#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.print("Hello");
  delay(200);
  lcd.print("World");
  delay(500);
}
