/*
 * utils.h
 *
 * Created: 4/22/2021 6:20:12 PM
 *  Author: PC
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit) (reg|=(1<<bit))
#define ResetBit(reg,bit) (reg&=~(1<<bit))
#define ToggleBit(reg,bit) (reg^=(1<<bit))
#define GetBit(reg,bit)  ((reg&(1<<bit))>>bit) // ((reg>>bit)&1)

#endif /* UTILS_H_ */