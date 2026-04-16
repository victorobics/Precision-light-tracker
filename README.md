# Dual-Axis Light Tracker

## 1. Overview
This is a small solar light I built using an **Arduino Nano**. It uses four light sensors to find where the brightest light is and moves two servos (horizontal and vertical) to point directly at it. It’s basically a simplified version of how professional solar panels follow the sun to get more energy.

<img width="384" height="240" alt="image" src="https://github.com/user-attachments/assets/7c5043ac-cc1c-4150-93d7-3595696ac311" />

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
<img width="384" height="240" alt="image" src="https://github.com/user-attachments/assets/e3cd31bf-37cc-452a-a3d9-57a90d7bceb0" />

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
| Micro Servos SG90 | Pan & Tilt movement | 2 | $9.22 | [Amazon Link](https://www.amazon.es/-/en/HOTUT-Pieces-Helicopters-Vehicle-Models/dp/B0DSPYZ4SH/ref=sr_1_11?crid=11P4S5D2O119K&dib=eyJ2IjoiMSJ9.A04Va_VMR3NyeR54cJikCspZNMz05JVdiRY0rmQlCWTIs-G5V_d0KXfM_tEQmkQt8Frh3h2LLV_ntY4v9CpHwYQIZ2KuB82Xf6RPcZ2w1T8x5AXGrxNC-_0sdfrSMgnE1AlE0ihyCD_LC2GobcNV7NjmpjGps4getRQ3T4AK9BvyiKEIvTuabsCMiu9qBIUaDVutiuGYKpVLLrRFE-cCDimBNw1MyHczwe_i3f9fb8vUyqADGpuJSjlpQ3ctwvFmpQy-9sv2pcrwxAzJTFBvr2UZ2E1tafN-IccaCjt4TDo.Mg0ZCYvwK8hECP17acZcv1Uk4SFWt817w3ah7q0tk74&dib_tag=se&keywords=servomotores&qid=1775147990&sprefix=servomotore%2Caps%2C94&sr=8-11&th=1) |
| TEMT6000 Sensors | Light detection | 4 | $12.68 | [Amazon Link](https://www.amazon.es/Youmile-TEMT6000-Ambient-Intensity-Detection/dp/B08SM32DJL/ref=sr_1_2_sspa?crid=15O9WNFDWMWQS&dib=eyJ2IjoiMSJ9.OUM4SBCcli6KQBNyBDGglg.SOXKNxyW3oqY40Ion3Uf0XbyKzN_duGgHWyCMX3NFZ4&dib_tag=se&keywords=temt6000&qid=1775147653&sprefix=temt6000%2Caps%2C95&sr=8-2-spons&aref=UNFn4q1ro1&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) |
| Arduino Nano | Main controller | 1 | $11.53 | [Amazon Link](https://www.amazon.es/-/en/ELEGOO-Na-no-Compatible-Arduino-Project/dp/B0716T2L77/ref=sr_1_1?dib=eyJ2IjoiMSJ9.qVOpDeZJd_-KwgDo1A2QveW9lSpTT6UbsXs5XnnEEhOh49q705fQjL41JFiCm5Ir1oaH5tTbAaja5j2TCxNb1VbdJsc-JiG_xZe7BxweomqN77-n0PDTkLvlYrymF6d9S952xPyGMTEbEX9vwhY3WhaPRkifsfNCdxgbuRblT9P-14rg6JmUc5yHPLlRaTz9oTWG9VNWTrAqqmwScdedeSuXTkDyfYi7LQEi9EV6-gvKJ9l8hRcNO2JFR0t3SXdS8ULhV-JYlR5ry-Im4jHZ9ADeJu5Fp-m-LmVP-ajdBW4.eWnxISyO6FJHWf8VVjivNNnluf3s4LI5XHhRBZrVK1k&dib_tag=se&keywords=arduino%2Bnano&qid=1775147568&sr=8-1&th=1) |
| **Total Cost** | | | **$36.43** | |

---

## 7. Notes & Usage
1. **Calibration:** The tracker works best with a focused light source (like a flashlight) at 20-30cm.
2. **Environment:** High ambient light can confuse the sensors; it's best tested in dim rooms.
3. **Power:** Can be powered via any standard 5V USB power bank or computer port.
