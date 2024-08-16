# Arduino Temperature Sensor Project

## Overview

This project involves using an Arduino microcontroller to measure and display the ambient temperature using a DHT11 temperature sensor. The temperature data is displayed on both an LCD screen and the Arduino Serial Monitor.

## Features

- Real-time temperature measurement
- Display temperature on an LCD screen
- Serial communication for temperature data logging
- Error handling for sensor readings

## Components

- Arduino Uno (or any compatible board)
- DHT11 Temperature and Humidity Sensor (can be swapped with DHT22)
- LCD Display (16x2)
- Breadboard and jumper wires
- Resistors (if needed)

## Wiring Diagram

*(Include a diagram showing how to connect the components to the Arduino, or describe the connections in text form.)*

## Setup Instructions

1. **Connect the Components:**
   - Connect the DHT11 sensor to the Arduino as follows:
     - **VCC**: 5V
     - **GND**: Ground
     - **Data**: Pin 2
   - Connect the LCD display to the Arduino:
     - **RS**: Pin 7
     - **E**: Pin 8
     - **D4**: Pin 9
     - **D5**: Pin 10
     - **D6**: Pin 11
     - **D7**: Pin 12

2. **Install Arduino IDE:**
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

3. **Install Required Libraries:**
   - Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Search for and install the following libraries:
     - `DHT sensor library`
     - `LiquidCrystal`

4. **Upload the Code:**
   - Copy the code below into a new sketch in the Arduino IDE.
   - Select your board and port from `Tools` > `Board` and `Port`.
   - Click `Upload` to upload the code to your Arduino.

## Code Example

```cpp
// Include necessary libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// Define pin numbers
#define DHTPIN 2     // Pin where the DHT sensor is connected
#define DHTTYPE DHT11   // DHT 11 (you can change to DHT22 if needed)

DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD interface with the pins connected to RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize the LCD
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Temp: ");
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read temperature as Celsius
  float temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *C");

  // Print temperature on the LCD
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.print(" C");
}
