const int POT_PIN = A1;          // Potentiometer
const int BUTTON_PIN = A4;       // Button to change color

const int LED_RED = 13;
const int LED_GREEN = 11;
const int LED_YELLOW = 10;       // Using Yellow instead of Blue

int colorMode = 0;               // 0 = Red, 1 = Green, 2 = Yellow
bool buttonPrevState = HIGH;

unsigned long lastPrintTime = 0;
const unsigned long printInterval = 500; // Print every 500 ms

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  Serial.begin(9600);
  delay(3000); // Initial delay
  Serial.println("Ready. Adjust brightness and press button to change LED color.");
}

void loop() {
  // Read potentiometer and convert to brightness
  int potValue = analogRead(POT_PIN);
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Check button press to change color
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonPrevState == HIGH && buttonState == LOW) {
    colorMode = (colorMode + 1) % 3; // Cycle through 0 → 1 → 2
    delay(200); // Debounce
  }
  buttonPrevState = buttonState;

  // Set LED brightness
  analogWrite(LED_RED,     colorMode == 0 ? brightness : 0);
  analogWrite(LED_GREEN,   colorMode == 1 ? brightness : 0);
  analogWrite(LED_YELLOW,  colorMode == 2 ? brightness : 0);

  // Serial printing
  if (millis() - lastPrintTime > printInterval) {
    Serial.print("Brightness: ");
    Serial.print(brightness);
    Serial.print(" | Color: ");
    if (colorMode == 0) Serial.println("Red");
    else if (colorMode == 1) Serial.println("Green");
    else if (colorMode == 2) Serial.println("Yellow");
    lastPrintTime = millis();
  }
}

