#include "Pressure_Sensor_Driver.h"
#include "state.h"
#include "driver.h"

/* Variables */
int pSensor_Driver_pVal = 0;

/* State pointer (pointer to function) */
void (*PRESSURE_SENSOR_DRIVER_state)();

/* Module Init */
void Pressure_Sensor_Driver_init (void)	
{	
	/* Driver Init */ 
}

/* State(s) implementation */
STATE_define(PRESSURE_SENSOR_DRIVER_reading)
{
	/* State name */
	PRESSURE_SENSOR_DRIVER_state_id = PRESSURE_SENSOR_DRIVER_reading;
	/* State action */
	/* 1. Get pressure reading from pressure sensor */
	pSensor_Driver_pVal = getPressureVal();
	/* 2. Send pressure sensor reading to the main algorithm */
	Set_Pressure_Val (pSensor_Driver_pVal);
	/* 3. Set pressure sensor pulling timer for 100 ms */
	Delay(100);
	/* Set next state */
	PRESSURE_SENSOR_DRIVER_state = STATE(PRESSURE_SENSOR_DRIVER_waiting);
}

STATE_define(PRESSURE_SENSOR_DRIVER_waiting)
{
	/* State name */
	PRESSURE_SENSOR_DRIVER_state_id = PRESSURE_SENSOR_DRIVER_waiting;
	/* State action: No action */
	/* Set next state */
	PRESSURE_SENSOR_DRIVER_state = STATE(PRESSURE_SENSOR_DRIVER_reading);	
}


