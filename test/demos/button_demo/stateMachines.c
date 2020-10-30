#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (red_on) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green1()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

char toggle_green()
{
  static char state1=0;
  switch(green_on)
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
  return 1;
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}

void state_advance_buttons()
{
  char changed=0;
  switch(button){
  case 0:
    changed= toggle_red();
    break;
  case 1:
    changed=toggle_green();
    break;
  case 2:
    changed=toggle_red();
    break;
  case 3:
    changed = toggle_green();
    break;
  default:
    break;
  }
  led_changed=changed;
  led_update();
}


