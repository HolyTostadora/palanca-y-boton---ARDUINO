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


struct Result {
  int id;
  String msgArray[maxStrings];
};

Result string2array(String string2convert) {
  Result res;
  int index = 0;

  // Divide el string por comas y almacena en el array
  while (string2convert.length() > 0 && index < maxStrings) {
    int commaIndex = string2convert.indexOf(',');
    if (commaIndex == -1) {
      res.msgArray[index] = string2convert;
      break;
    } else {
      res.msgArray[index] = string2convert.substring(0, commaIndex);
      string2convert = string2convert.substring(commaIndex + 1);
    }
    index++;
  }

  // Convertir el primer elemento a int y almacenarlo en id
  res.id = res.msgArray[0].toInt();

  // Eliminar el primer elemento desplazando los demás
  const int arraySize = index;
  for (int i = 0; i < arraySize - 1; i++) {
    res.msgArray[i] = res.msgArray[i + 1];
  }
  res.msgArray[arraySize - 1] = "";  // Limpiar la última posición

  return res;
}

void mostrarSeleccionPersonajes(String msgArray[]) {
  tft.fillScreen(WHITE);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(40, 60);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(3);
  tft.print("Player 1");
  
  tft.setCursor(40, 100);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(2);
  tft.print(msgArray[0]);  // Mostrar el personaje que selecciona Player 1

  // Configuración para Player 2 en la mitad inferior de la pantalla
  tft.setCursor(40, 180);  // Posicionar en la mitad inferior de la pantalla
  tft.setTextSize(3);
  tft.print("Player 2");
  
  tft.setCursor(40, 220);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(2);
  tft.print(msgArray[1]);  // Mostrar el personaje que selecciona Player 2
}

void mostrarPuntuaciones(String msgArray[]) {
  tft.fillScreen(WHITE);

  // Configuración para Player 1
  tft.setTextSize(3);  // Tamaño de texto más grande para Player 1
  tft.setCursor(40, 40);  // Posicionar en la parte superior
  tft.print("Player 1");
  
  tft.setTextSize(2);  // Tamaño de texto más pequeño para los sets
  tft.setCursor(40, 80);  // Un poco más abajo para los sets
  tft.print("Sets: " + msgArray[0]);  // Mostrar los sets de Player 1

  // Línea divisoria para los game sets de Player 1
  tft.drawLine(10, 100, 310, 100, BLACK);  // Línea divisoria para Player 1

  // Mostrar game sets y puntos de Player 1 en la misma línea
  tft.setCursor(40, 120);  // Un poco más abajo
  tft.print("Games: " + msgArray[1]);  // Mostrar los games de Player 1
  tft.setCursor(150, 120);  // Espacio para los puntos
  tft.print("Points: " + msgArray[2]);  // Mostrar los puntos de Player 1

  // Línea divisoria entre Player 1 y Player 2
  tft.drawLine(10, 140, 310, 140, BLACK);  // Línea divisoria entre Player 1 y Player 2

  // Configuración para Player 2
  tft.setTextSize(3);  // Tamaño de texto más grande para Player 2
  tft.setCursor(40, 160);  // Posicionar en la parte inferior del Player 1
  tft.print("Player 2");
  
  tft.setTextSize(2);  // Tamaño de texto más pequeño para los sets
  tft.setCursor(40, 200);  // Un poco más abajo para los sets
  tft.print("Sets: " + msgArray[3]);  // Mostrar los sets de Player 2

  // Línea divisoria para los game sets de Player 2
  tft.drawLine(10, 220, 310, 220, BLACK);  // Línea divisoria para Player 2

  // Mostrar game sets y puntos de Player 2 en la misma línea
  tft.setCursor(40, 240);  // Un poco más abajo
  tft.print("Games: " + msgArray[4]);  // Mostrar los games de Player 2
  tft.setCursor(150, 240);  // Espacio para los puntos
  tft.print("Points: " + msgArray[5]);  // Mostrar los puntos de Player 2
}

void setup() {
  Serial.begin(9600);
  
  uint16_t ID = tft.readID(); 
  tft.begin(ID);

  tft.setRotation(1);  
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);  
}

void loop() {
  if (Serial.available()) {
      String string2convert = Serial.readStringUntil('\n');
      Result mensaje = string2array(string2convert);

  }
}
