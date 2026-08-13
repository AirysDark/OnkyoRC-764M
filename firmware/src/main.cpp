#include <Arduino.h>

// Onkyo RC-764M ESP32-S3 Smart Remote
// Phase 1: hardware bring-up
//
// Planned:
// - matrix scanner
// - IR learning
// - IR transmitter
// - BLE remote
// - WiFi API
// - battery monitor
// - macro engine

#define IR_TX_PIN 4
#define IR_RX_PIN 5

void setup() {
  Serial.begin(115200);
  Serial.println("OnkyoRC-764M ESP32-S3 upgrade starting");
  Serial.println("Smart universal remote mode");
}

void loop() {
  // Hardware mapping will be added after PCB continuity testing.
  // Blob MCU dump and matrix capture are next steps.
  delay(1000);
}
