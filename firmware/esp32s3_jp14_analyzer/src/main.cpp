// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer
// Purpose: passive monitoring of JP1.4 programming header
// Start in INPUT mode only. Do not drive remote lines until protocol is known.

#include <Arduino.h>

// Change these to match your ESP32-S3 Big Board wiring.
const int JP14_PINS[] = {4, 5, 6, 7, 8, 9};
const int JP14_COUNT = sizeof(JP14_PINS) / sizeof(JP14_PINS[0]);

int lastState[JP14_COUNT];
unsigned long lastReport = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Onkyo RC-764M JP1.4 Analyzer");
  Serial.println("Passive mode - GPIO inputs only");

  for (int i = 0; i < JP14_COUNT; i++) {
    pinMode(JP14_PINS[i], INPUT);
    lastState[i] = digitalRead(JP14_PINS[i]);
  }
}

void loop() {
  for (int i = 0; i < JP14_COUNT; i++) {
    int state = digitalRead(JP14_PINS[i]);

    if (state != lastState[i]) {
      Serial.print("JP1.4 pin ");
      Serial.print(i + 1);
      Serial.print(" changed: ");
      Serial.println(state);
      lastState[i] = state;
    }
  }

  if (millis() - lastReport > 5000) {
    Serial.println("Monitoring...");
    lastReport = millis();
  }
}
