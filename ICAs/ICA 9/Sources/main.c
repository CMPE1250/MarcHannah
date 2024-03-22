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
#include "SWL_LED.h"
#include "clock.h"
#include "rti.h"
#include "misc.h"
#include "sci.h"
// #include <stdio.h>

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void partA(void);
void partB2(void);
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
  //partB2();
 // partC();
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

void partB2(void)
{
  RTI_Delay_ms(250);
  transmit20VowelsWithSum();
}
 
 void partC(void)
 {
  RTI_Delay_ms(250);
 // transmit20VowelsWithSumColors();
  }



/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
