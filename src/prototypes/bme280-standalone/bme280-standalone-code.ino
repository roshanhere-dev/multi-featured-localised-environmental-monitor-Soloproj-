#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Create an instance of the sensor
Adafruit_BME280 bme; 

// SEALEVELPRESSURE_HPA defines the baseline for altitude calculation
// Update this based on your current local weather report for perfect accuracy
#define SEALEVELPRESSURE_HPA (1013.25)

void setup() {
  Serial.begin(115200);
  while(!Serial); // Wait for Serial Monitor to open
  
  Serial.println(F("--- BME280 Standalone Test ---"));

  // Initialize the sensor using default I2C pins (GPIO 21 and 22)
  // Note: Some cheap modules use I2C address 0x76 instead of the default 0x77
  if (!bme.begin(0x76)) {  
    Serial.println(F("Could not find a valid BME280 sensor, check wiring or try address 0x77!"));
    while (1); // Halt program if sensor isn't found
  }
  
  Serial.println(F("BME280 Sensor successfully initialized!\n"));
}

void loop() {
  // Read and print Temperature
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  // Read and print Humidity
  Serial.print("Humidity    = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  // Read and print Barometric Pressure
  Serial.print("Pressure    = ");
  Serial.print(bme.readPressure() / 100.0F); // Converts Pascals to hPa
  Serial.println(" hPa");

  // Calculate and print approximate Altitude
  Serial.print("Approx. Alt = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println("------------------------------------");
  delay(2000); // Wait 2 seconds before reading again
}
