#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "../../Lib/SWL_LED.h"
#include"../../Lib/rti.h"

void main(void)
{
  // main entry point
  _DISABLE_COP();
  EnableInterrupts;

  SWL_Init();
  RTI_Init();
  for (;;)
  {
    if (SWL_Pushed(SWL_ANY) == 0)
    {
      RTI_Delay_ms(10);
    }

    if (SWL_Pushed(SWL_UP) > 0)
    {
      RTI_Delay_ms(8);
    }

    if (SWL_Pushed(SWL_DOWN) > 0)
    {
      RTI_Delay_ms(12);
    }

    if (((SWL_Pushed(SWL_UP)) > 0)
      &&(SWL_Pushed(SWL_DOWN) > 0)) { RTI_Delay_ms(10); }

    /// tier 2
    if (SWL_Pushed(SWL_LEFT) > 0)
    {
      RTI_Delay_ms(1);
      if (CRGFLG_RTIF)
      {
        CRGFLG = CRGFLG_RTIF_MASK;
        SWL_TOG(SWL_RED);
      }
      RTI_Delay_ms(9);
      if (CRGFLG_RTIF)
      {
        CRGFLG = CRGFLG_RTIF_MASK;
        SWL_TOG(SWL_RED);
      }
    }
    // tier 3
    if (SWL_Pushed (SWL_RIGHT))
    {
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_RED);
    }

    if (CRGFLG_RTIF) // RTI period over?
    {
      CRGFLG = CRGFLG_RTIF_MASK; // clear flag, VERY IMPORTANT
      SWL_TOG(SWL_RED);
    }
  }
}