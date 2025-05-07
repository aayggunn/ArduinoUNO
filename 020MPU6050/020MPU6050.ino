#include <MPU6050.h>
#include <Wire.h>

MPU6050 sensor;

int ivmeX, ivmeY, ivmeZ, GyroX, GyroY, GyroZ;

void setup() {

  Serial.begin(9600);
  Wire.begin();
  sensor.initailize();

}

void loop() {

  sensor.getAcceleration(&ivmeX, &ivmeY, &ivmeZ);
  sensor.getRotation(&GyroX, &GyroY, &GyroZ);

  Serial.print("ivmeX = ");
  Serial.println(ivmeX);

  Serial.print("ivmeY = ");
  Serial.println(ivmeY);

  Serial.print("ivmeZ = ");
  Serial.println(ivmeZ);

  Serial.print("GyroX = ");
  Serial.println(GyroX);

  Serial.print("GyroY = ");
  Serial.println(GyroY);

  Serial.print("GyroZ = ");
  Serial.println(GyroZ);
  delay(1000);
}
