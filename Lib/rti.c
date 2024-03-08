

#include "derivative.h"
#include <hidef.h>
#include "rti.h"

extern volatile unsigned long rtiMasterCount;

void RTI_Init(void) { RTICTL = 0b11000111; }

void RTI_Delay_ms(unsigned int ms)
{   
    
    unsigned int count = ms;
    if (ms == 8)
    {
        RTICTL = 0b10111100;
    }

    if (ms == 12)
    {
        RTICTL = 0b11001001;
    }




    if (ms == 10)
    {   
        RTICTL = 0;

        CRGFLG = CRGFLG_RTIF_MASK;

        RTICTL = 0b10001111;

       

        while (count > 0)
        {
            if (CRGFLG_RTIF) // RTI period over?
            {
                CRGFLG = CRGFLG_RTIF_MASK;
            }
            count--;
        }



    }






    if (ms == 1)
    {
        RTICTL = 0b10001111;
    }
    if (ms == 9)
    {
        RTICTL = 0b10111110;
    }
}