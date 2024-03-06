

#include "derivative.h"
#include <hidef.h>  
#include "rti.h"

extern volatile unsigned long rtiMasterCount;


void RTI_Init(void){RTICTL = 0b10010111;}

void RTI_Delay_ms(unsigned int ms)
{
    if (ms==8){RTICTL=0b10010111; }
    
     if (ms==12){RTICTL=0b10010111; }
     if (ms==10){RTICTL=0b10010111; }
    if (ms==1){RTICTL=0b10010111; }
        if (ms==9){RTICTL=0b10010111; }
    }