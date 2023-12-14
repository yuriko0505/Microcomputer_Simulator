#include <Arduino.h>

void setup() {
  digitalWrite(14, HIGH);
  pinMode(14, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(14, LOW);
    delay(500);
    digitalWrite(14, HIGH);
    delay(500);
  }
}
