#include <Wire.h>

int potPin=A0;
int val;
int alici = 0x05;

void setup() {

  Wire.begin();     //  I2C Communication

}

void loop() {

  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 180);
  Wire.beginTransmission(alici);
  Wire.write(val);
  Wire.endTransmission();
  delay(50);
  
}
