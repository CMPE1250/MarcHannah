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
#include "../../Lib/clock.h"
#include "../../Lib/rti.h" 
//Other system includes or your includes go here
#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
 unsigned char data;
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
sci0_Init2();
RTI_Init();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {


  data=GetRandom() + 'A';

  RTI_Delay_ms(50);
  SWL_TOG(SWL_RED);
  sci0_txByte(data);




//sci0_rxByte(&data)
  
 
 




 





}


 
 
 
 
 
  }                   


/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
