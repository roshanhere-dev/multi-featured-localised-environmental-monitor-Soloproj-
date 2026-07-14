#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <WiFi.h>
#include <WebServer.h>
#include "WebPages.h"

// ==========================================
// --- WI-FI CREDENTIALS ---
// ==========================================
const char* ssid = "";      // enter ssid here !! 
const char* password = "";  // enter pw here !! 

WebServer server(80);

//-------------------- RAIN SENSOR -----------------
const int rainSensorPin = 35;
const int orangeLEDR = 27;
const int greenLEDR = 33;


// ------------- BME280 PINS ----------------------
const int orangeLEDB = 25;    // Orange LED for working indication
const int greenLEDB = 26;     // Green LED for comm indication   

// --------------- MQ135 PINS ------------------
const int orangeLEDM = 13;    // Orange LED for working indication
const int greenLEDM = 14;     // Green LED for comm indication
const int gassensor = 34;     // MQ135 Analog Output (via 3.3V voltage divider)

// ==========================================
// --- CALIBRATION SETTINGS For MQ135 ---
// ==========================================
const float KALYAN_CURRENT_AQI = 97.0;  // Real-world AQI baseline
const float MY_RAW_READING = 600.0;     // <-- Change this based on your raw Serial outputs!
const float AQI_MULTIPLIER = KALYAN_CURRENT_AQI / MY_RAW_READING;

// Create an instance of the BME280 sensor
Adafruit_BME280 bme; 

#define SEALEVELPRESSURE_HPA (1013.25)

// --- TIMING CONFIGURATION (NON-BLOCKING) ---
const unsigned long ORANGE_BLINK_INTERVAL = 1000; // 1 second heartbeat
const unsigned long SENSOR_READ_INTERVAL = 3000;  // Read data every 3 seconds
const unsigned long GREEN_LED_DURATION = 100;     // Green flashes for 100ms

unsigned long lastOrangeToggle = 0;
unsigned long lastSensorRead = 0;
unsigned long greenLedTriggerTime = 0;

bool orangeState = LOW;
bool greenLedsActive = false;

// Global Sensor Values to serve over API
float current_temperature = 0.0;
float current_humidity = 0.0;
float current_pressure = 0.0;
float current_altitude = 0.0;
int current_aqi = 0;
int current_rain = 0;

// ==========================================
// --- API ENDPOINT ROUTE HANDLERS ---
// ==========================================
void handleDataApi() {
  // Return JSON array: [Temperature, Humidity, Pressure, Altitude, AQI, Rain_ADC]
  char jsonString[256];
  snprintf(jsonString, sizeof(jsonString), "[%.2f, %.2f, %.2f, %.2f, %d, %d]", 
           current_temperature, current_humidity, current_pressure, current_altitude, current_aqi, current_rain);
  server.send(200, "application/json", jsonString);
}

void setup() {
  // RAIN SENSOR 
  pinMode(rainSensorPin, INPUT);
  pinMode(greenLEDR, OUTPUT);
  pinMode(orangeLEDR, OUTPUT);

  // BME280 LED Configurations
  pinMode(greenLEDB, OUTPUT);
  pinMode(orangeLEDB, OUTPUT);
  
  // MQ135 Configurations
  pinMode(gassensor, INPUT);
  pinMode(greenLEDM, OUTPUT);
  pinMode(orangeLEDM, OUTPUT);
  
  Serial.begin(115200);
  while(!Serial); // Wait for Serial Monitor to open
  
  Serial.println(F("\n----- MAIN BREADBOARD TESTING -----"));
  Serial.println("==========================================");
  Serial.println("Calibrated MQ135 Gas Sensor Starting!!");
  Serial.println("==========================================");
  Serial.print("Current Calibration Multiplier: ");
  Serial.println(AQI_MULTIPLIER, 4);
  Serial.println(F("\n=========================================="));
  Serial.println(F("    LM393 Rain Sensor Starting     "));
  Serial.println(F("=========================================="));

  // Initialize BME280
  if (!bme.begin(0x76)) {  
    Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
    // Fast lockup flash on BME Orange LED if hardware initialization fails
    while (1) {
      digitalWrite(orangeLEDB, HIGH);
      delay(100);
      digitalWrite(orangeLEDB, LOW);
      delay(100); 
    }
  }
  
  Serial.println("==========================================");
  Serial.println(F("BME280 Sensor successfully initialized!\n"));
  
  Serial.println("ROSHAN WELCOMES YOU TO THIS ENVIRONMENTAL MONITOR");
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWireless Connection Established Successfully.");
  Serial.print("Use IP Address : ");
  Serial.println(WiFi.localIP());

  // Web Server Routing Setup
  server.on("/", []() {
    server.send(200, "text/html", PAGE_HERO);
  });
  
  server.on("/about.html", []() {
    server.send(200, "text/html", PAGE_ABOUT);
  });

  server.on("/telemetry-dash-readings.html", []() {
    server.send(200, "text/html", PAGE_READINGS);
  });

  server.on("/telemetry-dash(graphs).html", []() {
    server.send(200, "text/html", PAGE_GRAPHS);
  });

  server.on("/api/data", handleDataApi);

  server.begin();
  Serial.println("HTTP Server started.");
  Serial.println("==========================================");
}

