#include <avr/io.h>

int main(void)
{
	//change the first bit of the DDRB register to set the PB0 pin to output mode
	DDRB |= (0 << PB0);

	//we say that now we will output high on the PB0 pin
	PORTB |= (1 << PB0);

	//infinite loop
	while(1)
	{
	}
}