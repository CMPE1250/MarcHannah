

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
    PT1AD1 |=led;
}



int SWL_Pushed (SWL_SwitchPos pos)
{
    return PT1AD1 & pos;
}




void SWL_OFF (SWL_LEDColour led)
{
PT1AD1&= ~(led);
}


void SWL_TOG (SWL_LEDColour led)
{PT1AD1^= led;}



int GetCount(void)
{
  unsigned char total_LEDS;




  if (SWL_Pushed(SWL_RED)>0){total_LEDS++;}
  if (SWL_Pushed(SWL_GREEN)>0){total_LEDS++;}
  if (SWL_Pushed(SWL_YELLOW)>0){total_LEDS++;}

  return total_LEDS;
}
    

void countUp(long countNumber)
{
    long counter=0;
    while(counter < countNumber){counter++;}
}
//int SWL_PushedDeb (SWL_SwitchPos pos);


int checkSwitchTransition(int *oldState,SWL_SwitchPos button)
{
    int currentState = SWL_Pushed(button);
   
    if ((currentState != *oldState) && currentState)
    {
        *oldState = currentState; 
        return 1;
    }

    *oldState = currentState; 
    return 0; 
}