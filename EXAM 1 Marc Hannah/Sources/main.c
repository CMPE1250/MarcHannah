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

// Other system includes or your includes go here
// #include <stdlib.h>
// #include <stdio.h>

/********************************************************************/
// Defines
/********************************************************************/
#define all_LED 0b11100000
#define RED_LED 0b11100000
/********************************************************************/
// Local Prototypes
/********************************************************************/
int GetSwitch(void);
/********************************************************************/
// Global Variables
/********************************************************************/
int count = 0;
unsigned char total_Switch=0;
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
  PT1AD1 &= 0x1F;
  DDR1AD1 = 0xE0;
  ATD1DIEN1 |= 0x1F;
 
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
     PT1AD1 = all_LED;
     while(count>1,388,888){count++;}
     PT1AD1=0b011000000;
    
    
    if (GetSwitch()==2){PT1AD1=0b10100000;}
    else PT1AD1=0b11000000;
   
  }
}

/********************************************************************/
// Functions
/********************************************************************/
int GetSwitch(void){ unsigned char total_Switch;




  if (PT1AD1&= 0b00001000>0){total_Switch++;}
  if (PT1AD1&= 0b00000100>0){total_Switch++;}
   if (PT1AD1&= 0b00000010>0){total_Switch++;}
    if (PT1AD1&= 0b00010000>0){total_Switch++;}
     if (PT1AD1&= 0b00000001>0){total_Switch++;}

  return total_Switch;
}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
