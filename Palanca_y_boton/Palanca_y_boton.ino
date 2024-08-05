#include <Keyboard.h>

#define ABAJO1 3
#define ARRIBA1 2
#define DERECHA1 5
#define IZQUIERDA1 4

#define BTN_R 7


/*
*/

void setup()
{
  pinMode(ABAJO1,INPUT_PULLUP);
  pinMode(ARRIBA1,INPUT_PULLUP);
  pinMode(DERECHA1,INPUT_PULLUP);
  pinMode(IZQUIERDA1,INPUT_PULLUP);  
  pinMode(BTN_R,INPUT_PULLUP);

  Keyboard.begin();

}

void loop()
{

  BTN_on_click(ARRIBA1,'w');
  BTN_on_click(ABAJO1,'s');
  BTN_on_click(DERECHA1,'d');
  BTN_on_click(IZQUIERDA1,'a');

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
