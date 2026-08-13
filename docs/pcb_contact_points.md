# PCB Contact Points / Test Pads Investigation

## Observation

Additional exposed copper points were noticed on the remote PCB:

- A small square brown PCB area with a circular exposed contact near the Direct Tuning area.
- A similar exposed contact near LED1 at the top of the PCB.

These do not appear to be normal button contacts because they are isolated exposed pads rather than carbon key contacts.

## Possible Functions

Possible uses:

1. Factory test points
   - Used during manufacturing to check signals, voltage rails, or MCU operation.

2. Programming/debug pads
   - Could provide access to MCU test communication during production.

3. Calibration points
   - Direct Tuning or LED area contacts may be used during factory alignment.

## Action Plan

- Photograph both pads with better lighting.
- Trace each pad with continuity mode to determine destination.
- Check if connected to U1 pins, power, ground, or passive components.
- Add discovered points to JP1.4 reverse engineering map.

Do not assume these are programming interfaces until continuity and signal testing confirms it.
