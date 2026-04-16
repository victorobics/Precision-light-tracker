# Dual-Axis Light Tracker

## 1. Overview
This is a solar light tracking system built with an **Arduino Nano**. It uses four light sensors to detect the brightest light source and moves two servos (horizontal and vertical) to point directly at it. It simulates the mechanism professional solar panels use to maximize energy efficiency.

<p align="center">
  <img width="500" alt="Physical Project" src="https://github.com/user-attachments/assets/7c5043ac-cc1c-4150-93d7-3595696ac311" />
</p>

## 2. Why I made this
I wanted to build a mechanical system that reacts to its environment in real-time. This project helped me practice processing analog sensor data, coordinating 2-axis motor movements, and understanding the logic behind light-intensity comparison.

## 3. How it works
The system uses four **TEMT6000** sensors arranged in a cross configuration. 
* **The Logic:** Instead of just looking for the highest value, it calculates the difference between opposite sensors (Left/Right and Up/Down). 
* **Proportional Movement:** If the light is far from the center, the servos move faster; as it aligns, the movement slows down to avoid jitter.
* **Mechanical Design:** I designed separate compartments for each sensor to reduce light interference and improve directional accuracy.

---

## 4. 3D Model & Assembly
<p align="center">
  <img width="500" alt="CAD Assembly" src="https://github.com/user-attachments/assets/e3cd31bf-37cc-452a-a3d9-57a90d7bceb0" />
</p>

*Full CAD assembly including electronics (Arduino Nano, Servos, and Sensors).*

---

## 5. Wiring Diagram
Everything is connected directly to the Arduino Nano as follows:


| Component | Pin |
| :--- | :--- |
| **Sensor Down** | A0 |
| **Sensor Left** | A2 |
| **Sensor Right** | A1 |
| **Sensor Up** | A3 |
| **Servo PAN** | D9 |
| **Servo TILT** | D10 |

*Note: All components share common 5V and GND rails via the Arduino's USB power.*

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

## 7. Assembly Notes & Lessons Learned
* **Sensor Depth:** During testing, I found that installing sensors between **10mm to 20mm deep** inside the structure provides the most accurate readings.
* **Cable Management:** I used silicone to secure joints and keep cables flush against the walls, preventing them from tangling during rotation.
* **Prototyping:** I initially installed the sensors in the wrong orientation, which required a code update. For future versions, I would design cable holes directly into the CAD to avoid manual drilling after printing.

---

## 8. Usage
1. Upload the `light_tracker_final.ino` firmware.
2. Power via USB.
3. Use a flashlight at 20-30cm to test the tracking speed.
