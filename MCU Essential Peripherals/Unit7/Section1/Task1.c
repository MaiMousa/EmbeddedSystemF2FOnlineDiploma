/* ATMEGA32 MCU */
/* Task 1: turn on leds on PD5, PD6, PD7 sequentially then turn them off in reverse order */
 #include "MemMap.h"
 #include "Utils.h"
 #define F_CPU 8000000UL
 #include <util/delay.h>
 
 static char pattern[] = {0b000, 0b001, 0b011, 0b111, 0b011, 0b001, 0b000};
 	
 int main(void)
 {   
 	unsigned int i;
 	/* Configure portD pins 5, 6, 7 as output */
 	DDRD |= (0b111 << 5);
 	
     while (1) 
     {
 		for(i = 0; i < 7; i++)
 		{
 			PORTD = (pattern[i] << 5);
 			_delay_ms(500);
 		}
     }
