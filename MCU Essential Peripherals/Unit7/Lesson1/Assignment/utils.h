
#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit) (reg|=(1<<bit))
#define ResetBit(reg,bit) (reg&=~(1<<bit))
#define ToggleBit(reg,bit) (reg^=(1<<bit))
#define GetBit(reg,bit)  ((reg&(1<<bit))>>bit) // ((reg>>bit)&1)

#endif /* UTILS_H_ */