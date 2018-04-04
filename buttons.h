#ifndef buttons_included
#define buttons_included 

#define BT1 BIT0
#define BT2 BIT1
#define BT3 BIT2
#define BUTTONS (BT1 | BT2 | BT3)

void buttonInit();
void buttonInterruptHandler();

extern char button1SC, button2SC, button3SC, button1SD, button2SD, button3SD;

#endif
