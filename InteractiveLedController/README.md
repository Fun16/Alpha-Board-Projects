# Interactive LED Controller

This project allows you to control the brightness and color of an LED using the potentiometer and buttons on the Alpha board.

##  Features
-  Adjust LED brightness smoothly with the built-in potentiometer.
-  Cycle through LED colors (Red, Green, Blue) using buttons.
-  Smooth fading transitions for visual appeal.
-  Serial monitor displays current brightness level every 3 seconds.

## 🛠️ How It Works
- Turn the potentiometer to control LED brightness (0–255).
- Press a button to change the LED color (red → green → blue → red...).
- The LED fades in/out instead of abrupt changes.

##  Hardware Used
- **Alpha Board** with:
  - Built-in Red, Green, and Yellow LEDs
  - 2 built-in pushbuttons
  - Potentiometers (POT1 or POT2)

>  No external components required

## How to Use
1. Upload the code to the Alpha board.
2. Open the Serial Monitor (9600 baud).
3. Use the potentiometer to adjust brightness.
4. Press the buttons to change colors.
5. Watch brightness and color updates on the LED and monitor.

## 📄 Code Summary
- `analogRead()` used for reading brightness value.
- `digitalRead()` detects button press to switch colors.
- `analogWrite()` adjusts LED brightness.
- `Serial.println()` shows brightness every 3 seconds.


