# Smart Gas Leakage Alert System 🚨

## 📌 Project Overview
The Smart Gas Leakage Alert System is an IoT-based safety device designed to detect gas leakage and provide instant alerts. The system uses an ESP32 microcontroller with a gas sensor to monitor gas concentration. When gas leakage is detected, it activates a buzzer and sends real-time notifications through the Blynk IoT application.

## 🎯 Objective
To develop a low-cost and reliable gas leakage detection system that improves safety by providing early warnings and remote monitoring.

## 🛠️ Components Used

| Component | Purpose |
|-----------|---------|
| ESP32 | Main controller with WiFi connectivity |
| MQ-6 Gas Sensor | Detects LPG/gas leakage |
| Buzzer | Provides audio alert |
| LED | Indicates gas leakage status |
| Blynk IoT App | Sends mobile notifications |
| Jumper Wires | Connections |
| Breadboard | Circuit prototyping |

## ⚙️ Working Principle
1. The MQ-6 gas sensor continuously monitors gas concentration.
2. The ESP32 reads the sensor output values.
3. If the gas level exceeds the predefined threshold:
   - Buzzer turns ON.
   - LED indicates danger.
   - Notification is sent to the user's mobile through Blynk IoT.
4. The user can monitor gas levels remotely using the mobile application.

## ✨ Features
- Real-time gas leakage detection
- Mobile notification alert
- Low-cost safety solution
- WiFi-based remote monitoring
- Fast response system

## 🔌 Circuit Connections

**MQ-6 Sensor**
- VCC → 5V
- GND → GND
- AO → ESP32 GPIO 34

**Buzzer**
- Positive → ESP32 GPIO
- Negative → GND

## 💻 Software Used
- Arduino IDE
- Blynk IoT Platform
- Embedded C/C++

## 🌍 Applications
- Homes
- Kitchens
- Gas storage areas
- Industries
- Laboratories

## 🚀 Future Enhancements
- Automatic gas valve control
- SMS and call alerts
- AI-based gas leakage prediction
- Cloud data storage and analytics

## 👨‍💻 Developed By
Team Members:
- Your Name
- Team Member 1
- Team Member 2

## 📜 License
This project is open-source and created for educational purposes.
