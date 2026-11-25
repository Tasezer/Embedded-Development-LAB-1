/*
 * Name: Ahmet Tarik Sezer
 * Student number: 25159445
 */

#include <Arduino.h>

#define LED_PIN        23   // LED (with 220 ohm resistor) is connected to GPIO23
#define BUTTON_PIN     22   // Button is connected between GPIO22 and 3.3V
#define DEBOUNCE_TIME  50   // Time in ms to wait until the button stops bouncing

bool ledState = HIGH;          // Current state of the LED (starts ON)
bool lastButtonState = LOW;    // Button state from the previous loop

void setup() {
    Serial.begin(115200);                  // Start serial communication for debugging

    pinMode(LED_PIN, OUTPUT);              // LED pin is an output
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);   // Button pin is an input, pulled down to 0V when not pressed

    digitalWrite(LED_PIN, ledState);       // Turn the LED on at startup
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN);   // Read the button: HIGH = pressed, LOW = not pressed

    if (buttonState != lastButtonState) {         // Button state changed (pressed or released)
        if (buttonState == HIGH) {                 // Only react when the button is pressed, not released
            ledState = !ledState;                  // Toggle the LED state
            digitalWrite(LED_PIN, ledState);       // Write the new state to the LED

            if (ledState == HIGH) {
                Serial.println("LED on");
            } else {
                Serial.println("LED off");
            }
        }
        delay(DEBOUNCE_TIME);                      // Wait until the bouncing is over
    }

    lastButtonState = buttonState;                 // Remember the state for the next loop
}