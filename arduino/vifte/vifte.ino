 /***************************************************************************
Denne skissen leer tempraturen fra en BMP280, koblet til en ESP8266 via I2C-bus
Temperaturen T1 leses fra sensoren, mappes om fra 30-50 til 0-100 og pusbreddestyres
en motorkrets med D1 Mini I2C Dual Motor Driver Shield (HG7881) og styrer en 12V vifte på et grafikkkort.
Viftemotor kobles til A0 og A1. 12 volt kobles + til VM og - til GND.
Viften slår inn ved 30 grader og reguleres proporsjonalt til 50 grader.
Etter dette får viften full energi.
Temperaturen leses av i seriemonitoren.
2.mai 2021
 ***************************************************************************/
#include "WEMOS_Motor.h"

int pwm;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30,_MOTOR_A, 1000);//Motor A



 
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
  Serial.begin(115200);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
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
//T1=70;
    if (T1>30)
    {
        val = map(T1, 30, 50, 0, 100);
    //  analogWrite(pinout,val);
       val=constrain(val,0,100);
          M1.setmotor(_CCW, val);
          Serial.println(val);
    }
    else
      M1.setmotor(_STOP);
    delay(2000);
}
