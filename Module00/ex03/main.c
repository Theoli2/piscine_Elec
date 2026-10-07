#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//change the first bit of the DDRB register to set the PB0 pin to output mode
	DDRB |= (1 << PB0);

	//we change the bit that correspond to the pin of our button (SW1) to 0 to put it in input mode
	DDRD &= ~(1 << PD2);

	//we enable the chip pull-up so that when the button isnt pressed it outputs high (there is already external pull-up resistors so it isnt strictly needed but good practice)
	PORTD |= (1 << PD2);

	//we clear our PB0 pin (ie it outputs low)
	PORTB &= ~(1 << PB0);

	//infinite loop
	while(1)
	{
		//if our button is pressed
		if(!(PIND & (1 << PD2)))
		{
			// we debounce the press (during first ms of a state change of a button the pin can have unpredictable values we mitigate this by waiting)
			_delay_ms(5);
			//we toggle PB0 pin in PORTB (we change its state)
			PORTB ^= (1 << PB0);
			//we idle while waiting for our button to release
			while (!(PIND & (1 << PD2)))
			{
			}
			// we debounce the release
			_delay_ms(5);
		}
	}
}