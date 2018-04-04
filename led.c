#include <msp430.h>
#include "led.h"
#include "buttons.h"

int count;

void ledInit() {
  P1DIR |= LEDS;
}

void ledUpdate() {
  if(button1SC) {
    switch(count) {
    case 0:
      P1OUT |= 0x01;
      count = 1;
      break;
    case 1:
      P1OUT &= ~0x01;
      P1OUT |= 0x40;
      count = 2;
      break;
    default:
      P1OUT &= ~0x40;
      P1OUT &= ~0x01;
      count = 0;
      break;
    }
  }
  button1SC = 0;
}
