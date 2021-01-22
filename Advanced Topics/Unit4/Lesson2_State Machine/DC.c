/* DC.c */
#include "DC.h"
#include "state.h"

/* Module variables */
int DC_speed = 0;

/* State Pointer (pointer to function) */
void (*DC_state)();

void DC_init()
{
	printf("DC_init\n");
}

void DC_Motor_Set(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA ------speed = %d-----> DC\n", DC_speed);
}

STATE_define(DC_idle)
{
	DC_state_id = DC_idle;
	printf("DC_idle state: speed = %d\n", DC_speed);
}

STATE_define(DC_busy)
{
	DC_state_id = DC_busy;
	DC_state = STATE(DC_idle);
	printf("DC_busy state: speed = %d\n", DC_speed);	
}


