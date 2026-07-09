# 🤖 Bluetooth Controlled Robot using PIC16F877A

![Robot Cover](https://github.com/maryam-engineer-cmd/Bluetooth-Controlled-Robot/raw/main/WhatsApp%20Image%202026-07-09%20at%205.42.52%20PM.jpeg)

👩‍🎓 **Prepared by:**  Eng:Maryam Mohamed Ramy
🎓 **Ahram Canadian University**

---

## 📌 Overview
This project presents a Bluetooth-controlled robotic vehicle designed using the PIC16F877A microcontroller. The robot is controlled wirelessly through an Android smartphone using the HC-05 Bluetooth module. The system receives commands from the mobile application via UART communication and controls the motors using the L298N motor driver.

---

## 📖 Introduction
The Bluetooth controlled robot car is a remotely operated vehicle that can be controlled using a smartphone via Bluetooth communication. This project uses an **HC-05 Bluetooth module** for wireless communication, a **PIC16F877A microcontroller** for processing commands, and an **L298N motor driver** to control the movement of the motors.

---

## 🎯 Objectives
- Design and implement a Bluetooth controlled robot car.
- Enable remote control of the robot car using a smartphone via Bluetooth communication.
- Control the robot's movement using PIC16F877A microcontroller and L298N motor driver.
- Ensure reliable and efficient navigation and safe operation.

---

## 🧩 System Components
- PIC16F877A Microcontroller
- HC-05 Bluetooth Module
- L298N Dual H-Bridge Motor Driver
- 4WD Robot Car Chassis Kit
- DC Gear Motors (4x)
- 2x 18650 Li-ion Batteries (3.7V)
- 18650 Battery Holder (2-Slot)
- 18650 Battery Charger
- Jumper Wires (Male to Male & Male to Female)
- Small Toggle Switch
- Standoffs & Screws (M3)

---

## ⚙️ Components Used (Details)

| Component | Function |
|---|---|
| **PIC16F877A** | The brain of the robot. Receives commands from Bluetooth and controls the motors. |
| **HC-05 Bluetooth Module** | Receives commands from the mobile phone via Bluetooth and sends them to the PIC. |
| **L298N Motor Driver** | Controls the direction and speed of the 4 DC motors based on commands from the PIC. |
| **4x DC Motors** | Provide movement to the robot (2 motors on each side). |
| **2x 18650 Li-ion Batteries** | Provide power to the robot (7.4V) through a power switch. |
| **ON/OFF Switch** | Used to turn the robot power ON or OFF. |

---

## 🖼️ Hardware Setup

Below is a photo of the assembled 4WD robot chassis showing the breadboard, L298N driver, HC-05 module, and battery holder wiring:

![Robot Hardware Setup](https://github.com/maryam-engineer-cmd/Bluetooth-Controlled-Robot/raw/main/WhatsApp%20Image%202026-07-09%20at%205.42.52%20PM.jpeg)

---

## 🔌 Circuit Connections

### HC-05 → PIC16F877A
| HC-05 Pin | PIC Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | RC7/RX (Pin 26) |
| RXD | RC6/TX (Pin 25) |

> ⚠️ Note: Bluetooth TX/RX must be connected crossed to the PIC's RX/TX.

### L298N → PIC16F877A (4 Motors)
| L298N Pin | PIC Pin |
|---|---|
| IN1 | RD0 (Pin 19) |
| IN2 | RD1 (Pin 20) |
| IN3 | RB0 (Pin 33) |
| IN4 | RB1 (Pin 34) |
| ENA | RC2/CCP1 (Pin 17) |
| ENB | RC1/CCP2 (Pin 16) |

### Motors → L298N
| Motor | Side |
|---|---|
| M1 | Front Right |
| M2 | Rear Right |
| M3 | Front Left |
| M4 | Rear Left |

### Power
- Two 18650 Li-ion batteries in series (7.4V) power the L298N motor driver.
- PIC and HC-05 are powered with 5V from the driver's onboard regulator.
- All grounds (batteries, driver, PIC) must be connected together (common GND).

---

## 💻 Code (Main Logic)
The full source code is available in [`main.c`](./main.c).

Commands received over Bluetooth (UART, 9600 baud):

| Command | Action |
|---|---|
| `F` / `f` | Move Forward |
| `B` / `b` | Move Backward |
| `L` / `l` | Turn Left |
| `R` / `r` | Turn Right |
| `S` / `s` / `0` | Stop |
| `1`–`9` | Set Speed (Slow → Max) |

The robot also includes a **safety timeout**: if no command is received for a short period, the motors automatically stop.

---

## 📊 Project Presentation
You can view the full project presentation here: [Presentation.pptx](./Presentation.pptx)

---

## 🎥 Demo Videos

**Full demo:**

https://github.com/maryam-engineer-cmd/Bluetooth-Controlled-Robot/raw/main/WhatsApp%20Video%202026-07-09%20at%205.21.36%20PM.mp4

**Testing the robot during the project discussion:**

https://github.com/maryam-engineer-cmd/Bluetooth-Controlled-Robot/raw/main/WhatsApp%20Video%202026-07-09%20at%205.42.43%20PM.mp4

---

## 📱 Mobile Control
The robot is controlled through a simple mobile Bluetooth controller app with:
- Directional buttons (Up / Down / Left / Right)
- Stop button
- Speed control slider

---

## ✅ Conclusion
The Bluetooth controlled robot car was successfully designed and implemented using PIC16F877A microcontroller, HC-05 Bluetooth module, and L298N motor driver. The robot can be controlled remotely via smartphone using Bluetooth communication, making it a simple, efficient, and reliable solution for various applications.

## 🚀 Future Work
- Add more sensors (ultrasonic, line tracking, etc.) for better environment awareness.
- Implement PID control for smoother and more stable movement.
- Add speed control with adjustable levels.
- Implement wireless control over Wi-Fi for longer range and better performance.
- Improve battery life and optimize power consumption.

---

## 🙏 Acknowledgements
Special thanks to:
- **Dr. Mohamed Goda**
- **Eng. Loay Hussien**
- **Eng. Rahma Salama**

for their great support and effort with this project.

---

## 🏷️ Tags
`microcontroller` `robotics` `embedded-systems` `uart` `l298n` `pic16f877a` `mikroc` `embedded-c` `hc05`
