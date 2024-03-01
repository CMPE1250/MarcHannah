/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "../../Lib/SWL_LED.h"

// Other system includes or your includes go here
// #include <stdlib.h>
// #include <stdio.h>

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

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
    countUp(25000);
    SWL_ON(SWL_RED);
    countUp(25000);
    SWL_OFF(SWL_RED);

    if (SWL_Pushed(SWL_UP) > 0)
    {
      Clock_Set8MHZ();
    }
    if (SWL_Pushed(SWL_LEFT) > 0)
    {
      Clock_Set20MHZ();
    }
    if (SWL_Pushed(SWL_RIGHT) > 0)
    {
      Clock_Set24MHZ();
    }
    if (SWL_Pushed(SWL_DOWN) > 0)
    {
      Clock_Set40MHZ();
    }
  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
