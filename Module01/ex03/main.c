#include <avr/io.h>
#include <util/delay.h>


int main() {
	// We set our pins for our leds on output
	DDRB |= (1 << PB1);
	// We set our pins for our buttons to input
	DDRD &= ~(0b00010100);
	// We enable the chip pull-up for our 2 buttons
	PORTD |= (0b00010100);
	ICR1 = 62500 - 1;
	uint8_t ratio = 10;
	OCR1A =  (62500 * ratio) / 100 - 1;

	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);
	while (1) {
		// We wait for either of our buttons to be pressed
		while ((PIND & (1 << PD2)) && (PIND & (1 << PD4)))
		{}
		// We debounce the press
		_delay_ms(5);

		// We check which button has been pressed
		if (!(PIND & (1 << PD2)))
		{
			if (ratio == 100)
				ratio = 10;
			else 
				ratio += 10;
		}
		if (!(PIND & (1 << PD4)))
		{	
			if (ratio == 10)
				ratio = 100;
			else
				ratio -= 10;
		}
		// We actualise the leds display
		OCR1A = (62500 * ratio) / 100 - 1;
		// We wait for each button to be released
		while (!(PIND & (1 << PD2)) || !(PIND & (1 << PD4)))
    	{}
		// We debounce the release
    	_delay_ms(5);
	}
}
