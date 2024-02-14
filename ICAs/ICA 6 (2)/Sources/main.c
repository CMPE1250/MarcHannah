//******************************************************************** /
// HC12 Program:  ICA 6
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:      Marc Hannah
// Details:      toggle switched with attached header files
// Date:          february 9
// Revision History :
//  each revision will have a date + desc. of changes

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

// Other system includes or your includes go here
// #include <stdlib.h>
// #include <stdio.h>

#include "SWL_LED.h"

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
int GetCount(void);
/********************************************************************/
// Global Variables
/********************************************************************/

/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  // Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  // EnableInterrupts;

  /********************************************************************/
  // one-time initializations
  /********************************************************************/
  SWL_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    /* if (SWL_Pushed(SWL_LEFT) > 0)
     {
       SWL_ON(SWL_RED);
     }
     else if (SWL_Pushed(SWL_LEFT) == 0)
     {
       SWL_OFF(SWL_RED);
     }

     if (SWL_Pushed(SWL_RIGHT) > 0)
     {
       SWL_ON(SWL_GREEN);
     }
     else if (SWL_Pushed(SWL_RIGHT) == 0)
     {
       SWL_OFF(SWL_GREEN);
     }

     if (SWL_Pushed(SWL_CTR) > 0)
     {
       SWL_ON(SWL_YELLOW);
     }
     else if (SWL_Pushed(SWL_CTR) == 0)
     {
       SWL_OFF(SWL_YELLOW);
     } */
    // tier 2

    /*
        if (SWL_Pushed(SWL_LEFT) > 0 )
        {
          SWL_TOG(SWL_RED);
        }

        if (SWL_Pushed(SWL_RIGHT) > 0)
        {
          SWL_TOG(SWL_GREEN);
        }

        if (SWL_Pushed(SWL_CTR) > 0)
        {
          SWL_TOG(SWL_YELLOW);
        }

        if (SWL_Pushed(SWL_UP) > 0)
        {
          SWL_OFF(SWL_ALL);
        }

        if (SWL_Pushed(SWL_DOWN) > 0)
        {
          SWL_OFF(SWL_ALL);
        }*/


      

    if (SWL_Pushed(SWL_LEFT) > 0 && GetCount() <= 1)
    {

      SWL_ON(SWL_RED);
    }
    if (SWL_Pushed(SWL_LEFT) > 0 && GetCount() == 2)
    {
      if (SWL_Pushed(SWL_RED))
      {
        SWL_OFF(SWL_RED);
      }
    }

    if (SWL_Pushed(SWL_RIGHT) > 0 && GetCount() <=1 )
    {
      SWL_ON(SWL_GREEN);
    }
    if (SWL_Pushed(SWL_RIGHT) > 0 && GetCount() == 2)
    {
      if (SWL_Pushed(SWL_GREEN))
      {
        SWL_OFF(SWL_GREEN);
      }
    }
    if (SWL_Pushed(SWL_CTR) > 0 && GetCount() <= 1)
    {
      SWL_ON(SWL_YELLOW);
    }
    if (SWL_Pushed(SWL_CTR) > 0 && GetCount() == 2)
    {
      if (SWL_Pushed(SWL_YELLOW))
      {
        SWL_OFF(SWL_YELLOW);
      }
    }
    if (SWL_Pushed(SWL_UP) > 0)
    {
      SWL_OFF(SWL_ALL);
    }

    if (SWL_Pushed(SWL_DOWN) > 0)
    {
      SWL_OFF(SWL_ALL);
    }
  }}
    /********************************************************************/
    // Functions
    /********************************************************************/
int GetCount(void)
{
  unsigned char total_LEDS;


 unsigned char led_check = PT1AD1 & 0b11100000;

  if (SWL_Pushed(SWL_RED)){total_LEDS++;}
  if (SWL_Pushed(SWL_GREEN)){total_LEDS++;}
  if (SWL_Pushed(SWL_YELLOW)){total_LEDS++;}

  return total_LEDS;
}
    /********************************************************************/
    // Interrupt Service Routines
    /********************************************************************/
 