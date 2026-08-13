# Onkyo RC-764M ESP32-S3 Upgrade - Project Roadmap

## Engineering assessment

The best approach is a staged hybrid upgrade.

The original remote already contains valuable Onkyo universal remote knowledge inside the factory MCU. The ESP32-S3 should first learn how to access, preserve, and expand that capability before replacing anything.

## Phase 1 - Reverse engineering (do not remove blob)

Goals:
- Identify the main MCU under the epoxy blob.
- Document JP1.4 6-pin interface.
- Identify voltage, ground, clock, data and programming signals.
- Determine whether the original firmware or code database can be read.

Hardware:
- ESP32-S3 Tiny
- multimeter
- logic analyzer (recommended)
- safe JP1.4 breakout

## Phase 2 - Extract remote knowledge

Target information:
- universal remote device database
- manufacturer codes
- IR protocol data
- stored configuration

The ESP32-S3 should convert any recovered information into an open format:

/devices/
  onkyo.json
  tv.json
  custom.json

## Phase 3 - ESP32-S3 remote operating system

Features:
- IR transmit using ESP32 RMT
- IR learning mode
- automatic code scanning
- BLE phone remote
- WiFi web remote
- macros
- profiles
- battery monitoring
- charging dock support

## Phase 4 - Hardware integration

Keep:
- original IR LED circuit
- original enclosure
- buttons
- battery upgrade

Add:
- ESP32-S3 Tiny
- charging system
- optional display
- optional IR receiver

## Important design decision

The blob MCU is not treated as memory. It is treated as a source of proprietary remote intelligence that may be extracted or used as a compatibility layer.

If extraction fails, the fallback is:

1. Keep the original MCU operational.
2. ESP32-S3 controls the button matrix.
3. ESP32-S3 learns and stores new IR codes independently.

This gives a working upgraded remote without depending on the original firmware.
