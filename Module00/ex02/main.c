#include <avr/io.h>

int main(void)
{
	//change the first bit of the DDRB register to set the PB0 pin to output mode
	DDRB |= (1 << PB0);

	//we change the bit that correspond to the pin of our button (SW1) to 0 to put it in input mode
	DDRD &= ~(1 << PD2);

	//we set our PB0 pin to low
	PORTB &= ~(1 << PB0);

	//infinite loop
	while(1)
	{
		//if the real value of PIND and 00000100 is equal to 0 (ie the button is pressed)
		if (!(PIND & (1 << PD2)))
		{
			//we say that now we will output high on the PB0 pin
			PORTB |= (1 << PB0);
		}
		else
		{
			//we say that now we will output low on the PB0 pin
			PORTB &= ~(1 << PB0);
		}
	}
}