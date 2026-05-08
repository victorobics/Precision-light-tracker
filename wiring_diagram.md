## Wiring diagram
Everything is connected to the Arduino Nano:

## Wiring

<img width="1600" height="1204" alt="image" src="https://github.com/user-attachments/assets/031b7333-8258-4847-a489-dbf8613d3f51" />


### Power

| Source        | Connection       |
|--------------|------------------|
| 5V Power Supply USB| Arduino Nano USB |


### Servos

| Component | Signal Pin | VCC | GND |
|----------|-----------|-----|-----|
| Servo PAN  | D9        | 5V  | GND |
| Servo TILT | D10       | 5V  | GND |


### Sensors

| Sensor Position | OUT Pin | VCC | GND |
|-----------------|--------|-----|-----|
| Down            | A0     | 5V  | GND |
| Right           | A1     | 5V  | GND |
| Left            | A2     | 5V  | GND |
| Up              | A3     | 5V  | GND |


All components have the same  5V and GND pins from the Arduino

