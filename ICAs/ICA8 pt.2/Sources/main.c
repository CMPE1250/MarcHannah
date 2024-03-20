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
void partA(void);
void partB(void);
void partC(void);
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
  Clock_Set20MHZ();
  // sci0_Init2();
  sci0_InitEnum(BAUD_19200);
  RTI_Init();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
  partA();
  PartB();
  partC();
  }
}
/********************************************************************/
// Functions
/********************************************************************/
void partA(void)
{
  RTI_Delay_ms(250);
  transmit20Vowels();
}

void partB(void)
{
  RTI_Delay_ms(250);
  transmit20VowelsWithSum();
}
 
 void partC(void)
 {
  RTI_Delay_ms(250);
  transmit20VowelsWithSumColors();
  }



/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