void loop() {
  server.handleClient(); // Handle Web requests
  
  unsigned long currentMillis = millis();

  // 1. HEARTBEAT: Continuously blink BOTH Orange LEDs every 1000ms completely independently
  if (currentMillis - lastOrangeToggle >= ORANGE_BLINK_INTERVAL) {
    lastOrangeToggle = currentMillis;
    orangeState = !orangeState; // Toggle high/low state
    
    digitalWrite(orangeLEDB, orangeState);
    digitalWrite(orangeLEDM, orangeState);
    digitalWrite(orangeLEDR, orangeState);
  }

  // 2. DATA ACQUISITION & PRINTING: Runs smoothly every 3 seconds
  if (currentMillis - lastSensorRead >= SENSOR_READ_INTERVAL) {
    lastSensorRead = currentMillis;

    // Fire both green communication LEDs instantly
    digitalWrite(greenLEDB, HIGH);
    digitalWrite(greenLEDM, HIGH);
    digitalWrite(greenLEDR, HIGH);
    greenLedTriggerTime = currentMillis;
    greenLedsActive = true;

    // --- MQ135 Gas Sensor Logic ---
    int gasValue = analogRead(gassensor);
    current_aqi = gasValue * AQI_MULTIPLIER;

    Serial.println("=========================================");
    Serial.print("Raw Gas ADC: ");
    Serial.print(gasValue);
    Serial.print(" -> Calculated AQI: ");
    Serial.print(current_aqi);

    if (current_aqi <= 50) {
      Serial.println(" | Excellent (Fresh Air) 🍃");
    } 
    else if (current_aqi > 50 && current_aqi <= 100) {
      Serial.println(" | Moderate (Acceptable Air) 😐");
    } 
    else if (current_aqi > 100 && current_aqi <= 200) {
      Serial.println(" | Poor (Stale / Unhealthy) ⚠️");
    } 
    else if (current_aqi > 200 && current_aqi <= 300) {
      Serial.println(" | Warning (Chemicals / Vapors Detected) 🧪");
    } 
    else {
      Serial.println(" | DANGER! (Heavy Smoke / Gas Leak) 🚨");
    }

    // --- BME280 Climate Logic ---
    current_temperature = bme.readTemperature();
    current_humidity = bme.readHumidity();
    current_pressure = bme.readPressure() / 100.0F;
    current_altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

    Serial.print("Temperature = "); Serial.print(current_temperature); Serial.println(" *C");
    Serial.print("Humidity    = "); Serial.print(current_humidity);    Serial.println(" %");
    Serial.print("Pressure    = "); Serial.print(current_pressure); Serial.println(" hPa");
    Serial.print("Approx. Alt = "); Serial.print(current_altitude);    Serial.println(" m");
    Serial.println("=========================================\n");
  
    // --- RAIN SENSOR LOGIC ---
    current_rain = analogRead(rainSensorPin);

    Serial.print("Raw ADC Value: ");
    Serial.print(current_rain);

    // Rain level classification
    if (current_rain >= 4000) {
      Serial.println(" -> [STATUS]: Clear Skies / Completely Dry ☀️");
    } 
    else if (current_rain < 4000 && current_rain >= 3200) {
      Serial.println(" -> [STATUS]: Mist / Very Light Drizzling 🌫️");
    } 
    else if (current_rain < 3200 && current_rain >= 2200) {
      Serial.println(" -> [STATUS]: Light Rain / Steady Drops 🌧️");
    } 
    else if (current_rain < 2200 && current_rain >= 1000) {
      Serial.println(" -> [STATUS]: Moderate Rain / Heavy Shower 🌧️🌧️");
    } 
    else {
      Serial.println(" -> [STATUS]: DANGER! Torrential Downpour / Flood Risk 🚨");
    }
    
    Serial.println("------------------------------------------------");
  }

  // 3. AUTOMATIC GREEN LED SHUTOFF: Turns green flags off after exactly 100ms
  if (greenLedsActive && (currentMillis - greenLedTriggerTime >= GREEN_LED_DURATION)) {
    digitalWrite(greenLEDB, LOW);
    digitalWrite(greenLEDM, LOW);
    digitalWrite(greenLEDR, LOW);
    greenLedsActive = false;
  }
}
