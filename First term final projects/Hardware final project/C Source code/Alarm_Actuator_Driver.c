#include "Alarm_Actuator_Driver.h"
#include "state.h"
#include "driver.h"

/* Variables */

/* State pointer (pointer to function) */
void (*ALARM_ACTUATOR_DRIVER_state)();

/* Module Init */
void Alarm_Actuator_Driver_init (void)	
{	
	/* Driver Init */	
}

/* Input signal(s) implementation */
void Start_Alarm (void)
{	
	/* Set the next state */
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_alarm_on);	   
}

void Stop_Alarm (void)
{	
	/* Set the next state */
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_alarm_off);      
}

/* State(s) implementation */
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_off)
{
	/* State name */
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_alarm_off;	
	/* State action */
	/* Send signal to turn off the alarm */
	Set_Alarm_actuator(1);	
	/* Set next state */
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_waiting);	
}

STATE_define(ALARM_ACTUATOR_DRIVER_alarm_on)
{
	/* State name */
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_alarm_on;	
	/* State action */
	/* Send signal to turn on the alarm */
	Set_Alarm_actuator(0);	
	/* Set next state */
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_waiting);	
}

STATE_define(ALARM_ACTUATOR_DRIVER_waiting)
{
	/* State name */
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_waiting;	
	/* State action: No action */
}
