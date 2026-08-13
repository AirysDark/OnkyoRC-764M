# ESP32-S3 Wiring Plan

## Power

Li-ion 3.7V battery
-> protection/charger circuit
-> 3.3V regulator
-> ESP32-S3 3V3

Common ground:
Battery GND
ESP32-S3 GND
Remote PCB GND

## Button Matrix Interface

Do NOT remove the original blob MCU.

ESP32-S3 GPIOs connect through high-value resistors to selected matrix lines.

Initial testing:
- Find row lines
- Find column lines
- Measure idle voltage
- Confirm button press resistance

## IR Section

Leave original circuit untouched:

Original MCU
 -> Q1 transistor
 -> IR LED
 -> Onkyo receiver

## Future Additions

- USB-C charging stand contacts
- Battery ADC monitoring
- BLE control
- WiFi control

## Safety

Do not connect ESP32 GPIO directly to unknown MCU pins until voltage levels are measured.
Use resistors and verify with a multimeter first.
