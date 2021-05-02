 /***************************************************************************
Denne skissen leer tempraturen fra en BMP280, koblet til en ESP8266 via I2C-bus
Temperaturen T1 leses fra sensoren, mappes om fra 1-50 til 0-255 og pusbreddestyres
en motorkrets med HG7881 go styrer en 12V vifte på et grafikkkort.
Viften slår inn ved 30 grader og reguleres proporsjonalt til 50 grader.
Etter dette får viften full energi.
Temperaturen leses av i seriemonitoren.
2.mai 2021
 ***************************************************************************/
#define pinout  14  //GPIO14, D5
int T1;
int val;

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
                  pinMode(pinout,OUTPUT);
}

void loop() {
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

 
    Serial.println();
    T1= round(bmp.readTemperature());
    if (T1>25)
    {
        val = map(val, 0, 50, 0, 255);
      analogWrite(pinout,val);
    }
    delay(2000);
}
