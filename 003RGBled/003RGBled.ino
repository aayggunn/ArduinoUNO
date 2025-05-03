const int red=9;
const int green=10;
const int blue=11;
const int time=1000;

void setup() {

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {

  digitalWrite(red, LOW);
  delay(time);

  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  delay(time);

  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(time);

  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  delay(time);

  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);

}
