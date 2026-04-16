<img width="384" height="240" alt="CAD_view" src="https://github.com/user-attachments/assets/9c2ee669-fed4-4af3-bc3c-348eaa1da2b6" />
# Dual-Axis Light Tracker

## 1. Overview
This is a small solar light I built using an **Arduino Nano**. It uses four light sensors to find where the brightest light is and moves two servos (horizontal and vertical) to point directly at it. It’s basically a simplified version of how professional solar panels follow the sun to get more energy.

## 2. Why I made this
I wanted to see if I could build a mechanical system that reacts to its environment in real-time. It was a great way to practice how to turn analog sensor data into precise motor movements and to understand the math behind comparing light levels to decide direction.

## 3. How it works
The "brain" of the project is the Arduino, which constantly reads four **TEMT6000** sensors arranged in a cross (Up, Down, Left, Right). 

To keep the movement smooth:
* **The Logic:** It doesn't just look for the highest number. It compares the difference between opposite sensors (Left vs. Right and Up vs. Down). 
* **Proportional Speed:** If the light is way off to the side, the servos move faster. As it gets closer to the center, they slow down so it doesn't "jitter" or overshoot the target.
* **Accuracy:** I designed the 3D structure with separate walls for each sensor so they don't interfere with each other.

---

## 4. 3D Model & Visuals
![3D Model Screenshot](<img width="384" height="240" alt="image" src="https://github.com/user-attachments/assets/fb979155-2279-4966-a34f-a2fa28af51c7" />)
*Screenshot of the full assembly in Tinkercad/Fusion 360.*

---

## 5. Wiring
Everything is wired directly to the Nano as shown below:


| Component | Arduino Pin |
| :--- | :--- |
| **Sensor Down** | A0 |
| **Sensor Left** | A1 |
| **Sensor Right** | A2 |
| **Sensor Up** | A3 |
| **Servo Pan** | D9 |
| **Servo Tilt** | D10 |

*Note: All components share the 5V and GND pins of the Arduino via USB.*

---

## 6. Bill of Materials (BOM)


| Name | Purpose | Qty | Total (USD) | Link |
| :--- | :--- | :---: | :--- | :--- |
| 3D Printed Parts | Structure and housing | 1 | $3.00 | [View Files](./) |
| Micro Servos SG90 | Pan & Tilt movement | 2 | $9.22 | [Amazon Link](PEGA_LINK) |
| TEMT6000 Sensors | Light detection | 4 | $12.68 | [Amazon Link](PEGA_LINK) |
| Arduino Nano | Main controller | 1 | $11.53 | [Amazon Link](PEGA_LINK) |
| **Total Cost** | | | **$36.43** | |

---

## 7. Notes & Usage
1. **Calibration:** The tracker works best with a focused light source (like a flashlight) at 20-30cm.
2. **Environment:** High ambient light can confuse the sensors; it's best tested in dim rooms.
3. **Power:** Can be powered via any standard 5V USB power bank or computer port.
