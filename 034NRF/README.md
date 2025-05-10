# NRF Modülleri Hakkında / About NRF Modules

## 📡 NRF24L01 Modülü Nedir? / What is the NRF24L01 Module?

**Türkçe:**  
NRF24L01, 2.4GHz frekansında çalışan, düşük güçlü ve uygun maliyetli bir kablosuz haberleşme modülüdür. Mikrodenetleyiciler arasında veri alışverişi yapmak için kullanılır. Genellikle Arduino projelerinde tercih edilir.

**English:**  
The NRF24L01 is a low-power, cost-effective wireless communication module operating at the 2.4GHz frequency. It is commonly used for data exchange between microcontrollers and is popular in Arduino projects.

---

## 🔌 Özellikleri / Features

**Türkçe:**  
- 2.4GHz ISM bandında çalışır  
- SPI arayüzü ile haberleşir  
- Maksimum 2 Mbps veri transferi  
- Düşük güç tüketimi  
- 125 adede kadar kanal desteği  
- 100 metreye kadar menzil (açık alanda)

**English:**  
- Operates in the 2.4GHz ISM band  
- Communicates via SPI interface  
- Up to 2 Mbps data rate  
- Low power consumption  
- Supports up to 125 channels  
- Range up to 100 meters (in open space)

---

## ⚙️ Kullanım Alanları / Applications

**Türkçe:**  
- Kablosuz sensör ağları  
- RC araç kontrolü  
- Ev otomasyonu  
- Endüstriyel veri aktarımı

**English:**  
- Wireless sensor networks  
- RC vehicle control  
- Home automation  
- Industrial data transmission

---

## 🔧 Bağlantı Şeması (Arduino) / Connection Diagram (Arduino)

| NRF24L01 | Arduino |
|----------|---------|
| VCC      | 3.3V    |
| GND      | GND     |
| CE       | D9      |
| CSN      | D10     |
| SCK      | D13     |
| MOSI     | D11     |
| MISO     | D12     |

⚠️ **Not / Note:** VCC pinine kesinlikle 5V bağlamayın, sadece 3.3V kullanın.

---

## 📎 Ek Bilgiler / Additional Info

**Türkçe:**  
Bazı modellerde voltaj regülatörü bulunmaz. Bu yüzden doğrudan 3.3V güç verilmesi gerekir. Yüksek kaliteli kablolar ve harici kapasitörler (örneğin 10µF) stabil çalışma sağlar.

**English:**  
Some models lack onboard voltage regulators. Therefore, direct 3.3V power is required. Use quality wires and external capacitors (e.g., 10µF) for stable operation.

---
