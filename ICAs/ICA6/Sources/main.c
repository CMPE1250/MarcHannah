********************************************************************/
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
//#include <stdlib.h>
//#include <stdio.h>


#include "../Lib/SWL_LED.h"
#include "../Lib/SWL_LED.c"



/********************************************************************/
//Defines
/********************************************************************/
/*
#define red_LED=      0b10000000
#define yellow_LED=   0b01000000
#define green_LED=    0b00100000
#define left_Switch=  0b00001000
#define right_Switch= 0b00000010
#define center_Switch=0b00000001 
*/
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
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
 SWL_Init ();
  count = 0;

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  { if (SWL_Pushed(SWL_LEFT)>0){SWL_ON(SWL_RED);}
    else if (SWL_Pushed( SWL_LEFT)==0){SWL_OFF(SWL_RED);}
   
    if (SWL_Pushed(SWL_RIGHT)>0){SWL(SWL_GREEN);}
    else if (SWL_Pushed(SWL_RIGHT)==0){SWL_OFF(SWL_GREEN);}
  
    if (SWL_Pushed(SWL_CTR)>0){SWL(SWL_YELLOW);}
    else if (SWL_Pushed(SWL_CTR)=0){SWL_OFF(SWL_YELLOW);}
    
    if (SWL_Pushed(SWL_LEFT)>0){SWL_ON(SWL_RED);}





  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
