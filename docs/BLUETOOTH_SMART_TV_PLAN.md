# Bluetooth Smart TV Expansion

The ESP32-S3 upgrade will not only be an IR remote. It will also become a Bluetooth capable smart controller.

Goals:

- Bluetooth Low Energy phone remote
- Bluetooth HID support where compatible
- Smart TV control support where protocols allow
- WiFi control APIs
- Macro commands combining IR + Bluetooth

Architecture:

```
Phone / Smart TV
        |
   Bluetooth / WiFi
        |
    ESP32-S3
        |
 +------+------+
 |             |
IR Engine   BLE Stack
 |             |
Stereo      Smart Devices
```

The ESP32-S3 becomes the main operating system while the original Onkyo remote hardware remains a source of knowledge and compatibility.
