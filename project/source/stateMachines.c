#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
char music=0;
char on=0;

void toggle_red()		/* always toggle! */
{
  static char state = 0;
  
  if(!state)
    {
      red_on = 1;
      state = 1;
    }
  else
    {
      red_on = 0;
      state = 0;
     }
  led_changed = 1;
  led_update();			/* always changes an led */
}
void turn_on(){
  red_on      = 1;
  green_on    = 1;
  led_changed = 1;
  on          = 1;
  led_update();
}
void turn_off(){
  red_on      = 0;
  green_on    = 0;
  led_changed = 1;
  on          = 0;
  led_update();
}
void toggle_green()
{
  static char state1=0;
  switch(state1)
    {
  case 0:
    green_on=1;
    state1=1;
    led_update();
    break;
  case 1:
    green_on=0;
    state1=0;
    led_update();
    break;
  }
  led_changed = 1;
  led_update();
}
void dim(){
    int state = 1;
  switch(state){
  case 1:
      turn_off();
      break;
  case 4:
    turn_on();
    break;
  }
  }
}
void state_advance_buttons(){
  //void state_advance(){
   switch(button){
  case 0:
    turn_on();
    break;
  case 1:
    turn_off();
 break;
  case 2:
    dim();
    break;
  case 3:
    if(on)
      music=1;
    else
      music=0;
    break;
  }
}
void state_advance(){
  static int state=-1;
  if(music){
  state++;
  switch(state){
  case 0:  buzzer_set_period(7124); break;
  case 1:  buzzer_set_period(7124); break;
  case 2:  buzzer_set_period(4992); break;
  case 3:  buzzer_set_period(4992); break;
  case 4:  buzzer_set_period(4545); break;
  case 5:  buzzer_set_period(4545); break;
  case 6:  buzzer_set_period(4992); break;
  case 7:  buzzer_set_period(5714); break;
  case 8:  buzzer_set_period(5714); break;
  case 9:  buzzer_set_period(5664); break;
  case 10: buzzer_set_period(5664); break;
  case 11: buzzer_set_period(6660); break;
  case 12: buzzer_set_period(6660); break;
  case 13: buzzer_set_period(7126); break;
  case 14: buzzer_set_period(7126); break;
  case 15: state=0; break;
  }
}
  else{
    buzzer_set_period(0);
  }
}
