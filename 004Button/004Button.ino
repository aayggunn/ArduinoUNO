const int ledPin=9;
const int buttonPin=10;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  int value=digitalRead(buttonPin);
  if(value == HIGH) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
  
}
