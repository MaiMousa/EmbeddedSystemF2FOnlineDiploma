/* ATMEGA32 MCU */
/* Functionality
 * Toggle the LEDs and turn on the buzzer sequentially
 * PD5, PD6, PD7 >> Output (LEDs)
 * PD4 >> Output (Buzzer)
*/
#include <stdint.h>
#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void Delay (uint32_t t)
{
	uint32_t i, j;
	for(i = 0; i <t; i++)
	for(j = 0; j < 1000; j++);
}
static char pattern[] = {0b0000, 0b0010, 0b0100, 0b1000, 0b0001};
int main (void)
{
	unsigned char i ;
	/* Configure PD4, PD5, PD6, PD7 >> Output */
	DDRD |= 0xF0; /* 1111 0000 */

	while(1)
	{
		for(i = 0; i < 5; i++)
		{
			PORTD = (pattern[i] << 4);
			Delay(250);
		}
	}
	return 0;
}
