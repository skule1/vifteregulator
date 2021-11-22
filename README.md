## Vifteregulator

Denne skissen leer tempraturen fra en BMP280, koblet til en ESP8266 via I2C-bus Temperaturen T1 leses fra sensoren, mappes om fra 30-50 til 0-100 og pusbreddestyres en motorkrets med D1 Mini I2C Dual Motor Driver Shield (HG7881) og styrer en 12V vifte på et grafikkkort. Viftemotor kobles til A0 og A1. 12 volt kobles + til VM og - til GND. Viften slår inn ved 30 grader og reguleres proporsjonalt til 50 grader. Etter dette får viften full energi. Temperaturen leses av i seriemonitoren. 2.mai 2021



![Regulator](https://skule.sormo.no/bilder/git/1.jpg)  ![Mikrokontroller](https://skule.sormo.no/bilder/git/2.jpg)  ![motor Shield](https://skule.sormo.no/bilder/git/3jpg)



