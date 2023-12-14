#include <Arduino.h>

int prev_stat = LOW;
void serial_print();

void setup() {
    pinMode(14, INPUT);
    Serial.begin(115200);
}

void loop() {
    int stat = digitalRead(14);
    if (stat == LOW && prev_stat == HIGH) {
        serial_print();
    }
    prev_stat = stat;
}

void serial_print() {
    static int count = 0;
    count++;
    if (count % 15 == 0) {
        Serial.println("Fizz Buzz");
    } else if (count % 3 == 0) {
        Serial.println("Fizz");
    } else if (count % 5 == 0) {
        Serial.println("Buzz");
    } else {
        Serial.println(count);
    }
}