/********************************************************************/
// HC12 Program:  ICA 9 SCI strings
// Processor:     MC9S12XDP512
// Bus Speed:     16 MHz
// Author:        Marc Hannah
// Details:       A more detailed explanation of the program is entered here
// Date:          march 18,2024
// Revision History :
//  each revision will have a date + desc. of changes

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

// Other system includes or your includes go here
#include <stdlib.h>
#include "../../Lib/SWL_LED.h"
#include "../../Lib/clock.h"
#include "../../Lib/rti.h"
#include "../../Lib/misc.h"
#include "../../Lib/sci.h"
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
 
unsigned char keyPressed;
unsigned char *input = &keyPressed;
unsigned char data;
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
  Clock_Set20MHZ();
  sci0_Init2();
  
  RTI_Init();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    data = GetRandom(26) + 'A';

    RTI_Delay_ms(50);
    SWL_TOG(SWL_RED);
    sci0_txByte(data);

 
    if (sci0_rxByte(input) == 1)

    {
      if (IsVowel(input))
      {
        SWL_ON(SWL_GREEN);
        SWL_OFF(SWL_YELLOW);
      }
      else
      {

        SWL_ON(SWL_YELLOW);
        SWL_OFF(SWL_GREEN);
      }
    }
    SWL_OFF(SWL_GREEN);
    SWL_OFF(SWL_YELLOW);





  }
}
/********************************************************************/
// Functions
/********************************************************************/


/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
