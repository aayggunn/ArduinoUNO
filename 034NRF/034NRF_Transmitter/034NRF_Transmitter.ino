#include <SPI.h>
#include <RF24.h>

// Pin tanımlamaları / Pin definitions
RF24 nrf(9, 10);  // CE: 9, CSN: 10
const byte address[6] = "00001";  // Haberleşme adresi / Communication address
const int buttonPin = 2;          // Buton pini / Button pin

// Değişkenler / Variables
bool buttonState = false;         // Buton durumu / Button state
bool lastButtonState = false;     // Önceki buton durumu / Previous button state

void setup() {
  // Pin ayarları / Pin configurations
  pinMode(buttonPin, INPUT_PULLUP); // Buton girişi (dahili pull-up) / Button input (internal pull-up)
  
  // NRF24 başlatma / NRF24 initialization
  nrf.begin();
  nrf.openWritingPipe(address);    // Veri gönderme adresi / Transmitting address
  nrf.setPALevel(RF24_PA_MIN);    // Güç seviyesi (MIN, LOW, HIGH, MAX) / Power level
  nrf.stopListening();             // Verici modu / Transmitter mode
  
  Serial.begin(9600);              // Seri haberleşme başlat / Start serial communication
  Serial.println("NRF24 Verici Hazır!"); // NRF24 Transmitter Ready!
}

void loop() {
  // Buton durumunu oku (ters mantık: PULLUP olduğu için) / Read button state (inverted logic due to PULLUP)
  buttonState = !digitalRead(buttonPin);
  
  // Buton durumu değiştiyse / If button state changed
  if (buttonState != lastButtonState) {
    // Buton basıldıysa / If button is pressed
    if (buttonState) {
      bool success = nrf.write(&buttonState, sizeof(buttonState)); // Veri gönder / Send data
      
      // Gönderme sonucunu seri porta yazdır / Print transmission result to serial
      if (success) {
        Serial.println("Veri gonderildi: Buton BASILDI");
      } else {
        Serial.println("Gonderim basarisiz!");
      }
    }
    delay(50); // Debounce gecikmesi / Debounce delay
  }
  
  lastButtonState = buttonState; // Buton durumunu güncelle / Update button state
}