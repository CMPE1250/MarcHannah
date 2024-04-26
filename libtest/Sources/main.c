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
#include "sci.h"
/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void SwitchTransition(void);
/********************************************************************/
// Global Variables
/********************************************************************/
unsigned char input;
int loopCount;
int count=0;
char countBuffer[20];
int index=15;
char binaryBuffer[18]="0000000000000000\0";


int leftCurrent;
int rightCurrent;
int upCurrent;
int downCurrent;
int centerCurrent;

int oldLeftState=0;
int oldRightState=0;
int oldUpState=0;
int oldDownState=0;
int oldCenterState=0;
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
  
  sci0_InitEnum(BAUD_38400);
  RTI_Init();
  SWL_Init();
  Segs_Init();
  lcd_Init();
  lcd_Ins(00001111);
  
  //testInit();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {


    
  sci0_bread(&input);

  Segs_Normal(0,input,Segs_DP_OFF);


{
     leftCurrent=SWL_Pushed(SWL_LEFT);


    if ((leftCurrent!=oldLeftState)&&leftCurrent)
    {


      
    }

    oldLeftState=leftCurrent;

}

{
   rightCurrent=SWL_Pushed(SWL_RIGHT);


    if ((rightCurrent!=oldRightState)&&rightCurrent)
    {

     
    }
  
    oldRightState=rightCurrent;

}

{
 upCurrent=SWL_Pushed(SWL_UP);


    if ((upCurrent!=oldUpState)&&upCurrent)
    {
  
    }

    oldUpState=upCurrent;
}
{
   downCurrent=SWL_Pushed(SWL_DOWN);


    if ((downCurrent!=oldDownState)&&downCurrent)
    {

    }
    oldDownState=downCurrent;
}
{
     centerCurrent=SWL_Pushed(SWL_LEFT);


    if ((centerCurrent!=oldCenterState)&&centerCurrent)
    {


      
    }

    oldLeftState=leftCurrent;

}


   

  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
