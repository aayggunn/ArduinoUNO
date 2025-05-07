int sensorPin=10;

void setup() {

  pinMode(sensorPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  int deger=digitalRead(sensorPin);
  Serial.println(deger);
  delay(200);
  
}
