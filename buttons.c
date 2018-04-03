#include <msp430.h>
#include "buttons.h"
#include "led.h"

char button1SC, button2SC, button3SC;

void buttonInit() {
  P2REN |= BUTTONS;
  P2IE = BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  buttonUpdateIS();
}

static char buttonUpdateIS() { //update interrupt sense
  char p2val = P1IN;
  P2IES |= (p2val & BUTTONS);
  P2IES &| (p2val | ~BUTTONS);
  return p2val;
}

void buttonInterruptHandler() {
  char p2val = buttonUpdateIS();
  if(p2val & BT1) {
    buttonSC = 1;
    ledUpdate();
  }
  if(p2val & BT2) {
  }
  if(p2val & BT3) {
  }
