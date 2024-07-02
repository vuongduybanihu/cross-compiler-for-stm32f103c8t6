
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m3 -mthumb --specs=nano.specs
CPPFLAGS=-DSTM32F103xB \
				 -Ispl \
				 -Iinc

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE) -Wl,--gc-sections -u _printf_float -lc  -lm -lgcc

BINARY = blink.elf

PROGRAMMER = openocd
PROGRAMMER_FLAGS = -f interface/stlink.cfg -f target/stm32f1x.cfg

all: $(BINARY)

$(BINARY): main.o startup.o  syscalls.o delay.o ds18b20.o gpio.o lcd16x2.o onewire.o system_stm32f10x.o stm32f10x_gpio.o stm32f10x_rcc.o  
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(BINARY)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

system_stm32f10x.o: spl/system_stm32f10x.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

syscalls.o: syscalls.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

stm32f10x_gpio.o: spl/stm32f10x_gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

stm32f10x_rcc.o: spl/stm32f10x_rcc.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

delay.o: src/delay.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

ds18b20.o: src/ds18b20.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

gpio.o: src/gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

lcd16x2.o: src/lcd16x2.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

onewire.o: src/onewire.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

.PHONY: clean
clean:
	rm -f *.o *.elf

flash: $(BINARY)
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program $(BINARY) verify reset exit"

