#include <U8g2lib.h>
#include <Wire.h>

const int pumpPin = 7;
const int moisturePin = A0;
const int trigPin = 8;
const int echoPin = 9;

const int dryThreshold = 700; //drempelwaarde voor vochtigheid
const float tankEmptyThreshold = 11.0; // cm
const int pumpDuration = 2200;         // in ms
const int loopInterval = 30000;        // in ms

const float tankHeight = 13.4; // in cm
const float tankRadius = 5.0;  // 10 cm diameter

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

String getMoistureStatus(int value) {
  if (value < 400) return "Wet";
  else if (value < 600) return "Damp";
  else if (value < 700) return "Drying";
  else return "Dry";
}

// volume berekenen op basis van de afstand
float getWaterVolume(float measuredDistance) {
  float waterHeight = tankHeight - measuredDistance;
  if (waterHeight < 0) waterHeight = 0;
  float volume = 3.1416 * tankRadius * tankRadius * waterHeight;
  return volume; // mL
}

void updateDisplay(int moisture, float distance, long duration, bool tankEmpty, int countdownMs, bool watering = false) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);

  // Lijn 1: 
  String mLine = "Moisture: " + getMoistureStatus(moisture) + " (" + String(moisture) + ")";
  u8g2.drawStr(0, 10, mLine.c_str());

  // Lijn 2: 
  if (duration == 0 || tankEmpty) {
    u8g2.drawStr(0, 20, "Tank: Empty");
  } else {
    float volume = getWaterVolume(distance);
    String tLine = "Tank: " + String(volume, 0) + " mL";
    u8g2.drawStr(0, 20, tLine.c_str());
  }

  // Lijn 3: 
  String bLine = watering
    ? "Watering... " + String(countdownMs / 1000) + "s left"
    : "Next check in: " + String(countdownMs / 1000) + "s";
  u8g2.drawStr(0, 30, bLine.c_str());

  u8g2.sendBuffer();
}

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Serial is working!");
  u8g2.begin();
}

void loop() {
  int moisture = analogRead(moisturePin);

  // start meting waterniveau
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  float distance = duration * 0.034 / 2;
  bool tankEmpty = (duration == 0 || distance > tankEmptyThreshold);
  bool needWater = (moisture > dryThreshold);

  // water check
  if (needWater && !tankEmpty) {
    Serial.println("🌿 Watering...");

    for (int t = pumpDuration; t > 0; t -= 1000) {
      digitalWrite(pumpPin, HIGH);

      if (t % 5000 == 0) {
        digitalWrite(trigPin, LOW); delayMicroseconds(2);
        digitalWrite(trigPin, HIGH); delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH, 30000);
        distance = duration * 0.034 / 2;
        tankEmpty = (duration == 0 || distance > tankEmptyThreshold);
      }

      updateDisplay(moisture, distance, duration, tankEmpty, t, true);
      delay(1000);
    }

    digitalWrite(pumpPin, LOW);
    Serial.println("✅ Done watering");
  } else {
    if (!needWater) {
      u8g2.clearBuffer();
      u8g2.setFont(u8g2_font_6x12_tr);

      // Lijn 1: 
      String mLine = "Moisture: " + getMoistureStatus(moisture) + " (" + String(moisture) + ")";
      u8g2.drawStr(0, 10, mLine.c_str());

      // Lijn 2: 
      if (duration == 0 || tankEmpty) {
        u8g2.drawStr(0, 20, "Tank: Empty");
      } else {
        float volume = getWaterVolume(distance);
        String tLine = "Tank: " + String(volume, 0) + " mL";
        u8g2.drawStr(0, 20, tLine.c_str());
      }

      // Lijn 3: 
      u8g2.drawStr(0, 30, "Skipping watering...");
      Serial.println("❌ Skipped watering");
      u8g2.sendBuffer();

      delay(4000);
    }
  }

  for (int t = loopInterval; t > 0; t -= 1000) {
    if (t % 5000 == 0) {
      digitalWrite(trigPin, LOW); delayMicroseconds(2);
      digitalWrite(trigPin, HIGH); delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH, 30000);
      distance = duration * 0.034 / 2;
      tankEmpty = (duration == 0 || distance > tankEmptyThreshold);
    }

    updateDisplay(moisture, distance, duration, tankEmpty, t, false);
    delay(1000);
  }
}