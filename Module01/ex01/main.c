#include <avr/io.h>

int main() {
	// We set our pins for our leds on output
	DDRB |= (1 << PB1);

	TCCR1A |= (1 << COM1A0);
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	OCR1A = 31250 - 1;
	while (1) {}
}
