#ifndef buttons_included
#define buttons_included 

#define BT1 BIT0
#define BT2 BIT1
#define BT3 BIT2
#define BT4 BIT3
#define BUTTONS (BIT0 | BIT1 | BIT2 | BIT3)

void buttonInit();
void buttonInterruptHandler();

extern char buttonStateDown, buttonStateChanged;

#endif
