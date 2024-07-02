#ifndef __SYSTICK_H__
#define __SYSTICK_H__



#include "stdint.h"

#define SYSTICK_BASE_ADDRESS   (uint32_t)0xE000E010

typedef struct
{
    uint32_t CTRL;
    uint32_t LOAD;
    uint32_t VAL;
    uint32_t CALIB;

} SYSTICK_t;


void Delay_Init (unsigned char _CLK);
void Delay_ms (unsigned int _vrui_Time);
void Delay_us (unsigned long _vrui_Time);



#endif

