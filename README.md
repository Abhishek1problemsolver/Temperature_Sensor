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

## Project image
![temp_sensor](https://github.com/user-attachments/assets/ee651f7a-f045-412d-a78e-49633b09a566)



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
```

##output
![219320108-2a79135a-f24a-4502-8df4-5ca1948e0df4](https://github.com/user-attachments/assets/858bdfa4-5cdc-425f-9602-edfbf8eb6c82)

## Usage

- **Serial Monitor**: Open the Serial Monitor from the Arduino IDE (Tools > Serial Monitor) to view the temperature readings.
- **LCD Display**: If an LCD is connected, the temperature will be displayed in real-time.

## Troubleshooting

- Ensure all connections are secure and correct according to the wiring diagram.
- Make sure the correct libraries are installed.
- If the temperature reading fails, check the sensor's connection and try again.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request or report issues.

