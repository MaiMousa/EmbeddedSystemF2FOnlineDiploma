/* DC.h */
#ifndef	DC_H_
#define DC_H_

#include "state.h"

/* Define states */
enum 
{
	DC_idle,
	DC_busy
} DC_state_id;

/* Declare states functions DC */
void DC_init ();
STATE_define(DC_idle);
STATE_define(DC_busy);

/* State Pointer (pointer to function) */
extern void (*DC_state)();

#endif
