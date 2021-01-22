/* CA.c */
#include "CA.h"
#include "state.h"

/* Module variables */
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

/* State Pointer (pointer to function) */
void (*CA_state)();

void US_Get_Distance (int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ------distance = %d-----> CA\n", CA_distance);
}

STATE_define(CA_waiting)
{
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance = %d  speed = %d\n", CA_distance, CA_speed);
	CA_speed = 0;
	DC_Motor_Set(CA_speed);
}

STATE_define(CA_driving)
{
	CA_state_id = CA_driving;
	printf("CA_driving state: distance = %d  speed = %d\n", CA_distance, CA_speed);
	CA_speed = 30;	     
	DC_Motor_Set(CA_speed);
}


