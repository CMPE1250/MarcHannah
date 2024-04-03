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
#include <stdlib.h>
#include <stdio.h>
#include "sci.h"
#include "rti.h"
#include "clock.h"
#include "misc.h"
#include "SWL_LED.h"

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void GotoXY(int iCol, int iRow);
/********************************************************************/
// Global Variables
/********************************************************************/
char data;

int count;
int count2;


 char buffer[10];
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
  sci0_InitEnum(BAUD_38400);
  RTI_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    data = '.';

    if (SWL_Pushed(SWL_UP))
    {
      data = '!';
    }

    if (SWL_Pushed(SWL_DOWN))
    {
      data = '?';
    }
    if (SWL_Pushed(SWL_CTR))
    {
      data = '.';
    }

    RTI_Delay_ms(10);
    SWL_TOG(SWL_RED);
    sci0_txByte(data);

    count++;
    
    
    
    
      sprintf(buffer, "   %04d  ",count2 );


   GotoXY(1,1);




  
   if (count2==0)
   {
    GotoXY(0,3);
   }

   if(count2<80){

    if (count == 10)
    {
      sci0_txByte(data);
       SWL_TOG(SWL_GREEN);
       count2++;

      count = 0;
    }
   

   else if(count2==80)
   {
     sci0_txStr("\x1b[1K");

     count2=0;
   }




  }
  }
}

/********************************************************************/
// Functions
/********************************************************************/

void GotoXY(int iCol, int iRow)
{

  char location[20];
  sprintf(location, "\x1B[%d;%dH", iRow, iCol);
  sci0_txStr(location);
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
