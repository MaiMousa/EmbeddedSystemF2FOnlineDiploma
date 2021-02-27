#include "Alarm_Monitor.h"
#include "state.h"
#include "driver.h"

/* Variables */
int Alarm_Period = 60;

/* State pointer (pointer to function) */
void (*ALARM_MONITOR_state)();

/* Input signal(s) implementation */
void High_Pressure_Detected (void)
{	
	/* Set the next state */
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_alarm_on);     
}

/* State(s) implementation */
STATE_define(ALARM_MONITOR_alarm_off)
{   
	/* State name */
	ALARM_MONITOR_state_id = ALARM_MONITOR_alarm_off;  	
	/* State action: No action */  
}

STATE_define(ALARM_MONITOR_alarm_on)
{
	/* State name */
	ALARM_MONITOR_state_id = ALARM_MONITOR_alarm_on;
	/* State action */
	/* 1. Send start alarm signal to Alarm_Actuator_Driver */
	Start_Alarm ();
	/* 2. Set a timer with the required alarm period (60 Sec) */
	Delay(Alarm_Period);
	/* Set next state */
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_waiting);	
}
STATE_define(ALARM_MONITOR_waiting)
{
	/* State name */
	ALARM_MONITOR_state_id = ALARM_MONITOR_waiting;
	/* State action */
	/* 1. Send stop alarm signal to Alarm_Actuator_Driver */
	Stop_Alarm ();
	/* Set next state */
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_alarm_off);
}


