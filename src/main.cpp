#include <Arduino.h>

const uint8_t dorsiflexion = 15;
uint32_t last_print = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(dorsiflexion, OUTPUT);
  analogReadResolution(12);
  analogReadAveraging(100);
  Serial.begin(115200);
}

void loop() {
  int heel_force = analogRead(A0);
  int sole_force = analogRead(A2);
  uint32_t now = millis();

  if (now - last_print > 100) {
    last_print = now;
    Serial.print(heel_force);
    Serial.print(" ");
    Serial.println(sole_force);
  }

  if (heel_force > 3000 && sole_force > 3200) {
    delay(250);
    digitalWrite(dorsiflexion, 1);
    // delay(500);
  } else {
    digitalWrite(dorsiflexion, 0);
  }


}
