# JP1.4 ESP32-S3 Expansion Plan

## Goal
Investigate the JP1.4 connector as a possible communication/programming interface to the original remote MCU.

The ESP32-S3 may be able to use this interface to:

- identify the MCU
- monitor programming traffic
- read available configuration data
- backup remote firmware/settings if supported
- extract IR database information

## Important
JP1.4 is expected to be a programming/debug interface, not necessarily a normal runtime communication bus.

Do not connect power until JP1.4 pinout is verified.

## Future Architecture

```
ESP32-S3
   |
   | JP1.4 interface
   |
Original remote MCU
   |
IR database / firmware
```

Possible final design:

```
ESP32-S3
 |
 +-- JP1.4 analysis
 +-- IR learning
 +-- own IR database
 +-- BLE/WiFi remote
 +-- battery management
```

## Investigation Steps

1. Identify JP1.4 pins using continuity testing.
2. Determine VCC/GND.
3. Capture clock/data signals.
4. Determine if the interface is readable.
5. Build ESP32-S3 analyzer firmware.

## Long Term

If the original MCU data can be extracted, the ESP32-S3 can become the main controller while preserving the original remote capabilities.