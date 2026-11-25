# Embedded Development – Lab 1

**Name:** Ahmet Tarik Sezer
**Student number:** 25159445

## Description
ESP32 project (PlatformIO, Arduino framework) for Lab 1a – GPIO Input / Output.
Each press of the push button toggles an LED on or off. Button bouncing is handled with a short delay (debouncing).

## Hardware
| Part | ESP32 pin | Notes |
| --- | --- | --- |
| LED (+ 220 Ω resistor) | GPIO 23 | Output, resistor in series to GND |
| Push button | GPIO 22 | Input with internal pull-down, other side to 3.3 V |

## How to run
1. Open the project in VS Code with PlatformIO.
2. Connect the ESP32 via USB.
3. Upload: `pio run -t upload`
4. Open the serial monitor (115200 baud): `pio device monitor -b 115200`
5. Press the button: the LED toggles and "LED on" / "LED off" is printed.