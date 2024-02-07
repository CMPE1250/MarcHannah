

#include "derivative.h"
#include <hidef.h>  
#include "SWL_LED.h"











void SWL_Init (void){
    PT1AD1 &= 0x1F;
    DDR1AD1 = 0xE0;
    ATD1DIEN1 |= 0x1F;

}
void SWL_ON (SWL_LEDColour led)
{
    PT1AD1 |=led
}



int SWL_Pushed (SWL_SwitchPos pos)
{
    return PT1AD1 & pos;
}




void SWL_OFF (SWL_LEDColour led)
{
PT1AD1&= ~(led)
}
