const int analog=A0;

void setup() {

  pinMode(analog, INPUT);
  Serial.begin(9600);

}

void loop() {

  int value = analogRead(analog);
  Serial.println("Value : ");
  Serial.println(value);
  delay(1000);
  
}
