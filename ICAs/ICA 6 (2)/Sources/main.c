//******************************************************************** /
// HC12 Program:  ICA 6
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:      Marc Hannah
// Details:      toggle switched with attached header files
// Date:          february 9
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

#include "SWL_LED.h"

/********************************************************************/
// Defines
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
   /* if (SWL_Pushed(SWL_LEFT) > 0)
    {
      SWL_ON(SWL_RED);
    }
    else if (SWL_Pushed(SWL_LEFT) == 0)
    {
      SWL_OFF(SWL_RED);
    }

    if (SWL_Pushed(SWL_RIGHT) > 0)
    {
      SWL_ON(SWL_GREEN);
    }
    else if (SWL_Pushed(SWL_RIGHT) == 0)
    {
      SWL_OFF(SWL_GREEN);
    }

    if (SWL_Pushed(SWL_CTR) > 0)
    {
      SWL_ON(SWL_YELLOW);
    }
    else if (SWL_Pushed(SWL_CTR) == 0)
    {
      SWL_OFF(SWL_YELLOW);
    } */
  




 if (SWL_Pushed(SWL_LEFT)>0 & GetCount()<=2){SWL_TOG(SWL_RED);}

if (SWL_Pushed(SWL_RIGHT)>0){SWL_TOG(SWL_GREEN);}

if (SWL_Pushed(SWL_CTR)>0){SWL_TOG(SWL_YELLOW);}

if (SWL_Pushed(SWL_UP)>0){SWL_OFF(SWL_ALL);}

if(SWL_Pushed(SWL_DOWN)>0 ){SWL_OFF(SWL_ALL);}



unsigned char led_Count=0;
 if (SWL_Pushed(SWL_LEFT) > 0)
 {
   while (led_Count < 2)
   {
     SWL_TOG(SWL_RED);
     led_Count++;
   }
 }
 if (SWL_Pushed(SWL_RIGHT)>0)
 {
   while (led_Count < 2)
   {
     SWL_TOG(SWL_GREEN);
     led_Count++;
   }
 }
 if (SWL_Pushed(SWL_CTR)>0)

    { while (led_Count<2)
     {
       
         SWL_TOG(SWL_YELLOW);led_Count++; 


     }
   }

if (SWL_Pushed(SWL_UP)>0){SWL_OFF(SWL_ALL); led_Count=0;}

 if(SWL_Pushed(SWL_DOWN)>0 ){SWL_OFF(SWL_ALL);led_Count=0;}

 }   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/



  }}