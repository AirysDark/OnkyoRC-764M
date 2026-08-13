#include <Arduino.h>

// Onkyo RC-764M ESP32-S3 upgrade
// Phase 1: hardware bring-up

void setup() {
  Serial.begin(115200);
  Serial.println("OnkyoRC-764M ESP32-S3 upgrade starting");
}

void loop() {
  // Future:
  // - matrix scanner
  // - BLE remote
  // - WiFi API
  // - battery monitor
  delay(1000);
}
