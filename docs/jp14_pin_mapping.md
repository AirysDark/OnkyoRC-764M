# JP1.4 Pin Mapping

## Verified measurements

Current confirmed JP1.4 connections:

| Header position | Function | Status |
|---|---|---|
| Row 1 Pin 1 | VCC | Confirmed |
| Row 1 Pin 2 | GND | Confirmed |

## Notes

The remote is powered by a modified 3.7V Li-ion battery system.

Next measurements:
- Identify remaining JP1.4 pins
- Determine which are connected to U1 MCU programming/debug signals
- Verify voltage levels before connecting ESP32-S3 GPIO

The ESP32-S3 JP1.4 analyzer firmware should remain receive-only until the interface is identified.
