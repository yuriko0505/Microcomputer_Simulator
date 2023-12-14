#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// ref: https://docs.wokwi.com/parts/wokwi-photoresistor-sensor

const float GAMMA = 0.7;
const float RL10 = 50;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(A0, INPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {
    int analogValue = analogRead(A0);
    float voltage = analogValue / 4096. * 5;
    float resistance = 2000 * voltage / (1 - voltage / 5);
    float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

    lcd.setCursor(0, 0);
    lcd.print("Lux: ");
    lcd.print(lux);
    lcd.print("          ");
    delay(1000);
}