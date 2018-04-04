#include <msp430.h>
#include "buttons.h"
#include "led.h"

char button1SC, button2SC, button3SC, button1SD, button2SD, button3SD;

static char buttonUpdateIS() { //update interrupt sense
  char p2val = P2IN;
  P2IES |= (p2val & BUTTONS);
  P2IES &= (p2val | ~BUTTONS);
  return p2val;
}

void buttonInit() {
  P2REN |= BUTTONS;
  P2IE = BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  buttonUpdateIS();
}

void buttonInterruptHandler() {
  char p2val = buttonUpdateIS();
  if(!(p2val & BT1)) {
    button1SC = 1;
    ledUpdate();
  }

}
