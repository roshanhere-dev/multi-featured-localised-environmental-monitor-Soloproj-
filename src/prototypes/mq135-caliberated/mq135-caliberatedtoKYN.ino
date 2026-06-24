// ==========================================
// ESP32 MQ135 Gas Sensor & AQI Monitor
// ==========================================

// Pin Definitions
const int greenLED = 4;     // Green LED for safe air indication
const int gassensor = 34;   // MQ135 Analog Output (via 3.3V voltage divider)

// ==========================================
// --- CALIBRATION SETTINGS ---
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
  pinMode(greenLED, OUTPUT);
  
  // Blink the LED 3 times at boot

    digitalWrite(greenLED, HIGH);
    
 
  
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
    digitalWrite(greenLED, HIGH);
  } 
  else if (aqi > 50 && aqi <= 100) {
    Serial.println(" | Moderate (Acceptable Air) 😐");
    digitalWrite(greenLED, HIGH); 
  } 
  else if (aqi > 100 && aqi <= 200) {
    Serial.println(" | Poor (Stale / Unhealthy) ⚠️");
    digitalWrite(greenLED, LOW); // Turn off safety light
  } 
  else if (aqi > 200 && aqi <= 300) {
    Serial.println(" | Warning (Chemicals / Vapors Detected) 🧪");
    for(int i = 0; i < 3; i++) {
    digitalWrite(greenLED, HIGH);
    delay(200);
    digitalWrite(greenLED, LOW);
    delay(200);
  }
  } 
  else {
    Serial.println(" | DANGER! (Heavy Smoke / Gas Leak) 🚨");
    // Danger state: Fast flash the LED to grab attention
    for(int i = 0; i < 4; i++) {
      digitalWrite(greenLED, HIGH);
      delay(150);
      digitalWrite(greenLED, LOW);
      delay(150);
    }
  }

  // 2-second delay
  delay(2000);
}
