#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#include <SPI.h>          
#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;



#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


const int maxStrings = 10; // Máximo número de elementos en el array
String stringArray[maxStrings]; // Array para almacenar las cadenas

void setup() {
  Serial.begin(9600);
  
  uint16_t ID = tft.readID(); 
  tft.begin(ID);

  tft.setRotation(1);  
  tft.fillScreen(WHITE);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);  
}

void loop() {
  if (Serial.available()) {
    String dataFromUnity = Serial.readStringUntil('\n'); // Lee el string enviado por Unity hasta un salto de línea
    
    int index = 0;

    // Divide el string por comas y almacena en el array
    while (dataFromUnity.length() > 0 && index < maxStrings) {
      int commaIndex = dataFromUnity.indexOf(',');
      if (commaIndex == -1) {
        // Si no hay más comas, almacena el resto del string
        stringArray[index] = dataFromUnity;
        break;
      } else {
        // Almacena el substring antes de la coma
        stringArray[index] = dataFromUnity.substring(0, commaIndex);
        dataFromUnity = dataFromUnity.substring(commaIndex + 1); // Resto del string
      }
      index++;
    }
  }
  int id = stringArray[0].toInt();
  const int arraySize = sizeof(stringArray) / sizeof(stringArray[0]);  // Tamaño del array
  for (int i = 0; i < arraySize - 1; i++) {
    stringArray[i] = stringArray[i + 1];
  }
  stringArray[arraySize- 1] = "";
      

}
