#include <avr/io.h>

int main(void)
{
	// Change the first bit of the DDRB register to set the PB0 pin to output mode
	DDRB |= (0 << PB0);

	// We say that now we will output high on the PB0 pin
	PORTB |= (1 << PB0);

	// Infinite loop
	while(1)
	{
	}
}