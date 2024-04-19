/********************************************************************/
// HC12 Program:  LAb3
// Processor:     MC9S12XDP512
// Bus Speed:     16MHz
// Author:        Marc Hannah
// Details:  
// Date:          
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

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

void DrawTop(void);
void valueMath(void);

/********************************************************************/
// Global Variables
/********************************************************************/
int index=0;
int trueValue;
int thousands;
int hundreds;
int tens;
int ones;
int leftPushed;
int RightPushed;

int leftCurrent;
int rightCurrent;
int upCurrent;
int downCurrent;

int oldLeftState=0;
int oldRightState=0;
int oldUpState=0;
int oldDownState=0;
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
  Lab3SegsInit();
  SWL_Init();
  RTI_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    RTI_Delay_ms(50);
{
     leftCurrent=SWL_Pushed(SWL_LEFT);


    if ((leftCurrent!=oldLeftState)&&leftCurrent)
    {

      if (index > 0)
      {

        index--;
      }
      
    }

    oldLeftState=leftCurrent;

}

{
   rightCurrent=SWL_Pushed(SWL_RIGHT);


    if ((rightCurrent!=oldRightState)&&rightCurrent)
    {

      if (index < 3)
      {
        index++;
      }
    }
  
    oldRightState=rightCurrent;

}

{
 upCurrent=SWL_Pushed(SWL_UP);


    if ((upCurrent!=oldUpState)&&upCurrent)
    {
      switch (index)
      {
      case 0:
        thousands++;
        if(thousands==10)
        {
          thousands=0;
        }
        break;
      case 1:
        hundreds++;
        if(hundreds==10)
        {
          hundreds=0;
        }
        break;

      case 2:
        tens++;
        if(tens==10)
        {
          tens=0;
        }

        break;

      case 3:
        ones++;
       if(ones==10)
        {
          ones=0;
        }


         break;

      default:;
      }
    }

    oldUpState=upCurrent;
}
{
   downCurrent=SWL_Pushed(SWL_DOWN);


    if ((downCurrent!=oldDownState)&&downCurrent)
    {
      switch (index)
      {
      case 0:
        thousands--;
       if(thousands<0)
        {
          thousands=0;
        }

        break;
      case 1:
        hundreds--;

          if(hundreds<0)
        {
          hundreds=0;
        }
        break;

      case 2:
        tens--;
          if(tens<0)
        {
          tens=0;
        }
        break;

      case 3:
        ones--;
          if(ones<0)
        {
          ones=0;
        }
       break;

      default:;
      }
    }
    oldDownState=downCurrent;
}


    valueMath();

    DrawTop();
    Segs_16H(trueValue, Segs_LineBottom);
  }
}
/********************************************************************/
// Functions
/********************************************************************/

void DrawTop(void)
{



  if (index == 0)
  {
    Segs_Normal(0, thousands, Segs_DP_ON);
    Segs_Normal(1, hundreds, Segs_DP_OFF);
    Segs_Normal(2, tens, Segs_DP_OFF);
    Segs_Normal(3, ones, Segs_DP_OFF);
  }
  if (index == 1)
  {
    Segs_Normal(0, thousands, Segs_DP_OFF);
    Segs_Normal(1, hundreds, Segs_DP_ON);
    Segs_Normal(2, tens, Segs_DP_OFF);
    Segs_Normal(3, ones, Segs_DP_OFF);
  }
  if (index == 2)
  {
    Segs_Normal(0, thousands, Segs_DP_OFF);
    Segs_Normal(1, hundreds, Segs_DP_OFF);
    Segs_Normal(2, tens, Segs_DP_ON);
    Segs_Normal(3, ones, Segs_DP_OFF);
  }

  if (index == 3)
  {
    Segs_Normal(0, thousands, Segs_DP_OFF);
    Segs_Normal(1, hundreds, Segs_DP_OFF);
    Segs_Normal(2, tens, Segs_DP_OFF);
    Segs_Normal(3, ones, Segs_DP_ON);
  }
}

void valueMath(void)
{

  trueValue = (thousands * 1000) + (hundreds * 100) + (tens * 10) + (ones);
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
