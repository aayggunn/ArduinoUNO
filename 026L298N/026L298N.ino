int in1=8;
int in2=7;
int enbA=9;

void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enbA, OUTPUT);

}

void loop() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(1000);
  digitalWrite(in1, LOW);
  delay(1000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);
  digitalWrite(in1, LOW);
  delay(1000);

}
