#include "US.h"
#include "state.h"

/* Module variables */
int US_distance = 0;

/* State Pointer (pointer to function) */
void (*US_state)();

int US_Get_distance_random(int l, int r, int count); 

void US_init ()
{
	printf("US_init\n");
}

STATE_define(US_busy)
{
	US_state_id = US_busy;
	US_distance = US_Get_distance_random(45, 55, 1);
	printf("US_busy state: distance = %d\n", US_distance);
	US_Get_Distance (US_distance);
	US_state = STATE(US_busy);
}

int US_Get_distance_random(int l, int r, int count)
{
	/* this code will generate random number in range l and r */
	int i;
	int rand_num;
	for (i = 0; i < count; i++)	{	rand_num = (rand() % (r - l + 1)) + l;	}
	return rand_num;
}
