#include <Keyboard.h>

#define ABAJO 3
#define ARRIBA 2
#define DERECHA 5
#define IZQUIERDA 4

#define BTN_R 7


/*
*/

void setup()
{
  pinMode(ABAJO,INPUT_PULLUP);
  pinMode(ARRIBA,INPUT_PULLUP);
  pinMode(DERECHA,INPUT_PULLUP);
  pinMode(IZQUIERDA,INPUT_PULLUP);  
  pinMode(BTN_R,INPUT_PULLUP);

  Keyboard.begin();

}

void loop()
{

  BTN_on_click(ARRIBA,'w');
  BTN_on_click(ABAJO,'s');
  BTN_on_click(DERECHA,'d');
  BTN_on_click(IZQUIERDA,'a');

  BTN_on_click(BTN_R,'r');

}

void BTN_on_click(int direcc, char tecla)
{

  if(digitalRead(direcc)==false)
  {
    Keyboard.press(tecla);
  }
  else
  {
    Keyboard.release(tecla);
  }
    
}
