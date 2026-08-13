# JP1.4 Code Extraction Plan

## Goal

The ESP32-S3 is not intended to use the original remote MCU as RAM. The goal is to investigate whether the JP1.4 programming interface can be used to retrieve the built-in universal remote information stored in the original controller.

## Objective

Extract useful data from the original remote:

- Universal remote device database
- IR command tables
- Configuration data
- Possible firmware information

## Proposed Workflow

1. Identify the processor used under the epoxy blob.
2. Map JP1.4 pins:
   - GND
   - VCC
   - Clock
   - Data
   - Reset/Test lines
3. Connect ESP32-S3 as a read/debug interface.
4. Attempt read-only communication first.
5. Capture and analyse returned data.
6. Convert extracted IR codes into ESP32-S3 compatible format.

## Final Upgrade Goal

The ESP32-S3 becomes the main remote controller:

- Larger code database
- IR learning
- Auto device scan
- Custom macros
- WiFi/Bluetooth control
- Rechargeable battery system

The original controller is used as a source of existing Onkyo/universal remote knowledge where possible.
