COMMON_OBJECTS =
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

CC             = msp430-elf-gcc
AS             = msp430-elf-as

all: button.elf

buttons.elf: ${COMMON_OBJECTS} p2InterruptHandler.o led.o buttons.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	mspdebug rf2500 "prog button.elf"
clean:
	rm -f *.o *.elf
