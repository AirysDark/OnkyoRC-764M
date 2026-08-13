// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer
// Passive reverse engineering tool
//
// Confirmed JP1.4:
// Pin 1 = VCC (do not monitor)
// Pin 2 = GND (common ground)
// Pins 3-6 = unknown signals
//
// Features:
// - Passive monitoring only
// - Edge detection
// - Event timing
// - Pulse width capture
// - Signal activity counter
// - No GPIO driving

#include <Arduino.h>

// ESP32-S3 Big Board GPIO mapping
// JP1.4 pins 3-6 only
const int JP14_PINS[] = {4, 5, 6, 7};
const char* JP14_NAMES[] = {
  "JP1.4 Pin 3",
  "JP1.4 Pin 4",
  "JP1.4 Pin 5",
  "JP1.4 Pin 6"
};

const int JP14_COUNT = 4;

int lastState[JP14_COUNT];
unsigned long lastChange[JP14_COUNT];
unsigned long pulseStart[JP14_COUNT];
unsigned long eventCount[JP14_COUNT];

unsigned long lastReport = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("============================");
  Serial.println("Onkyo RC-764M JP1.4 Analyzer");
  Serial.println("ESP32-S3 Passive Mode");
  Serial.println("============================");
  Serial.println("Pin 1 = VCC");
  Serial.println("Pin 2 = GND");
  Serial.println("Monitoring Pins 3-6");

  for (int i = 0; i < JP14_COUNT; i++) {
    pinMode(JP14_PINS[i], INPUT);
    lastState[i] = digitalRead(JP14_PINS[i]);
    lastChange[i] = micros();
    pulseStart[i] = 0;
    eventCount[i] = 0;
  }
}

void loop() {
  unsigned long now = micros();

  for (int i = 0; i < JP14_COUNT; i++) {
    int state = digitalRead(JP14_PINS[i]);

    if (state != lastState[i]) {
      unsigned long duration = now - lastChange[i];
      eventCount[i]++;

      Serial.print(JP14_NAMES[i]);
      Serial.print(" -> ");
      Serial.print(state ? "HIGH" : "LOW");
      Serial.print(" width=");
      Serial.print(duration);
      Serial.print("us events=");
      Serial.println(eventCount[i]);

      lastState[i] = state;
      lastChange[i] = now;
    }
  }

  if (millis() - lastReport > 5000) {
    Serial.println("--- JP1.4 monitoring active ---");
    for (int i = 0; i < JP14_COUNT; i++) {
      Serial.print(JP14_NAMES[i]);
      Serial.print(" events: ");
      Serial.println(eventCount[i]);
    }
    lastReport = millis();
  }
}
