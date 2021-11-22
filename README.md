# Vifteregulator

Denne skissen leer tempraturen fra en BMP280, koblet til en ESP32 D1 mini via I2C-bus
Temperaturen t1 leses fra sensoren, mappes om fra 30-70 til 0-150 og pusbreddestyres
en Motor Shield  med D1 Mini I2C Dual Motor Driver Shield (HG7881)som styrer en 12V vifte på et grafikkkort.
Viftemotor kobles til A0 og A1. 12 volt kobles + til VM og - til GND.
Viften slår inn ved 30 grader og reguleres proporsjonalt til 70 grader.
Etter dette får viften full energi.
Temperaturen leses av i seriemonitoren.
2.mai 2021

En spenningsregulator gir 5v til kontrollkortet fra 12 forsyning på motorshield-et.
PWM-refekvensen settes til 20 0000 Hz , fra 1000Hz som var default. Før det støyet shield-det sjenerende.

<img src="H:\bilder\eshop\a\a1.jpg" alt="a1" style="zoom:33%;" />
