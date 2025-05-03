const int analog=A0;
const int ledPin = 9;

void setup() {

  pinMode(analog, INPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {

  int value = analogRead(analog);
  Serial.println("Value : ");
  Serial.println(value);
  delay(1);
  int ledValue = map(value,0,1023,0,255);
  analogWrite(ledPin, ledValue);
  
}
