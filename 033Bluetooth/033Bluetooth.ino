#include <Adafruit_NeoPixel.h>
#define PIXELSAYISI 11  // Number of LEDs / LED sayısı
#define NEOPIXELPIN 6   // NeoPixel data pin / NeoPixel veri pini

Adafruit_NeoPixel SERIDLED(PIXELSAYISI, NEOPIXELPIN, NEO_GRB + NEO_KHZ800);
char veri;  // Serial data variable / Seri veri değişkeni

void setup() {

    Serial.begin(9600);    // Start serial communication / Seri haberleşmeyi başlatıyoruz
    SERIDLED.begin();      // Initialize NeoPixels / NeoPixelleri başlatıyoruz
    SERIDLED.show();         // Initialize all pixels to off / Tüm LED'leri söndürüyoruz
}

void loop() {

    if(Serial.available() > 0){    // Check for incoming data / Gelen veriyi kontrol ediyoruz
        veri = Serial.read();      // Read serial data / Seri haberleşmeden gelen veriyi okuyoruz
        
        if(veri == 'k'){    // 'k' for red / kırmızı için 'k'
            for(int i=0; i<PIXELSAYISI; i++) {
                SERIDLED.setPixelColor(i, SERIDLED.Color(150, 0, 0)); // Red / Kırmızı
                SERIDLED.show();
                delay(50);
            }
        }
        else if(veri == 'y'){    // 'y' for yellow / sarı için 'y'
            for(int i=0; i<PIXELSAYISI; i++) {
                SERIDLED.setPixelColor(i, SERIDLED.Color(150, 150, 0)); // Yellow / Sarı
                SERIDLED.show();
                delay(50);
            }
        }
        else if(veri == 'm'){    // 'm' for green / yeşil için 'm'
            for(int i=0; i<PIXELSAYISI; i++) {
                SERIDLED.setPixelColor(i, SERIDLED.Color(0, 150, 0)); // Green / Yeşil
                SERIDLED.show();
                delay(50);
            }
        }
        else if(veri == 's'){    // 's' for off / söndürmek için 's'
            for(int i=0; i<PIXELSAYISI; i++) {
                SERIDLED.setPixelColor(i, SERIDLED.Color(0, 0, 0)); // Off / Söndür
                SERIDLED.show();
                delay(50);
            }
        }
    }
    
}