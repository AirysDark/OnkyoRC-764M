# Next Physical Steps

## Step 1 - Document PCB

- Photograph PCB front and back at high resolution
- Identify JP1.4 six pin header traces
- Identify blob MCU connections
- Identify IR LED driver section
- Identify battery and charging points

## Step 2 - JP1.4 Investigation

Before connecting ESP32-S3:

1. Use multimeter continuity mode.
2. Find GND.
3. Find VCC.
4. Trace remaining pins to the MCU.
5. Determine data/clock/reset/test lines.

Do not inject voltage until pinout is confirmed.

## Step 3 - ESP32-S3 Test Hardware

Build a temporary connection:

- ESP32-S3 GPIO protection resistors
- Logic analyser points
- Serial logging

Purpose:

- Observe JP1.4 activity
- Identify protocol
- Attempt read-only communication

## Step 4 - Build Final Upgrade

ESP32-S3 features:

- IR database
- IR learning
- BLE remote
- WiFi remote
- Smart TV control
- Battery monitoring
- Charging dock
- Macro engine
