#include <LiquidCrystal.h>
int sensorPin=A0;
int sensorDeger=0;
float gerilim=0;
float sicaklik=0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int position = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
 
 sensorDeger=analogRead(sensorPin);
 gerilim=(sensorDeger/1024.0) * 5000.0;
 sicaklik=gerilim/10.0;
 lcd.print("Sicaklik:");
  lcd.print(sicaklik);
}
