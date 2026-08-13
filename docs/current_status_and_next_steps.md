# OnkyoRC-764M ESP32-S3 Upgrade

## Current status

The original blob MCU is being kept intact for now. The goal is to upgrade the remote, not destroy the existing functionality.

Current design goals:

- ESP32-S3 becomes the smart controller.
- Keep original IR hardware where useful.
- Investigate JP1.4 header for access to original remote data.
- Recover universal remote code database if possible.
- Add Bluetooth smart TV control.
- Add WiFi control, macros, IR learning, and expanded device support.

## Current observations

JP1.4 appears connected to the original MCU area.

Confirmed from visual tracing:

- JP1.4 row 1 pin 3 appears to route to U1.
- JP1.4 row 2 pin 1 appears to route to U1.
- Other JP1.4 pins are still unknown.

No confirmed intentional trace cuts have been found. Earlier suspected cuts were likely caused by viewing angle and PCB markings.

## Next physical steps

1. Do not remove the blob MCU.
2. Remove battery power before continuity testing.
3. Map all six JP1.4 pins:
   - GND
   - VCC
   - data
   - clock
   - reset/test
   - unknown
4. Photograph JP1.4 and U1 area straight-on.
5. Use continuity mode to confirm each JP1.4 connection.
6. Only after mapping, connect ESP32-S3 through protection resistors.

## Future architecture

```
ESP32-S3
 |
 +-- Bluetooth (smart TVs)
 +-- WiFi
 +-- IR learning
 +-- IR transmitter
 +-- JP1.4 interface
 |
Original MCU
 |
Universal remote database
```

The first objective is information recovery, not replacement.