#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(14, INPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {
    int stat = 0;
    for (int i = 0; i < 100; i++) {
        stat |= digitalRead(14);
        delay(10);
    }
    lcd.setCursor(0, 0);
    if (stat) {
        lcd.print("Motion detected!");
    } else {
        lcd.print("No motion       ");
    }
}