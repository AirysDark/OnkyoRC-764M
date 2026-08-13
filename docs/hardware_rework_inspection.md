# Hardware Rework Inspection Notes

## Current observation

The JP1.4 / U1 area shows signs that the board may have had previous repair or rework.

Observed:
- Discoloration around the component area near R15.
- Possible flux residue or cleaning marks.
- Solder joints do not appear factory-perfect.
- A capacitor near this area may have been replaced.

## Important

This is not yet confirmed damage. Possible causes:

1. Previous repair/replacement.
2. Factory rework.
3. Flux residue from manufacturing.
4. Corrosion or contamination.

## Inspection procedure

Before connecting ESP32-S3:

- Photograph both PCB sides.
- Check continuity around affected components.
- Check for shorts to ground.
- Verify JP1.4 pins.

## Current reverse engineering status

Confirmed:
- JP1.4 header exists.
- JP1.4 traces appear to connect toward U1 blob MCU.
- Row 1 pin 3 has been traced toward U1.
- Row 2 pin 1 has been traced toward U1.

Unknown:
- Exact JP1.4 protocol.
- MCU type under epoxy blob.
- Whether programming access is locked.

Next step:
- Continue JP1.4 continuity mapping.
- Use ESP32-S3 in listen-only mode first.
