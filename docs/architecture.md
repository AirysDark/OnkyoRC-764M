# OnkyoRC-764M ESP32-S3 Smart Remote Upgrade

## Goal
Upgrade the RC-764M into a smart universal remote while preserving the original IR hardware.

## Architecture

ESP32-S3 Tiny becomes the main controller.

Features:
- Button matrix scanning
- IR learning
- IR database storage
- Automatic device scan
- WiFi/BLE control
- Macros
- Battery monitoring
- Charging dock support

## Hybrid design

ESP32-S3 -> original button matrix interface -> IR engine -> IR LED

The original blob MCU will be preserved initially. A future phase will dump and document the blob behavior.

## IR system

Add:
- IR receiver module for learning
- ESP32-S3 RMT based IR transmit/receive
- Local command database

## Blob MCU dump plan

Before removal:
1. Photograph all traces.
2. Identify power, clock, matrix, and IR pins.
3. Capture button matrix behavior.
4. Capture IR output from every button.
5. Archive measurements.
