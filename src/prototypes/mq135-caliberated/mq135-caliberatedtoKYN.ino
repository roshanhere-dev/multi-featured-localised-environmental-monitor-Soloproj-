// ==========================================
// ESP32 MQ135 Gas Sensor & AQI Monitor
// ==========================================

// Pin Definitions
const int greenLEDM = 14;    // Green LED for safe air indication
const int orangeLEDM = 13;   // Orange LED for safe air indication
const int gassensor = 34;   // MQ135 Analog Output (via 3.3V voltage divider)

// ==========================================
// --- CALIBRATION SETTINGS For MQ135---
// ==========================================
// 1. Look up the current AQI in your city (e.g., Kalyan is ~97).
// 2. Look at your Serial Monitor and find your average "Raw Sensor Value".
const float KALYAN_CURRENT_AQI = 97.0;  // Real-world AQI from a weather app
const float MY_RAW_READING = 600.0;     // <--- CHANGE THIS TO YOUR ACTUAL RAW NUMBER!

// The ESP32 calculates a custom ratio based on your specific sensor
const float AQI_MULTIPLIER = KALYAN_CURRENT_AQI / MY_RAW_READING;

void setup() {
  Serial.begin(115200);
  delay(5000); 
  
  Serial.println("\n==========================================");
  Serial.println("Calibrated MQ135 Gas Sensor Starting!!");
  Serial.println("==========================================");
  Serial.print("Current Calibration Multiplier: ");
  Serial.println(AQI_MULTIPLIER, 4);

  pinMode(gassensor, INPUT);
  pinMode(greenLEDM, OUTPUT);
  pinMode(orangeLEDM, OUTPUT);
  
  // Blink the LED 3 times at boot as an indication of its working !! 
    int i;
    for(i=0;i<3;i++){
    digitalWrite(greenLED, HIGH);
    delay(500);
    digitalWrite(greenLED, LOW);
    delay(500);
    }
  
}

void loop() {
  // Read the raw analog voltage
  int gasValue = analogRead(gassensor);
  
  // Calculate real-time AQI based on your custom baseline anchor
  int aqi = gasValue * AQI_MULTIPLIER; 

  Serial.print("Raw: ");
  Serial.print(gasValue);
  Serial.print(" -> AQI: ");
  Serial.print(aqi);

  // --- Standardized AQI Tiers ---
  
  if (aqi <= 50) {
    Serial.println(" | Excellent (Fresh Air) 🍃");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, HIGH);
    delay(100);
  } 
  else if (aqi > 50 && aqi <= 100) {
    Serial.println(" | Moderate (Acceptable Air) 😐");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, HIGH);
    delay(100); 
  } 
  else if (aqi > 100 && aqi <= 200) {
    Serial.println(" | Poor (Stale / Unhealthy) ⚠️");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, HIGH);
    delay(100); 
  } 
  else if (aqi > 200 && aqi <= 300) {
    Serial.println(" | Warning (Chemicals / Vapors Detected) 🧪");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, HIGH);
    delay(100);
  }
  } 
  else {
    Serial.println(" | DANGER! (Heavy Smoke / Gas Leak) 🚨");
    // Danger state: Fast flash the LED to grab attention
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    }
  }

  // 2-second delay
  delay(2000);
}

//----------------------------------------- IGNORE NEECHE KA !! -----------------------------------------------//


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
// -------------BME280 ----------------------
const int orangeLEDB = 25;    // Orange LED for working indication
const int greenLEDB = 26;    // Green LED for comm indication   
// ---------------MQ135------------------
const int greenLEDM = 14;    // Green LED for comm indication
const int orangeLEDM = 13;   // Orange LED for working indication
const int gassensor = 34;   //  MQ135 Analog Output (via 3.3V voltage divider)

// ==========================================
// --- CALIBRATION SETTINGS For MQ135---
// ==========================================
// 1. Look up the current AQI in your city (e.g., Kalyan is ~97).
// 2. Look at your Serial Monitor and find your average "Raw Sensor Value".
const float KALYAN_CURRENT_AQI = 97.0;  // Real-world AQI from a weather app
const float MY_RAW_READING = 600.0;     // <--- CHANGE THIS TO YOUR ACTUAL RAW NUMBER!

// The ESP32 calculates a custom ratio based on your specific sensor
const float AQI_MULTIPLIER = KALYAN_CURRENT_AQI / MY_RAW_READING;


// Create an instance of the sensor    it is 0x76 only btw 
Adafruit_BME280 bme; 

// SEALEVELPRESSURE_HPA defines the baseline for altitude calculation
// Update this based on your current local weather report for perfect accuracy
#define SEALEVELPRESSURE_HPA (1013.25)

