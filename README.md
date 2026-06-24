# ESP32 Smart Environmental Dashboard 🌦️💨


An advanced, IoT-enabled environmental telemetry station built on the ESP32 microcontroller. This project integrates a suite of specialized hardware sensors—including the BME280 Climate Sensor, MQ135 Gas Sensor (with localized baseline calibration), and an LM393 Rain Sensor—to serve an interactive, live web dashboard.

The dashboard features real-time data visualization via dynamic, responsive charts, and actively fetches official municipal meteorological data from a cloud API to perform side-by-side, localized comparison analytics.

🚀 Key Features

Micro-Local vs. Macro-Metro Comparison API: The web client automatically fetches official real-time meteorological data for Kalyan from public APIs (such as OpenWeatherMap or WAQI). It displays this metropolitan baseline side-by-side with your physical breadboard telemetry.

Dynamic Real-Time Charts & Graphs: Diversified line charts, trend vectors, and dynamic radial gauges visualize localized telemetry trends natively inside the browser (updating asychronously via WebSockets or Server-Sent Events).

High-Accuracy BME280 Micro-Climate Profiling: Collects highly accurate temperature, relative humidity, and local barometric pressure over the digital $I^2C$ protocol.

Logarithmic AQI Estimation: Converts raw analog values from the MQ135 into a scaled Air Quality Index ($AQI$) based on localized city baselines, bypassing the non-linear curve limitations of raw metal-oxide resistance.

Interactive Rain Telemetry: Maps real-time soil/precipitation conductivity from the LM393 probe, scaling precipitation levels from dry to torrential downpours.

Dual-State Visual Feedback: Drives physical indicators, utilizing hardware Pulse Width Modulation ($PWM$) for dimming and high-frequency blink alarms during hazard events.

Safe Electrical Topology: Features an integrated series voltage divider to protect the ESP32's $3.3\text{ V}$ analog-to-digital converter ($ADC$) inputs from the gas sensor’s native $5\text{ V}$ signaling.

🔬 Sensor Science & Principles of Operation

The system merges three completely different physical and chemical sensing methodologies into a unified data structure.

1. The BME280 Climate Sensor

The BME280 is a digital sensor communicating over the $I^2C$ protocol. It uses three distinct micromachined sensing elements:

Relative Humidity: Utilizes a fast-response capacitive sensor. Moisture in the air permeates a specialized polymer dielectric layer, altering its capacitance proportionally to relative humidity:

$$C \propto \epsilon_r$$

Barometric Pressure: Employs a high-precision piezoresistive silicon pressure sensor. Mechanical deflection of a silicon diaphragm due to atmospheric pressure alters the electrical resistance of the integrated piezoresistors.

Temperature: Uses an internal diode-based semiconductor bandgap reference. The forward voltage drop ($V_{be}$) across a silicon junction changes linearly with temperature:

$$\Delta V_{be} \propto T$$

2. The MQ135 Air Quality Sensor

The MQ135 relies on a heated Tin Dioxide ($SnO_2$) semiconductor layer.

In Clean Air: Oxygen molecules trap free electrons on the $SnO_2$ crystal boundaries, forming an electrostatic barrier that keeps internal resistance extremely high.

In Polluted Air: Reducing gases—such as Ammonia ($NH_3$), Nitrogen Oxides ($NO_x$), Carbon Dioxide ($CO_2$), and volatile organic vapors—react with the adsorbed oxygen. This releases the trapped electrons back into the conduction band, causing a sharp drop in electrical resistance:

$$R_s \propto \frac{1}{\text{Gas Concentration}}$$

3. Calibration Anchor Formula

To normalize the MQ135's gas-sensing curve to match the municipal $AQI$, the ESP32 calculates a custom calibration multiplier:

$$\text{Multiplier} = \frac{\text{Local Municipal AQI Baseline (Kalyan = 97)}}{\text{Steady State Raw ADC Reading}}$$

This multiplier scales subsequent analog changes relative to your ambient conditions:

$$\text{Calculated AQI} = \text{Raw ADC Value} \times \text{Multiplier}$$

🛠️ Hardware Architecture & Wiring

