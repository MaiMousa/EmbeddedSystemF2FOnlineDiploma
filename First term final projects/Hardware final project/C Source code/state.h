#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

/* Automatic state function generated */
#define STATE_define(_statefun_)  void ST_##_statefun_()
#define STATE(_statefun_) ST_##_statefun_

/* States connection */
void Set_Pressure_Val (int pVal);
void High_Pressure_Detected (void);
void Start_Alarm (void);
void Stop_Alarm (void);

#endif
