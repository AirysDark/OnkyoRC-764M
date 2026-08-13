// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer
// Passive JP1.4 reverse engineering tool
//
// Confirmed:
// Pin 1 = VCC (do not monitor)
// Pin 2 = GND (common ground)
// Pins 3-6 = unknown signals
//
// Mode: LISTEN ONLY
// No GPIO driving.

#include <Arduino.h>

#define JP14_COUNT 4
#define BUFFER_SIZE 128

const uint8_t JP14_PINS[JP14_COUNT] = {4,5,6,7};
const char* JP14_NAMES[JP14_COUNT] = {
  "JP1.4 Pin 3",
  "JP1.4 Pin 4",
  "JP1.4 Pin 5",
  "JP1.4 Pin 6"
};

int lastState[JP14_COUNT];
uint32_t edgeCount[JP14_COUNT];
uint32_t lastEdgeTime[JP14_COUNT];

struct Capture {
  uint8_t pin;
  uint8_t state;
  uint32_t time;
};

Capture buffer[BUFFER_SIZE];
uint16_t bufferIndex = 0;

unsigned long lastReport = 0;

void recordEvent(uint8_t pin, uint8_t state) {
  buffer[bufferIndex].pin = pin;
  buffer[bufferIndex].state = state;
  buffer[bufferIndex].time = micros();
  bufferIndex++;
  if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Onkyo RC-764M JP1.4 ESP32-S3 Analyzer");
  Serial.println("Passive capture mode");
  Serial.println("Monitoring JP1.4 pins 3-6 only");

  for (int i=0;i<JP14_COUNT;i++) {
    pinMode(JP14_PINS[i], INPUT);
    lastState[i] = digitalRead(JP14_PINS[i]);
    edgeCount[i] = 0;
    lastEdgeTime[i] = micros();
  }
}

void loop() {
  for (int i=0;i<JP14_COUNT;i++) {
    int state = digitalRead(JP14_PINS[i]);

    if (state != lastState[i]) {
      uint32_t now = micros();
      uint32_t gap = now - lastEdgeTime[i];

      edgeCount[i]++;
      lastEdgeTime[i] = now;
      recordEvent(i,state);

      Serial.print(JP14_NAMES[i]);
      Serial.print(" ");
      Serial.print(state ? "HIGH" : "LOW");
      Serial.print(" gap=");
      Serial.print(gap);
      Serial.print("us count=");
      Serial.println(edgeCount[i]);

      lastState[i] = state;
    }
  }

  if (millis()-lastReport > 5000) {
    Serial.println("--- JP1.4 status ---");
    for (int i=0;i<JP14_COUNT;i++) {
      Serial.print(JP14_NAMES[i]);
      Serial.print(" edges: ");
      Serial.println(edgeCount[i]);
    }
    lastReport = millis();
  }
}
