const int maxStrings = 10; // Máximo número de elementos en el array
struct Result {
  int id;
  String msgArray[maxStrings];
};

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

Result prueba;

Result string2array(String string2convert) {
  Result res;
  int index = 0;

  // Divide the string by commas and store in the array
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

  // Convert the first element to int and store in id
  res.id = res.msgArray[0].toInt();

  // Shift elements left after extracting id
  for (int i = 0; i < index - 1; i++) {
    res.msgArray[i] = res.msgArray[i + 1];
  }
  //res.msgArray[index - 1] = "";  // Clear last position if shifted

  return res;
}

void mostrarSeleccion2Personajes(Result mensaje) {
  tft.fillScreen(BLACK);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(130, 60);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(5);
  tft.print("Player 1");

  tft.setCursor(180, 100);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.print(mensaje.msgArray[0]);  // Mostrar el personaje que selecciona Player 1

  // Configuración para Player 2 en la mitad inferior de la pantalla
  tft.setCursor(130, 200);  // Posicionar en la mitad inferior de la pantalla
  tft.setTextSize(5);
  tft.print("Player 2");

  tft.setCursor(180, 240);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.print(mensaje.msgArray[1]);  // Mostrar el personaje que selecciona Player 2
}

void mostrarSeleccion1Personajes(Result mensaje) {
  tft.fillScreen(BLACK);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(90, 85);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(7);
  tft.print("Player 1");

  tft.setCursor(140, 200);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(6);
  tft.print(mensaje.msgArray[0]);  // Mostrar el personaje que selecciona Player 1
}

void mostrarPuntuacionesTennis(Result mensaje) {
  tft.fillScreen(BLACK);

  // Check if at least 4 elements are available
  if (mensaje.msgArray[0] != "" && mensaje.msgArray[1] != "" &&
      mensaje.msgArray[2] != "" && mensaje.msgArray[3] != "") {
    
    // Display Player 1 information
    tft.setTextSize(5);
    tft.setCursor(125, 40);
    tft.print("Player 1");
    tft.setTextSize(3);
    tft.setCursor(80, 110);
    tft.print("Games: " + mensaje.msgArray[0]);
    tft.setCursor(260, 110);
    tft.print("Points: " + mensaje.msgArray[1]);

    // Display Player 2 information
    tft.setTextSize(5);
    tft.setCursor(125, 180);
    tft.print("Player 2");
    tft.setTextSize(3);
    tft.setCursor(80, 250);
    tft.print("Games: " + mensaje.msgArray[2]);
    tft.setCursor(260, 250);
    tft.print("Points: " + mensaje.msgArray[3]);
  } else {
    tft.println("Error: Insufficient data for displaying tennis scores.");
  }
}

void tilesAvanzadas2players(Result mensaje) {
  tft.fillScreen(BLACK);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(95, 40);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(6);
  tft.print("Player 1");

  tft.setCursor(120, 100);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.print("Score: " + mensaje.msgArray[0]);

  // Configuración para Player 2 en la mitad inferior de la pantalla
  tft.setCursor(95, 190);  // Posicionar en la mitad inferior de la pantalla
  tft.setTextSize(6);
  tft.print("Player 2");

  tft.setCursor(120, 250);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.print("Score: " + mensaje.msgArray[1]);  // Mostrar el personaje que selecciona Player 2
}
void tilesAvanzadas1players(Result mensaje) {
  tft.fillScreen(BLACK);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(65, 85);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(8);
  tft.print("Player 1");

  tft.setCursor(100, 200);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(5);
  tft.print("Score: " + mensaje.msgArray[0]);  // Mostrar el personaje que selecciona Player 1
}

void dmgFighter(Result mensaje){
  tft.fillScreen(BLACK);

  // Configuración para Player 1 en la mitad superior de la pantalla
  tft.setCursor(95, 40);  // Posicionar en la mitad superior de la pantalla
  tft.setTextSize(6);
  tft.print("Player 1");

  tft.setCursor(80, 100);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.println("Dano hecho: " + mensaje.msgArray[0]);
  tft.print("");

  // Configuración para Player 2 en la mitad inferior de la pantalla
  tft.setCursor(95, 190);  // Posicionar en la mitad inferior de la pantalla
  tft.setTextSize(6);
  tft.print("Player 2");

  tft.setCursor(80, 250);  // Un poco más abajo para el nombre del personaje
  tft.setTextSize(4);
  tft.println("Dano hecho: " + mensaje.msgArray[1]);  // Mostrar el personaje que selecciona Player 2
  tft.print("");
}


void setup() {
  Serial.begin(9600);
  
  uint16_t ID = tft.readID(); 
  tft.begin(ID);

  tft.setRotation(1);  
  tft.setTextColor(GREEN); 
  tft.setCursor(40, 40);

}

void loop() {

 /*
  prueba.msgArray[0] = "3";
  prueba.msgArray[1] = "30";
  
  prueba.msgArray[2] = "5";
  prueba.msgArray[3] = "45";

  mostrarPuntuacionesTennis(prueba);

  delay(1000);

  prueba.msgArray[0] = "peron";

  mostrarSeleccion1Personajes(prueba);

  
  delay(1000);

  prueba.msgArray[0] = "leo";
  prueba.msgArray[1] = "fierro";

  mostrarSeleccion2Personajes(prueba);

  delay(1000);

  prueba.msgArray[0]=200;
  prueba.msgArray[1]=220;
  tilesAvanzadas1players(prueba);
  
  delay(1000);

  prueba.msgArray[0]=2000;
  prueba.msgArray[1]=2100;
  tilesAvanzadas2players(prueba);

  delay(1000);

  
  prueba.msgArray[0]=200;
  prueba.msgArray[1]=220;
  tilesAvanzadas1players(prueba);

  delay(1000);

  */
  
    if (Serial.available()) {
      String string2convert = Serial.readStringUntil('\n');
      Result mensaje = string2array(string2convert);
      if (mensaje.id == 1){
        mostrarSeleccion2Personajes(mensaje);
      }
      if (mensaje.id == 2){
        mostrarSeleccion1Personajes(mensaje);
      }
      if (mensaje.id == 3){
        mostrarPuntuacionesTennis(mensaje);
      }
      if(mensaje.id == 4){
        tilesAvanzadas2players(mensaje);
      }
      if (mensaje.id == 5){
        tilesAvanzadas1players(mensaje);
      }
      if (mensaje.id == 6){
        dmgFighter(mensaje);
      }
        
    }
}
