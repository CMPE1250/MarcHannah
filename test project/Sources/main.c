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

//Other system includes or your includes go here
#include <stdlib.h>
#include <stdio.h>
#include "sci.h"
#include "rti.h"
#include "clock.h"
#include "misc.h"
#include "SWL_LED.h"


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void GotoXY(int iCol, int iRow);
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
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
  SWL_Init();
  Clock_Set20MHZ();
  sci0_InitEnum(BAUD_19200);
  RTI_Init();

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
      
      char buffer[20]="string here";
      RTI_Delay_ms(250);
      //sci0_txStr("\x1B[5;10H");
      
      sci0_txStr(buffer);
      RTI_Delay_ms(250);
      sci0_ClearScreen();

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/



void GotoXY(int iCol, int iRow) {
   
   char location[20];
    sprintf(location,"\x1B[%d;%dH", iRow, iCol);
    sci0_txStr(location);
    
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
