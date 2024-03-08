#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "../../Lib/SWL_LED.h"
#include "../../Lib/rti.h"

void main(void)
{
  // main entry point
  _DISABLE_COP();

  SWL_Init();
  RTI_Init();
  for (;;)
  {
    if (SWL_Pushed(SWL_ANY) == 0)
    {
      RTI_Delay_ms(10);
      SWL_TOG(SWL_RED);
    }

     if (SWL_Pushed(SWL_UP) > 0)
    {
      RTI_Delay_ms(8);
      SWL_TOG(SWL_RED);

    }

    if (SWL_Pushed(SWL_DOWN) > 0)
    {
      RTI_Delay_ms(12);
      SWL_TOG(SWL_RED);
    }

    if (((SWL_Pushed(SWL_UP)) > 0)
      &&(SWL_Pushed(SWL_DOWN) > 0)) { RTI_Delay_ms(10);
      SWL_TOG(SWL_RED); }

    /// tier 2
    if (SWL_Pushed(SWL_LEFT) > 0)
    {
      SWL_ON(SWL_RED);
      RTI_Delay_ms(1);
      SWL_OFF(SWL_RED);
     RTI_Delay_ms(9);
     
    }
    // tier 3
    if (SWL_Pushed (SWL_RIGHT)>0)
    {
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_RED);
    }
  else {SWL_OFF(SWL_GREEN);}
  




  }
}