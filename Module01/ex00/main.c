#include <avr/io.h>

int main() {
	// We set our pins for our leds on output
	DDRB |= (1 << PB1);

	const uint8_t LOOP_CYCLE = 34;
	const uint8_t FREQ = 2;
	const uint32_t TRIGGER = F_CPU / LOOP_CYCLE / FREQ;
	
	uint32_t i = 0;
	while (1) {
		++i;
		PORTB ^= (i == TRIGGER) << PB1;
		i *= (i != TRIGGER);
	}
}
