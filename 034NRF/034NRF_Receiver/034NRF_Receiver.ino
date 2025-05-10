#include <SPI.h>
#include <RF24.h>

// Pin tanımlamaları / Pin definitions
RF24 nrf(9, 10);  // CE: 9, CSN: 10
const byte address[6] = "00001";  // Haberleşme adresi (vericiyle aynı olmalı) / Communication address (must match transmitter)

// Değişkenler / Variables
bool receivedData = false;  // Alınan veri / Received data
int ledPin = 6;            // LED pini / LED pin

void setup() {
  // Pin ayarları / Pin configurations
  pinMode(ledPin, OUTPUT);  // LED çıkışı / LED output
  
  // NRF24 başlatma / NRF24 initialization
  nrf.begin();
  nrf.openReadingPipe(0, address);  // Veri alma adresi / Receiving address
  nrf.setPALevel(RF24_PA_MIN);      // Güç seviyesi (vericiyle aynı olmalı) / Power level (must match transmitter)
  nrf.startListening();             // Alıcı modu / Receiver mode
  
  Serial.begin(9600);               // Seri haberleşme başlat / Start serial communication
  Serial.println("NRF24 Alıcı Hazır!"); // NRF24 Receiver Ready!
}

void loop() {
  // Veri kontrolü / Data check
  if (nrf.available()) {
    nrf.read(&receivedData, sizeof(receivedData));  // Veriyi oku / Read data
    
    // LED kontrolü / LED control
    digitalWrite(ledPin, receivedData ? HIGH : LOW);
    
    // Seri porta durum yazdır / Print status to serial
    Serial.print("Alınan veri: ");
    Serial.println(receivedData ? "BUTON BASILDI" : "BUTON BIRAKILDI");
  }
  
  delay(100);  // Küçük bir gecikme / Small delay
}