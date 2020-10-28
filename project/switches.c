
static char

switch_update_interrupt_sense()

{

  char p1val = P1IN;

  /* update switch interrupt to detect changes from current buttons */

  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */

  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  return p1val;

}
void switch_init()/* setup switch */
{

  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();

  led_update();

}

void switch_interupt ()
{
  switch_change = 1;

  if((p2val & SW1)==0)
    {
      button=0;
    }
  else if((p2val & SW2)==0)
    {
      button=1;
    }
  else if((p2val & SW3)==0)
    {
      button=2;
    }
  else if((p2val & SW4)==0)
    {
      button=3;
    }
  led_update();
}
