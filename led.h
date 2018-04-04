#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void ledInit();
void ledUpdate();

extern unsigned char ledsChanged, greenLedState, redLedState;
extern int count;

#endif 
