#include <avr/io.h>
#include <stdbool.h>

#define LED (1 << PB1)

int main() {
	// We set our pins for our leds on output
	DDRB |= LED;

	const uint32_t LOOP_CYCLE = 64;
	const uint32_t FREQ = 2;
	const uint32_t TAC = F_CPU / LOOP_CYCLE / FREQ;
	
	volatile uint32_t i = 0;
	while (true) {
		++i;
		if (i == TAC) {
			PORTB ^= LED;
			i = 0;
		}
	}
}