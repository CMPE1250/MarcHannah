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
#include "SWL_LED.h"
#include "clock.h"
#include "rti.h"
#include "misc.h"
#include "segs.h"
#include <stdio.h>
#include "lcd.h"
/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/

int loopCount;
float count=0;
char countBuffer[20];
int index=15;
char binaryBuffer[18]="0000000000000000\0";

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
  Clock_Set20MHZ();
  RTI_Init();
  SWL_Init();
  lcd_Init();
  testInit();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {


    
     RTI_Delay_ms(10);
     loopCount++;
      if (loopCount % 10 == 0)
      {
         count += 0.1;
      }
    

     sprintf(countBuffer,"Count %d",count);
     lcd_AddrXY(0,0);
     lcd_String(countBuffer);

    if(SWL_Pushed(SWL_DOWN))
    {
      if(binaryBuffer[index]==0)
      {
        binaryBuffer[index]=1;
      }
      else{binaryBuffer[index]=0;}
    }
    lcd_AddrXY(2,3);
    lcd_String(binaryBuffer);



  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
