/* US.h */
#ifndef	US_H_
#define US_H_

#include "state.h"

/* Define states */
enum 
{
	US_busy
} US_state_id;

/* Declare states functions US */
void US_init();
STATE_define(US_busy);

/* State Pointer (pointer to function) */
extern void (*US_state)();

#endif
