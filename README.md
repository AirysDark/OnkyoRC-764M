# OnkyoRC-764M ESP32-S3 Smart Remote Upgrade

## Project Goal
Upgrade the Onkyo RC-764M remote with an ESP32-S3 Tiny while keeping the original Onkyo IR controller.

The design keeps:
- Original remote MCU (blob)
- Original IR transistor driver
- Original IR LED

The ESP32-S3 adds:
- WiFi/Bluetooth remote control
- Button matrix monitoring
- Macros
- Battery monitoring
- Charging dock support

## Architecture

ESP32-S3 -> simulated button presses -> original MCU -> IR driver -> Onkyo receiver

## Hardware Plan

ESP32-S3:
- 3.3V regulated supply
- Li-ion battery monitor
- USB-C charging dock

Future:
- OLED/TFT status display
- Home Assistant MQTT control
- Web remote

## Current Phase

Phase 1:
- PCB reverse engineering
- Identify button matrix lines
- Add ESP32-S3 safely without removing original controller
