#include <SPI.h>
#include <Servo.h>

Servo myservo;
volatile uint8_t s_recv;
volatile bool flag = 0;

void setup() {

  myservo.attach(9);
  pinMode(MISO, OUTPUT);
  SPCR = (1 << SPE) | (1 << SPIE); // SPI Slave modunu etkinleştir ve kesmeyi aç
  sei(); // Genel kesmeleri etkinleştir

}

void loop() {

  myservo.write(s_recv);
  delay(16);
  
  if(flag) {
    SPDR = 'F'; // Master'a yanıt gönder
    flag = 0;
  }
  
}

// SPI Kesme Servis Rutini (Veri alındığında tetiklenir)
ISR(SPI_STC_vect) {
  s_recv = SPDR; // Gelen veriyi kaydet
  flag = 1;      // Bayrağı yükselt
}