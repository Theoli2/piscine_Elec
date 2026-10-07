#include <avr/io.h>
#include <util/delay.h>

void update_leds(uint8_t counter)
{
	PORTB = (PORTB & ~0b00010111)           // clear the 4 LED bits
      | (counter & 0b0111)                // bits 0-2 go to PB0-PB2
      | ((counter & 0b1000) << 1);        // bit 3 goes to PB4
}

int main(void)
{
	DDRB |= 0b0010111;

	DDRD &= ~(0b00010100);

	PORTD |= (0b00010100);

	uint8_t counter = 0;

	while(1)
	{
		while ((PIND & (1 << PD2)) && (PIND & (1 << PD4)))
		{}
		_delay_ms(5);

		if (!(PIND & (1 << PD2)))
			counter = (counter + 1) & 0x0F;
		if (!(PIND & (1 << PD4)))
			counter = (counter -1) & 0x0F;
		
		update_leds(counter);
		while (!(PIND & (1 << PD2)) || !(PIND & (1 << PD4)))
    	{}
    	_delay_ms(5);
	}

}