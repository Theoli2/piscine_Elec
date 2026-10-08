NAME	= main
SRC		= main.c


CC		= avr-gcc
OBJCOPY	= avr-objcopy

MCU		= atmega328p
F_CPU	= 16000000UL
CFLAGS	= -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -O2

PROG	= arduino
PORT	= /dev/ttyUSB0
BAUD	= 115200

all: hex flash

hex: $(NAME).hex

$(NAME).bin: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME).bin

$(NAME).hex: $(NAME).bin
	$(OBJCOPY) -O ihex $(NAME).bin $(NAME).hex

flash: hex
	avrdude -p $(MCU) -c $(PROG) -P $(PORT) -b $(BAUD) -U flash:w:$(NAME).hex:i

clean:
	rm -f $(NAME).bin $(NAME).hex

re: clean all

.PHONY: all hex flash clean re