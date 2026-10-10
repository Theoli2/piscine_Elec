#include <avr/io.h>

int main() {
	// We set our pins for our leds on output
	DDRB |= (1 << PB1);
	
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);
	ICR1 = 62500 - 1;
	OCR1A = 6250 - 1;
	while (1) {}
}
