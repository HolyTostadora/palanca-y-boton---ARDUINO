#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define CS 2
#define RESET PC6
#define DC 4
#define MOSI 11
#define SCK 13
#define LED 7
#define MISO 12                

Adafruit_ILI9341 tft = Adafruit_ILI9341 (CS,DC,MOSI,SCK,RESET,MISO);

void setup() {
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLUE);

}

void loop() {
  // put your main code here, to run repeatedly:

}
