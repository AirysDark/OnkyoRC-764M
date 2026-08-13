# JP1.4 Interface Investigation

## Discovery

The six-pin header marked JP1.4 is likely the factory programming/debug interface for the UEI universal remote controller, not a normal communication bus for the Onkyo receiver.

Typical JP1.4 signals:

1. VCC (~3.3V)
2. RESET / control line (varies by processor)
3. GND
4. SDAT data
5. TEST / programming mode
6. SCLK clock

The ESP32-S3 can potentially connect here for reverse engineering, but it should not be connected permanently until the signals are verified.

## New plan

Use JP1.4 for investigation:

- Read processor communication
- Attempt firmware/data extraction
- Identify flash memory access
- Determine if original universal remote database can be backed up

Do not assume it is a live API. It is most likely a programming/debug interface.

## ESP32-S3 connection goals

Future adapter:

ESP32-S3
|
+-- JP1.4 VCC sense
+-- JP1.4 GND
+-- SDAT capture
+-- SCLK capture
+-- TEST control (only when safe)
+-- RESET control

## Alternative architecture

If the original firmware can be dumped:

- Preserve original Onkyo database
- Extract IR tables
- Build expanded ESP32-S3 firmware
- Add learning mode and unlimited device database

If extraction is impossible:

- Capture IR output
- Scan button matrix
- Replace firmware functionality with ESP32-S3

## Required hardware tests

1. Continuity trace JP1.4 pins to blob MCU.
2. Identify processor family.
3. Capture signals with logic analyzer.
4. Attempt read-only communication first.
