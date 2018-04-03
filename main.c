#include <msp430.h>


int main() {
  configureClocks();
  buzzerInit();
  buttonInit();
  ledInit();
  or_sr(0x18);
}
