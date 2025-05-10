#include <SPI.h>

int SSpin = 10;
int potpin = A0;
int val;

void setup() {

  SPI.begin();
  pinMode(SSpin, OUTPUT);

}

void loop() {

  digitalWrite(SSpin, LOW);
  delay(1);
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  SPI.transfer(val);
  delay(15);
  digitalWrite(SSpin, HIGH);
  
}