The BME280 runs on digital $I^2C$ ($3.3\text{ V}$ safe), while the MQ135 requires a $5\text{ V}$ heater supply and an analog step-down interface.

System Schematic

  [ESP32 Development Board]                  [Breadboard Node]               [MQ135 Gas Sensor]
   
   VIN (5V USB Power) ------------------------------------------------------> VCC (5V Power)
   GND (System Ground) -----------------------------------------------------> GND (Ground)
  
                                            (Row A) <----------------------- AO (Analog Out)
                                               |
                                        [1kΩ Resistor (R1)]
                                               |
   GPIO 34 (ADC1) <------------------------- (Row B)
                                               |
                                        [1kΩ Resistor (R2)]
                                               |
                                            (Row C)
                                               |
                                        [1kΩ Resistor (R3)]
                                               |
   GND ------------------------------------- (Row C) <--- Connected to Ground Rail


Digital $I^2C$ Architecture

  [ESP32 Development Board]                  [Breadboard Node]               [BME280 Sensor]
   
   3V3 (3.3V Power) --------------------------------------------------------> VCC (3.3V Power)
   GND (System Ground) -----------------------------------------------------> GND (Ground)
   GPIO 21 (I2C SDA) -------------------------------------------------------> SDA (Data)
   GPIO 22 (I2C SCL) -------------------------------------------------------> SCL (Clock)


📊 Live Web Interface Dashboard

The ESP32 acts as a local web server, delivering a light-weight asynchronous web page to any local browser client.

Data Flow Topology

   +------------------+     I2C (Digital)     +-------------------+
   |  BME280 Sensor   | --------------------> |                   |
   +------------------+                       |                   |
   +------------------+    Analog (0-3.3V)    |       ESP32       |
   |  MQ135 (Divided) | --------------------> |    Micro-Server   |
   +------------------+                       |                   |
   +------------------+    Analog (0-3.3V)    |                   |
   |  Rain Sensor AO  | --------------------> |                   |
   +------------------+                       +-------------------+
                                                        |
                                                 Wi-Fi / WebSockets
                                                        v
   +------------------+                       +-------------------+
   |   Public Cloud   |                       |    Web Browser    |
   |   Weather API    | <-------------------- |   Client Portal   |
   | (Metro Baseline) |    JSON Fetch (GET)   |  (Live Charts)    |
   +------------------+                       +-------------------+


Frontend Technology: Built with CSS Grid, SVG gauges, and a lightweight plotting library (such as Chart.js or HTML5 Canvas).

Asynchronous Telemetry: State updates bypass standard page-reloads. Instead, telemetry variables are parsed as structured JSON payloads over a live communication layer, avoiding sensor lag.

Client-Side Comparison API: The dashboard issues an asynchronous fetch() request directly from the client's browser to retrieve regional meteorology. This avoids adding a network-handling load to the ESP32.

📁 Repository Structure

├── src/
│   ├── main_system/            # Unified production code (Webserver, BME280, MQ135, Rain)
│   │   └── main_system.ino
│   └── prototypes/             # Isolated unit tests
│       ├── led_pwm_demo/       # Hardware PWM testing
│       ├── bme280_i2c_test/    # I2C scanning & readings
│       ├── rain_sensor_analog/ # Raw moisture mapping
│       └── mq135_calibrated/   # Localized multiplier sketch
├── docs/                       # Sensor guides, wiring schemas, & datasheets
└── README.md                   # Project documentation


💻 Installation & Getting Started

Clone this repository:

git clone https://github.com/yourusername/esp32-environmental-dashboard.git


Open the sketch: Load src/main_system/main_system.ino in your Arduino IDE.

Install Board Package & Libraries:

Install the ESP32 board manager package.

Install Adafruit BME280 Library (via Arduino Library Manager).

Configure Access Point: Update the network credentials in the source code with your local Wi-Fi router's SSID and Password.

Calibrate:

Power the system and let the MQ135 pre-heat for at least 5 minutes.

Read the average raw value in your Serial Monitor.

Update MY_RAW_READING at the top of the sketch to anchor the custom municipal-scaling algorithm.

