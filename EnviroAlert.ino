#define RED 13
#define YELLOW 12
#define GREEN 11
#define BUZZER 9

// Beta model constants for NTC thermistor
const float BETA = 3950;         // Beta value
const float T0 = 298.15;         // 25°C in Kelvin
const float R0 = 10000;          // Resistance at 25°C
const float SERIES_RESISTOR = 10000; // 10kΩ fixed resistor

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(A0);         // LDR sensor value
  int lightThreshold = analogRead(A1); // Pot for light threshold
  int tempRaw = analogRead(A3);        // NTC sensor raw reading
  int tempThreshold = analogRead(A2);  // Pot for temperature threshold (0–1023 mapped later)

  // Convert raw NTC reading to temperature in Celsius using Beta formula
  float voltage = tempRaw * (5.0 / 1023.0);
  float resistance = SERIES_RESISTOR * (1023.0 / (float)tempRaw - 1.0);
  float temperatureK = 1.0 / (1.0 / T0 + log(resistance / R0) / BETA);
  float temperatureC = temperatureK - 273.15;

  // Map temperature threshold pot (0–1023) to 0–100°C
  int tempThreshC = map(tempThreshold, 0, 1023, 0, 100);

  // Light logic
  if (light > lightThreshold + 200) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  } else if (light > lightThreshold - 100) {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
  }

  // Temperature logic (based on actual °C)
  if (temperatureC > tempThreshC) {
    tone(BUZZER, 1000); // frequency in Hz
  } else {
    noTone(BUZZER);
  }

  // Serial output for debugging
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print(" lux | Temp: ");
  Serial.print(temperatureC, 2);
  Serial.print(" °C | Light Thresh: ");
  Serial.print(lightThreshold);
  Serial.print(" | Temp Thresh: ");
  Serial.print(tempThreshC);
  Serial.println(" °C");

  delay(1000);
}

