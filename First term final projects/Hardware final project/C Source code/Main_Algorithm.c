#include "Main_Algorithm.h"
#include "state.h"


/* Variables */
int Main_Algorithm_pVal = 0;
int pThreshold = 20;

/* State pointer (pointer to function) */
void (*MAIN_ALGORITHM_state)();

/* Input signal(s) implementation */
void Set_Pressure_Val (int pVal)
{
	Main_Algorithm_pVal = pVal;
	/* Set next state */
	MAIN_ALGORITHM_state = STATE(MAIN_ALGORITHM_high_pressure_detect);
}

/* State(s) implementation */
STATE_define(MAIN_ALGORITHM_high_pressure_detect)
{
	/* State name */
	MAIN_ALGORITHM_state_id = MAIN_ALGORITHM_high_pressure_detect;
	/* State action */
	if      (Main_Algorithm_pVal <= pThreshold) { } 
	else if (Main_Algorithm_pVal >  pThreshold) { High_Pressure_Detected(); }
}


