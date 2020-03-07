#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hello");
}

void loop() {
  lcd.setCursor(0, 1);
}

