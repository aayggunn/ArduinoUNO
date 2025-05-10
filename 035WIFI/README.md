# 📶 ESP8266 Wi-Fi Modülü / ESP8266 Wi-Fi Module

## 📋 Teknik Özellikler / Technical Specifications

| Özellik (TR)                            | Feature (EN)                           |
|----------------------------------------|----------------------------------------|
| Wi-Fi Standardı: 802.11 b/g/n           | Wi-Fi Standard: 802.11 b/g/n           |
| Frekans: 2.4 GHz                        | Frequency: 2.4 GHz                     |
| Güç Girişi: 3.0V - 3.6V (ideali 3.3V)   | Power Input: 3.0V - 3.6V (ideal: 3.3V) |
| GPIO Sayısı: 17                         | GPIO Pins: 17                          |
| UART, SPI, I2C Desteği                  | Supports UART, SPI, I2C                |
| Flash Bellek: 512 KB - 4 MB             | Flash Memory: 512 KB - 4 MB            |
| İşlemci: Tensilica L106 (80 MHz)        | Processor: Tensilica L106 (80 MHz)     |
| TCP/IP Yığını Entegre                   | Integrated TCP/IP stack                |
| Modlar: İstemci, Erişim Noktası, Her İkisi | Modes: Station, Access Point, Both   |

---

## 🌐 ESP8266 Nedir? / What is ESP8266?

**🇹🇷 Türkçe:**  
ESP8266, düşük maliyetli, küçük boyutlu ve Wi-Fi bağlantı yeteneğine sahip bir mikrokontrolcü çipidir. IoT (Nesnelerin İnterneti) projelerinde yaygın olarak kullanılır. Arduino ile birlikte AT komutları ya da doğrudan programlama ile kontrol edilebilir.

**🇬🇧 English:**  
ESP8266 is a low-cost, compact microcontroller chip with built-in Wi-Fi capability. It is widely used in IoT (Internet of Things) projects. It can be controlled via AT commands or programmed directly using the Arduino IDE.

---

## 🛠️ AT Komutları Nedir? / What are AT Commands?

**🇹🇷 Türkçe:**  
ESP8266 Wi-Fi modülü, Arduino gibi cihazlarla seri haberleşme (UART) üzerinden AT komutları ile kontrol edilebilir. Bu komutlarla Wi-Fi ağına bağlanmak, veri göndermek, bağlantı kurmak gibi işlemler gerçekleştirilir.

**🇬🇧 English:**  
The ESP8266 module can be controlled using AT commands via UART from devices like Arduino. These commands are used to connect to Wi-Fi, send data, establish TCP/UDP connections, etc.

---

## 📋 Yaygın AT Komutları / Commonly Used AT Commands

| Komut / Command         | Açıklama (TR)                               | Description (EN)                             |
|-------------------------|---------------------------------------------|----------------------------------------------|
| `AT`                    | Modül çalışıyor mu kontrol eder             | Tests if the module is responding            |
| `AT+RST`                | Modülü yeniden başlatır                     | Resets the module                            |
| `AT+GMR`                | Firmware versiyonunu gösterir               | Shows firmware version                       |
| `AT+CWMODE=1`           | Station moduna geçer                        | Sets mode to station                         |
| `AT+CWJAP="SSID","PASS"`| Belirtilen Wi-Fi ağına bağlanır             | Connects to the given Wi-Fi network          |
| `AT+CIFSR`              | IP adresini listeler                        | Lists IP address                             |
| `AT+CIPSTART="TCP","ip",port`| TCP bağlantısı başlatır             | Starts a TCP connection                      |
| `AT+CIPSEND=n`          | n byte veri gönderir                        | Sends n bytes of data                        |
| `AT+CIPCLOSE`           | TCP bağlantısını sonlandırır                | Closes the TCP connection                    |

---

## ⚙️ Donanım Bilgileri / Hardware Details

- **Güç Voltajı:** 3.3V (Kesinlikle 5V bağlanmamalıdır!)  
- **Bağlantı Tipi:** UART (TX, RX pinleri ile)  
- **Baud Rate:** 9600 veya 115200 (modüle göre değişebilir)  
- **Gerilim Seviyesi:** TX için seviye dönüştürücü önerilir  
- **GPIO’lar:** Röle kontrolü, sensör veri okuma gibi görevler için kullanılabilir

---

## ⚠️ Notlar / Notes

- **🇹🇷** Tüm AT komutları `\r\n` ile bitmelidir. Arduino'da `Serial.println()` kullanıldığında bu otomatik olur.  
- **🇬🇧** All AT commands must end with `\r\n`. Arduino’s `Serial.println()` handles this automatically.  
- Modülden `OK` cevabı alınmazsa bağlantı veya baud ayarları kontrol edilmelidir.  
- Yetersiz voltaj ya da yanlış bağlantılar modüle zarar verebilir.

---
