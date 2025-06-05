# Environmental-Alert-System
# EnviroAlert: Alpha Board Light & Temp Monitor

**EnviroAlert** is a smart environmental monitoring system built with the **Alpha Board**. It detects and displays ambient light and temperature levels using an LDR and an NTC thermistor, with thresholds set via onboard potentiometers. It uses LEDs and a buzzer for local alerts and logs data via `Serial` for debugging or external visualization.

---

##  Features

-  **Sensor Monitoring**:  
  - LDR for ambient light  
  - NTC thermistor for temperature  
-  **Threshold Configuration**:  
  - Two potentiometers for dynamic threshold setting  
- 💡 **LED Indicators**:  
  - Green = Normal  
  - Yellow = Warning  
  - Red = Critical  
-  **Buzzer Alerts**:  
  - Audible alarm for critical temperature or light
- **Serial1 Debugging**:  
  - Outputs real-time sensor readings and system state to Serial1 (USB-C)

---

##  Hardware Components

| Component        | Function                    |
|------------------|-----------------------------|
| Alpha Board      | Microcontroller platform     |
| LDR              | Light level sensor           |
| NTC Thermistor   | Temperature sensor           |
| Potentiometers x2| Set light & temp thresholds  |
| LEDs (Red, Yellow, Green) | Visual status alerts |
| Buzzer           | Audio alert for critical events |
| USB-C            | Serial1 output               |

---

##  How It Works

1. **Reads analog values** from:
   - LDR (`A0`) for light
   - Thermistor (`A3`) for temperature
   - Potentiometers (`A1` for light threshold, `A2` for temp threshold)

2. **Compares sensor data** to the threshold values.

3. **LED Logic:**
   - 🔴 Red LED for high light
   - 🟡 Yellow for warning level
   - 🟢 Green when conditions are normal

4. **Buzzer** triggers if temperature crosses a critical threshold.

5. **Serial Output:**
   ```plaintext
   Light: <value> | Temp: <value> | Light Thresh: <value> | Temp Thresh: <value>
 
