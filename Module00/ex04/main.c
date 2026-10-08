#include <avr/io.h>
#include <util/delay.h>

// This function is used to display counter on the leds
void update_leds(uint8_t counter)
{
	// We clear the bits of the leds pin (PB0, PB1, PB2 and PB4)
	PORTB = (PORTB & ~0b00010111);
	// In parenthesis we do a mask that we will apply to PORTB, this mask is constitued of the first 3 bits of counter
    PORTB |= (counter & 0b0111);               
	// In parenthesis we do a mask that we will apply to PORTB, this mask is constitued of the 4th bit of counter that we bitshift to put it in the 5th position of PORTB
	PORTB |= ((counter & 0b1000) << 1);
}

int main(void)
{
	// We set our pins for our leds on output
	DDRB |= 0b00010111;
	// We set our pins for our buttons to input
	DDRD &= ~(0b00010100);
	// We enable the chip pull-up for our 2 buttons
	PORTD |= (0b00010100);

	uint8_t counter = 0;

	while(1)
	{
		// We wait for either of our buttons to be pressed
		while ((PIND & (1 << PD2)) && (PIND & (1 << PD4)))
		{}
		// We debounce the press
		_delay_ms(5);

		// We check which button has been pressed
		if (!(PIND & (1 << PD2)))
			counter = (counter + 1) & 0b00001111; // We increment the counter while only keeping the first 4 bits of it (it enables us to not worry about the counter overflowing, it will circle back to 0 when going over 15)
		if (!(PIND & (1 << PD4)))
			counter = (counter -1) & 0b00001111;
		// We actualise the leds display
		update_leds(counter);
		// We wait for each button to be released
		while (!(PIND & (1 << PD2)) || !(PIND & (1 << PD4)))
    	{}
		// We debounce the release
    	_delay_ms(5);
	}

}