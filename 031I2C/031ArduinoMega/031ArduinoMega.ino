#include <Wire.h>
#include <Servo.h>

Servo myServo;
int val;

void setup() {

  myServo.attach(9);
  Wire.begin(5);
  Wire.onReceive(oku);

}

void oku(){

  val = Wire.read();

}

void loop() {

  myServo.write(val);
  
}
