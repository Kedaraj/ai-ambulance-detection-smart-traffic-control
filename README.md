# 🚑 AI Ambulance Detection & Smart Traffic Control System

<div align="center">

# 🚦 AI-Powered Smart Traffic Management System

### Real-Time Ambulance Detection using ESP32-CAM, Arduino Mega & TinyML
![ESP32-CAM](https://i.ibb.co/JwbT6s6H/Chat-GPT-Image-Jul-17-2026-at-09-17-14-PM.png)
![ESP32-CAM](https://img.shields.io/badge/ESP32--CAM-IoT-blue?style=for-the-badge)
![Arduino Mega](https://img.shields.io/badge/Arduino-Mega-00979D?style=for-the-badge\&logo=arduino)
![TinyML](https://img.shields.io/badge/TinyML-Edge%20AI-orange?style=for-the-badge)
![Computer Vision](https://img.shields.io/badge/Computer-Vision-red?style=for-the-badge)
![Smart City](https://img.shields.io/badge/Smart-City-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge)

**An intelligent traffic management system that detects ambulances using an ESP32-CAM with an onboard TinyML model and automatically controls traffic signals through an Arduino Mega to create a green corridor for emergency vehicles.**

</div>

---

# 📖 Overview

The **AI Ambulance Detection & Smart Traffic Control System** improves emergency response by automatically identifying ambulances approaching an intersection.

The ESP32-CAM captures live images and runs a lightweight TinyML model to detect ambulances. When an ambulance is recognized, it sends a command to the Arduino Mega through serial communication. The Arduino Mega immediately changes the traffic signals to provide a green corridor, allowing the ambulance to pass safely and efficiently.

---

# ✨ Features

* 🚑 Real-time ambulance detection
* 📷 ESP32-CAM image capture
* 🧠 TinyML / Edge AI inference
* 🚦 Automatic traffic signal control
* 🟢 Green corridor generation
* 🔴 Automatic signal restoration
* ⚡ Low-latency communication
* 🔌 Serial communication between ESP32-CAM and Arduino Mega
* 🏙️ Smart city ready
* 📈 Expandable to multiple intersections

---

# 🛠 Hardware Components

| Component              |    Quantity |
| ---------------------- | ----------: |
| ESP32-CAM (AI Thinker) |           1 |
| Arduino Mega 2560      |           1 |
| USB Camera (ESP32-CAM) |    Built-in |
| Red LEDs               |           4 |
| Yellow LEDs            |           4 |
| Green LEDs             |           4 |
| 220Ω Resistors         |          12 |
| Breadboard             |           1 |
| Jumper Wires           | As Required |
| 5V Power Supply        |           1 |

---

# 💻 Software Used

* Arduino IDE
* ESP32 Board Package
* Arduino Mega Board Package
* ESP32 Camera Library
* TinyML / Edge Impulse Arduino Library
* C++

---

# 🔌 Hardware Connections

## ESP32-CAM → Arduino Mega

| ESP32-CAM  | Arduino Mega |
| ---------- | ------------ |
| TX (GPIO1) | RX1 (Pin 19) |
| RX (GPIO3) | TX1 (Pin 18) |
| GND        | GND          |

---

## Traffic Signal LEDs

| Arduino Mega Pin | Signal        |
| ---------------- | ------------- |
| 2                | Road 1 Red    |
| 3                | Road 1 Yellow |
| 4                | Road 1 Green  |
| 5                | Road 2 Red    |
| 6                | Road 2 Yellow |
| 7                | Road 2 Green  |
| 8                | Road 3 Red    |
| 9                | Road 3 Yellow |
| 10               | Road 3 Green  |
| 11               | Road 4 Red    |
| 12               | Road 4 Yellow |
| 13               | Road 4 Green  |

---

# 🏗 Hardware Architecture

```text
          Road
           │
           ▼
      ESP32-CAM
(Camera + TinyML)
           │
           ▼
     Serial UART
           │
           ▼
    Arduino Mega
           │
           ▼
   Traffic Signals
           │
           ▼
   Green Corridor
```

---

# 🧠 Software Architecture

```text
ESP32-CAM
     │
Capture Image
     │
     ▼
TinyML Inference
     │
     ▼
Serial Command
(A / N)
     │
     ▼
Arduino Mega
     │
     ▼
Traffic Light Control
```

---

# 🔄 Workflow

```text
Start
 │
 ▼
Initialize Camera
 │
 ▼
Capture Image
 │
 ▼
Run TinyML Model
 │
 ▼
Ambulance Detected?
 ┌───────────────┐
 │ Yes           │ No
 ▼               ▼
Send 'A'      Send 'N'
 │               │
 ▼               ▼
Arduino Mega Controls Signals
 │
 ▼
Green Corridor
 │
 ▼
Return to Normal Cycle
```

---

# 📂 Repository Structure

```text
ai-ambulance-detection-smart-traffic-control/
│
├── esp32_cam/
│   └── ESP32_CAM_Ambulance_Framework.ino
│
├── arduino_mega/
│   └── Arduino_Mega_Traffic_Controller.ino
│
├── tinyml/
│   ├── model.h
│   ├── model_data.cpp
│   └── labels.txt
│
├── diagrams/
│   ├── wiring_diagram.png
│   ├── block_diagram.png
│   ├── architecture.png
│   └── flowchart.png
│
├── images/
│   ├── prototype.jpg
│   ├── hardware.jpg
│   ├── testing.jpg
│   └── traffic_demo.jpg
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# 🚀 Installation

1. Install Arduino IDE.
2. Install the ESP32 Board Package.
3. Install the ESP32 Camera library.
4. Install the TinyML/Edge Impulse Arduino library.
5. Upload `ESP32_CAM_Ambulance_Framework.ino` to the ESP32-CAM.
6. Upload `Arduino_Mega_Traffic_Controller.ino` to the Arduino Mega.
7. Connect both boards using UART and a common GND.
8. Power the system and verify serial communication.
9. Integrate your trained TinyML model into the ESP32-CAM firmware.

---

# 📸 Screenshots

Add these images to the `images/` folder:

* Hardware Setup
* ESP32-CAM Module
* Arduino Mega Traffic Controller
* Traffic Signal Prototype
* Ambulance Detection Demo

---

# 🌍 Applications

* Smart Cities
* Emergency Vehicle Priority Systems
* Intelligent Traffic Management
* Hospitals
* Urban Road Networks
* Research Projects
* Engineering Demonstrations

---

# 🚀 Future Improvements

* 📡 Vehicle-to-Infrastructure (V2I) Communication
* ☁️ Cloud Monitoring Dashboard
* 📱 Mobile Monitoring App
* 📍 GPS-Based Ambulance Tracking
* 📊 Traffic Analytics
* 🛣️ Multi-Junction Coordination
* 🔔 Emergency Notifications
* 🤖 Improved AI Models

---

# 🤝 Contributing

Contributions are welcome.

1. Fork the repository.
2. Create a feature branch.
3. Commit your changes.
4. Submit a Pull Request.

---

# 📄 License

This project is licensed under the **MIT License**.

---

# 👨‍💻 Author

**KDJ**

**Techraft Studio**

*Building innovative IoT, AI, Robotics, Embedded Systems, and Smart City solutions.*

---

<div align="center">

### ⭐ If you found this project useful, please give it a Star!

**Made with ❤️ by Techraft Studio**

</div>
