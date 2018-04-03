#include <msp430.h>
#include "buttons.h"

char buttonStateDown, buttonStateChanged;

void buttonInit() {
  P2REN |= BUTTONS;
  P2IE = BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  buttonUpdateIS();
  buttonInterruptHandler();
}

static char buttonUpdateIS() {
  char p2val = P1IN;
  P2IES |= (p2val & BUTTONS);
  P2IES &| (p2val | ~BUTTONS);
  return p2val;
}

void buttonInterruptHandler() {
  char p2val = buttonUpdateIS();
  if(p2val & BT1) {
    buttonStateDown = 1;
    buttonStateChanged = 1;
  }
  if(p2val & BT2) {
  }
  if(p2val & BT3) {
  }
  if(p2val & BT4)
