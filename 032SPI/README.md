
# **📌 SPI (Serial Peripheral Interface) Haberleşme Projesi**  
# **📌 SPI Communication Project**  

---

## **📖 Proje Açıklaması / Project Description**  
Bu proje, bir ana (master) ve bir/çok köle (slave) cihaz arasında **SPI protokolü** kullanarak yüksek hızlı veri iletişimini gösterir. SD kartlar, ekranlar ve hızlı sensörlerle haberleşme için idealdir.

This project demonstrates **high-speed data communication** between one master and one/multiple slave devices using the **SPI protocol**, ideal for communicating with SD cards, displays and fast sensors.

---

### **🎯 Temel Özellikler / Key Features**  

| Türkçe | English |
|--------|---------|
| • **Full-duplex iletişim** | • **Full-duplex communication** |
| • **Yüksek hız** (10MHz+) | • **High speed** (10MHz+) |
| • **Senkron iletişim** | • **Synchronous communication** |
| • **4 hatlı tasarım** (MOSI, MISO, SCK, SS) | • **4-wire design** (MOSI, MISO, SCK, SS) |
| • **Çoklu cihaz desteği** (Slave Select) | • **Multi-device support** (Slave Select) |

---

## **🔌 Bağlantı Şeması / Connection Diagram**
```
[MASTER CİHAZ]    [SLAVE CİHAZ 1]
     MOSI -------------------> MOSI
     MISO <------------------- MISO
     SCK --------------------> SCK
     SS1 --------------------> SS
     GND --------------------> GND
```

⚠️ **ÖNEMLİ NOTLAR / IMPORTANT NOTES:**  
- **SS (Slave Select) hattı** her slave için ayrı olmalıdır  
- **SCK hattı** mümkün olduğunca kısa tutulmalıdır  
- **MISO hattına** pull-up direnci eklenebilir  

- **SS (Slave Select) line** must be separate for each slave  
- **SCK line** should be kept as short as possible  
- **Pull-up resistor** can be added to MISO line  

---

## **💻 Örnek Kodlar / Example Codes**

### **1️⃣ Master Cihaz Kodu / Master Device Code**
```cpp
#include <SPI.h>

// Türkçe Açıklama:
// SPI master olarak slave cihaza veri gönderir

// English Description:
// Sends data to slave device as SPI master

void setup() {
  SPI.begin(); // SPI başlat / Initialize SPI
  pinMode(SS, OUTPUT); // SS pini çıkış olarak / SS pin as output
}

void loop() {
  digitalWrite(SS, LOW); // Slave seç / Select slave
  SPI.transfer('A');     // Veri gönder / Send data
  digitalWrite(SS, HIGH);// Slave serbest bırak / Deselect slave
  delay(1000);
}
```

### **2️⃣ Slave Cihaz Kodu / Slave Device Code**
```cpp
#include <SPI.h>

// Türkçe Açıklama:
// SPI slave olarak gelen veriyi işler

// English Description:
// Processes incoming data as SPI slave

volatile byte receivedData;

void setup() {
  pinMode(MISO, OUTPUT); // MISO çıkış olarak / MISO as output
  SPCR |= _BV(SPE);     // Slave modunu etkinleştir / Enable slave mode
  SPCR |= _BV(SPIE);    // Kesmeyi etkinleştir / Enable interrupt
  Serial.begin(9600);
}

ISR (SPI_STC_vect) { // SPI kesme rutini / SPI interrupt routine
  receivedData = SPDR; // Veriyi al / Receive data
  Serial.println(receivedData); // Seri porta yazdır / Print to serial
}

void loop() {
  // Ana işlemler / Main operations
}
```

---

## **⚡ Teknik Detaylar / Technical Details**

### **SPI Modları / SPI Modes**
| Mod/Mode | CPOL | CPHA |
|----------|------|------|
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 2 | 1 | 0 |
| 3 | 1 | 1 |

### **Veri Çerçevesi / Data Frame**
```
[SS LOW] | [8-16 bit data] | [SS HIGH]
```

---

## **📊 Protokol Karşılaştırması / Protocol Comparison**

| Özellik/Feature | SPI | I2C | UART |
|----------------|-----|-----|------|
| **Hız/Speed** | 10MHz+ | 400kHz-3.4MHz | 115.2kbps |
| **Hat Sayısı/Lines** | 4+ | 2 | 2 |
| **Çoklu Cihaz/Multi-device** | ✔️ (Slave Select) | ✔️ (Addressing) | ❌ |
| **Mesafe/Distance** | <1m | <1m | 15m+ |

---