void setup() {

  // BME280
  pinMode(greenLEDB, OUTPUT);
  pinMode(orangeLEDB, OUTPUT);
  // MQ135 
  pinMode(gassensor, INPUT);
  pinMode(greenLEDM, OUTPUT);
  pinMode(orangeLEDM, OUTPUT);
  
  Serial.begin(115200);
  while(!Serial); // Wait for Serial Monitor to open
  
  Serial.println(F(" ----- MAIN BREADBOARD TESTING ----- "));
Serial.println("\n==========================================");
  Serial.println("Calibrated MQ135 Gas Sensor Starting!!");
  Serial.println("==========================================");
  Serial.print("Current Calibration Multiplier: ");
  Serial.println(AQI_MULTIPLIER, 4);


  // Initialize the sensor using default I2C pins (GPIO 21 and 22)
  // Note: Some cheap modules use I2C address 0x76 instead of the default 0x77
  if (!bme.begin(0x76)) {  
    Serial.println(F("Could not find a valid BME280 sensor, check wiring or try address 0x77!"));
    while (1){
      digitalWrite(orangeLEDB, HIGH);
      delay(100);
      digitalWrite(orangeLEDB, LOW);
      delay(100); 
  }; // Halt program AND BLINK ORANGE LED if sensor isn't found
  }
  Serial.println("==========================================");
  Serial.println(F("BME280 Sensor successfully initialized!\n"));
  Serial.println("==========================================");
  Serial.println("==========================================");
  Serial.println("==========================================");
}

void loop() {


  int gasValue = analogRead(gassensor);
  int aqi = gasValue * AQI_MULTIPLIER;

  Serial.print("Raw: ");
  Serial.print(gasValue);
  Serial.print(" -> AQI: ");
  Serial.print(aqi);

   if (aqi <= 50) {
    Serial.println(" | Excellent (Fresh Air) 🍃");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, LOW);
    delay(100);
  } 
  else if (aqi > 50 && aqi <= 100) {
    Serial.println(" | Moderate (Acceptable Air) 😐");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, LOW);
    delay(100); 
  } 
  else if (aqi > 100 && aqi <= 200) {
    Serial.println(" | Poor (Stale / Unhealthy) ⚠️");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, LOW);
    delay(100); 
  } 
  else if (aqi > 200 && aqi <= 300) {
    Serial.println(" | Warning (Chemicals / Vapors Detected) 🧪");
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, LOW);
    delay(100);
  }
   
  else {
    Serial.println(" | DANGER! (Heavy Smoke / Gas Leak) 🚨");
    // Danger state: Fast flash the LED to grab attention
    digitalWrite(greenLEDM, HIGH);
    delay(100);
    digitalWrite(greenLEDM, LOW);
    delay(100);
    }
  

  // Read and print Temperature
  Serial.print("Temperature = ");
  float bme_readTemperature = bme.readTemperature();
  Serial.print(bme_readTemperature);
  Serial.println(" *C");

  // Read and print Humidity
  Serial.print("Humidity    = ");
  float bme_readHumidity = bme.readHumidity();
  Serial.print(bme_readHumidity);
  Serial.println(" %");

  // Read and print Barometric Pressure
  Serial.print("Pressure    = ");
  float bme_readPressure_hPa = bme.readPressure() / 100.0F;
  Serial.print(bme_readPressure_hPa); // Converts Pascals to hPa
  Serial.println(" hPa");

  // Calculate and print approximate Altitude
  Serial.print("Approx. Alt = ");
  float bme_readAltitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print(bme_readAltitude);
  Serial.println(" m");

  Serial.println("------------------------------------");
  delay(2000);
  digitalWrite(greenLEDB, HIGH);
  delay(100);
  digitalWrite(greenLEDB, LOW);
   // Wait 2 seconds before reading again
}



//------------------WORKING PROTOTYPE OF BREADBOARD MQ135 AND BME280 ------------ 


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

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
  }

  // 2. DATA ACQUISITION & PRINTING: Runs smoothly every 3 seconds
  if (currentMillis - lastSensorRead >= SENSOR_READ_INTERVAL) {
    lastSensorRead = currentMillis;

    // Fire both green communication LEDs instantly
    digitalWrite(greenLEDB, HIGH);
    digitalWrite(greenLEDM, HIGH);
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
  }

  // 3. AUTOMATIC GREEN LED SHUTOFF: Turns green flags off after exactly 100ms
  if (greenLedsActive && (currentMillis - greenLedTriggerTime >= GREEN_LED_DURATION)) {
    digitalWrite(greenLEDB, LOW);
    digitalWrite(greenLEDM, LOW);
    greenLedsActive = false;
  }
}

----------------------------

  MQ135 Gas Sensor



VCC ---- VIN (5V)



GND ----- GND



AO (Analog)---- GPIO 34 (via Divider)



bme 280:



v cc ---- 3v3

gnd --- gnd

sda --- g21

scl g22





lm393 comparator



vcc --- 3v3 line

gnd - gnd

ao ( analog ) --- g4



LEDs



bme 280

orange - g25

green -- g 26





lm393

orange - g27

green -- g 33



mq135

orange - g13
green -- g14

