# RC-764M Blob MCU Dump

## Purpose
Reverse engineer the original remote controller IC before replacement.

## Planned capture

- VCC/GND pins
- Matrix row/column pins
- IR output pin
- Oscillator components
- Sleep/wake behavior

## Tools

- Multimeter continuity mode
- Logic analyzer
- Oscilloscope if available
- IR receiver capture

## Procedure

1. Keep original battery power.
2. Map every MCU pad to PCB trace.
3. Press every button and log matrix changes.
4. Capture IR waveform.
5. Build replacement firmware.

## Goal

ESP32-S3 can eventually replace the blob completely while keeping the original remote casing and buttons.
