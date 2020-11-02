#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();			/* always changes an led */
}

void toggle_green()
{
  static char state1=0;
  switch(state1)
    {
  case 0:
    green_on=1;
    state1=1;
    break;
  case 1:
    green_on=0;
    state1=0;
    break;
  }
  led_changed = 1;
  led_update();
}

void state_advance_buttons(){
  //void state_advance(){
   switch(button){
  case 0:
    toggle_red();
    break;
  case 1:
    toggle_green();
 break;
  case 2:
    toggle_red();
    break;
  case 3:
    toggle_green();
    break;
  }
}
