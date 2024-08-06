#include <Keyboard.h>

#define ABAJO1 2
#define ARRIBA1 3
#define DERECHA1 5
#define IZQUIERDA1 4

#define ABAJO2 9
#define ARRIBA2 8
#define DERECHA2 11
#define IZQUIERDA2 10

#define BTN_R 7


/*
*/

void setup()
{
  pinMode(ABAJO1,INPUT_PULLUP);
  pinMode(ARRIBA1,INPUT_PULLUP);
  pinMode(DERECHA1,INPUT_PULLUP);
  pinMode(IZQUIERDA1,INPUT_PULLUP);  
  pinMode(ABAJO2,INPUT_PULLUP);
  pinMode(ARRIBA2,INPUT_PULLUP);
  pinMode(DERECHA2,INPUT_PULLUP);
  pinMode(IZQUIERDA2,INPUT_PULLUP);  
  
  pinMode(BTN_R,INPUT_PULLUP);

  Keyboard.begin();

}

void loop()
{

  BTN_on_click(ARRIBA1,'w');
  BTN_on_click(ABAJO1,'s');
  BTN_on_click(DERECHA1,'d');
  BTN_on_click(IZQUIERDA1,'a');

  BTN_on_click(ARRIBA2,KEY_UP_ARROW);
  BTN_on_click(ABAJO2,KEY_DOWN_ARROW);
  BTN_on_click(DERECHA2,KEY_RIGHT_ARROW);
  BTN_on_click(IZQUIERDA2,KEY_LEFT_ARROW);

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
