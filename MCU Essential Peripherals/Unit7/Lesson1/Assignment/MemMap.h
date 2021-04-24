
#ifndef MEMMAP_H_
#define MEMMAP_H_

#include <stdint.h>

#define DDRC    *(volatile uint8_t*)(0x34)
#define PORTC   *(volatile uint8_t*)(0x35)
#define PINC    *(volatile uint8_t*)(0x33)
#define DDRD    *(volatile uint8_t*)(0x31)
#define PORTD   *(volatile uint8_t*)(0x32)
#define PIND    *(volatile uint8_t*)(0x30)

#endif /* MEMMAP_H_ */