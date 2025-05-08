int in1=8;
int in2=7;
int enbA=9;

void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enbA, OUTPUT);

}

void loop() {

 for(int i=0; i<255; i++){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enbA, i);
  delay(1000);

 }

}
