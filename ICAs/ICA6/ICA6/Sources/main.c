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
#define red_LED=      0b10000000
#define yellow_LED=   0b01000000
#define green_LED=    0b00100000
#define left_Switch=  0b00001000
#define right_Switch= 0b00000010
#define center_Switch=0b00000001
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
 SWL_Init ()
  count = 0;

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  { if (SWL_Pushed(left_Switch)>0){SWL_ON(red_LED)}
    else if (SWL_Pushed( left_Switch)==0){SWL_OFF(red_LED)}
   
    if (SWL_Pushed(right_Switch)>0){SWL(green_LED)}
    else if (SWL_Pushed(right_Switch)==0){SWL_OFF(green_LED)}
  
    if (SWL_Pushed(center_switch)>0){SWL(yellow_LED)}
    else if (SWL_Pushed(center_switch)=0){SWL_OFF(yellow_LED)}
    

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
