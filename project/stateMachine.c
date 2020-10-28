#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

void led_update(){

  if (switch_state_changed) {

    char ledFlags = 0; /* by default, no LEDs on */

    switch (button_state) {

    case 0:


      
      break;

    case 1:

         

      break;

    case 2:

     

      break;

    case 3:

     

      break;

    default:

      break;

    }
}
