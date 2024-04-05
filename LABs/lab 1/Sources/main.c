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
#include "SWL_LED.h"
#include "clock.h"
#include "rti.h"
#include "misc.h"
#include "sci.h"

/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void sci0_GotoXY(int iCol, int iRow);
/********************************************************************/
// Global Variables
/********************************************************************/


unsigned char input;





/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

 

  char letter='!';
  char myString[]= "this is a string please work";


  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  

    



/********************************************************************/
  // one-time initializations
/********************************************************************/
  SWL_Init();
  Clock_Set20MHZ();

  sci0_InitEnum(BAUD_38400);
  RTI_Init();
  Lab1Init();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {

    
    if(sci0_Peek())
    {

      sci0_rxByte(&input);
      
      Parseinput(input);
      














    }
   
    
    
    
    
    




   
   
   
   
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void sci0_GotoXY(int iCol, int iRow) {
   
   char location[22];
   
   
   
    sprintf(location,"\x1B[%d;%dH", iRow, iCol);
   
    sci0_txStr(location);
    
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
