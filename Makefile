xCOMMON_OBJECTS =
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

CC             = msp430-elf-gcc
AS             = msp430-elf-as

all: buzzyToy.elf

buzzyToy.elf: ${COMMON_OBJECTS} p2InterruptHandler.o led.o buttons.o main.o timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: buzzyToy.elf
	mspdebug rf2500 "prog buzzyToy.elf"
clean:
	rm -f *.o *.elf
