#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
//#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

static int faceID=1;
void wdt_c_handler()
{
  static int secCount = 0;
  static char blink_count = 0;
  static char blink_light = 0;
  static char change_dim  = 0;

  if (++blink_count == 75) {
    state_advance();
    blink_count = 0;
  }

  if(++blink_light==1){
    dim25();
    dim75();
    blink_light = 0;
  }

  if(++change_dim==125){
    dim_machine();
    change_dim = 0;
  }

  secCount ++;
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    
    if(faceID){
      faceID=0;
    }else{
      

      faceID=1;
    }
    lcd_state();
    redrawScreen = 1;
  }
}
  

void main()
{
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {                   /* forever */
    if(redrawScreen){
      redrawScreen = 0;
      mainMenu();
    }
    green_on=0;
    led_update();/* green off */
    or_sr(0x10);		/**< CPU OFF */
    green_on=1;
    led_update();/* green on */
  }
}

    
    



