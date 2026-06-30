#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
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

// The ESP32 calculates a custom ratio based on your specific sensor
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
  Serial.println("==========================================");
}

void loop() {
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
    int aqi = gasValue * AQI_MULTIPLIER;

    Serial.println("=========================================");
    Serial.print("Raw Gas ADC: ");
    Serial.print(gasValue);
    Serial.print(" -> Calculated AQI: ");
    Serial.print(aqi);

    if (aqi <= 50) {
      Serial.println(" | Excellent (Fresh Air) 🍃");
    } 
    else if (aqi > 50 && aqi <= 100) {
      Serial.println(" | Moderate (Acceptable Air) 😐");
    } 
    else if (aqi > 100 && aqi <= 200) {
      Serial.println(" | Poor (Stale / Unhealthy) ⚠️");
    } 
    else if (aqi > 200 && aqi <= 300) {
      Serial.println(" | Warning (Chemicals / Vapors Detected) 🧪");
    } 
    else {
      Serial.println(" | DANGER! (Heavy Smoke / Gas Leak) 🚨");
    }

    // --- BME280 Climate Logic ---
    float bme_readTemperature = bme.readTemperature();
    float bme_readHumidity = bme.readHumidity();
    float bme_readPressure_hPa = bme.readPressure() / 100.0F;
    float bme_readAltitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

    Serial.print("Temperature = "); Serial.print(bme_readTemperature); Serial.println(" *C");
    Serial.print("Humidity    = "); Serial.print(bme_readHumidity);    Serial.println(" %");
    Serial.print("Pressure    = "); Serial.print(bme_readPressure_hPa); Serial.println(" hPa");
    Serial.print("Approx. Alt = "); Serial.print(bme_readAltitude);    Serial.println(" m");
    Serial.println("=========================================\n");
  
   // RAIN LOGIC PRINTING 

  

    // Read raw ADC value (0 to 4095)
    int rawRainValue = analogRead(rainSensorPin);

    Serial.print("Raw ADC Value: ");
    Serial.print(rawRainValue);

    // --- RAIN LEVEL CLASSIFICATION METRIC ---
    // Note: You can tweak these thresholds based on your specific sensor pad sensitivity
    if (rawRainValue >= 4000) {
      Serial.println(" -> [STATUS]: Clear Skies / Completely Dry ☀️");
    } 
    else if (rawRainValue < 4000 && rawRainValue >= 3200) {
      Serial.println(" -> [STATUS]: Mist / Very Light Drizzling 🌫️");
    } 
    else if (rawRainValue < 3200 && rawRainValue >= 2200) {
      Serial.println(" -> [STATUS]: Light Rain / Steady Drops 🌧️");
    } 
    else if (rawRainValue < 2200 && rawRainValue >= 1000) {
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
