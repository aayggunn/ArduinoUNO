#include <LiquidCrystal.h>

int sensorPin = A3;
float sensorDeger = 0;
float gerilim = 0;
float sicaklik = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);          
  lcd.begin(16, 2);            
  lcd.setCursor(0, 0);
  lcd.print("Sicaklik:");
}

void loop() {
  sensorDeger = analogRead(sensorPin);

  gerilim = (sensorDeger * 5.0) / 1023.0;

  sicaklik = gerilim * 100.0;

  lcd.setCursor(0, 1);
  lcd.print("                ");  
  lcd.setCursor(0, 1);
  lcd.print(sicaklik, 1);       
  lcd.print((char)223);         
  lcd.print("C");

  Serial.print("Analog Deger: ");
  Serial.print(sensorDeger);
  Serial.print(" | Gerilim: ");
  Serial.print(gerilim, 3);     
  Serial.print(" V | Sicaklik: ");
  Serial.print(sicaklik, 1);    
  Serial.println(" C");

  delay(1000);
}
