#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String message = "  HELLO ARDUINO WORLD!!!  ";
int position = 0;

void setup() {
  lcd.begin(16, 2); // 16x2 LCD ekran
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(message.substring(position, position + 16));

  position++;
  if (position > message.length() - 16) {
    position = 0;
  }

  delay(500); // Kayma hız
}
