// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer
// Passive JP1.4 reverse engineering tool
//
// Important finding:
// JP1.4 connection appears to affect remote startup state.
// Do NOT assume startup capture while connected.
// Tool must remain passive and high impedance.
//
// Confirmed:
// Pin 1 = VCC (do not monitor)
// Pin 2 = GND (common ground)
// Pins 3-6 = unknown signals

#include <Arduino.h>

#define JP14_COUNT 4
#define BUFFER_SIZE 512
#define STARTUP_CAPTURE_MS 3000

const uint8_t JP14_PINS[JP14_COUNT] = {4,5,6,7};
const char* JP14_NAMES[JP14_COUNT] = {
  "JP1.4 Pin 3",
  "JP1.4 Pin 4",
  "JP1.4 Pin 5",
  "JP1.4 Pin 6"
};

struct Capture {
  uint8_t pin;
  uint8_t state;
  uint32_t time;
};

Capture buffer[BUFFER_SIZE];
uint16_t bufferIndex = 0;

int lastState[JP14_COUNT];
uint32_t edgeCount[JP14_COUNT];
uint32_t lastEdgeTime[JP14_COUNT];

void recordEvent(uint8_t pin, uint8_t state) {
  buffer[bufferIndex].pin = pin;
  buffer[bufferIndex].state = state;
  buffer[bufferIndex].time = micros();
  bufferIndex++;
  if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;
}

void clearCapture() {
  memset(buffer,0,sizeof(buffer));
  bufferIndex = 0;
  Serial.println("Capture cleared");
}

void dumpCapture() {
  Serial.println("--- JP1.4 Capture ---");
  for(int i=0;i<BUFFER_SIZE;i++) {
    if(buffer[i].time) {
      Serial.print("Pin ");
      Serial.print(buffer[i].pin + 3);
      Serial.print(" ");
      Serial.print(buffer[i].state ? "HIGH" : "LOW");
      Serial.print(" @ ");
      Serial.println(buffer[i].time);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Onkyo RC-764M JP1.4 Passive Sniffer");
  Serial.println("No pullups. No outputs. Listen only.");
  Serial.println("Commands: d=dump c=clear");

  for(int i=0;i<JP14_COUNT;i++) {
    pinMode(JP14_PINS[i], INPUT);
    lastState[i]=digitalRead(JP14_PINS[i]);
    lastEdgeTime[i]=micros();
    edgeCount[i]=0;
  }
}

void loop() {
  if(Serial.available()) {
    char c=Serial.read();
    if(c=='d') dumpCapture();
    if(c=='c') clearCapture();
  }

  for(int i=0;i<JP14_COUNT;i++) {
    int state=digitalRead(JP14_PINS[i]);

    if(state != lastState[i]) {
      uint32_t now=micros();
      edgeCount[i]++;
      lastEdgeTime[i]=now;
      recordEvent(i,state);

      Serial.print(JP14_NAMES[i]);
      Serial.print(" -> ");
      Serial.print(state ? "HIGH" : "LOW");
      Serial.print(" count=");
      Serial.println(edgeCount[i]);

      lastState[i]=state;
    }
  }
}
