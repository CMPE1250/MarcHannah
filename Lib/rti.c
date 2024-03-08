#include "derivative.h"
#include <hidef.h>
#include "rti.h"

extern volatile unsigned long rtiMasterCount;

void RTI_Init(void)
{
    RTICTL=0;
    CRGFLG = CRGFLG_RTIF_MASK;
    RTICTL = 0b10001111;
}

void RTI_Delay_ms(unsigned int ms)
{

    rtiMasterCount = 0;

    RTI_Init();

    while (rtiMasterCount < ms)
    {
        if (CRGFLG_RTIF) // RTI period over?
        {
            CRGFLG = CRGFLG_RTIF_MASK;
            rtiMasterCount++;
        }
    }

RTICTL=0;

}
