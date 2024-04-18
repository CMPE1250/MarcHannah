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
int index;
int trueValue;
int thousands;
int hundreds;
int tens;
int ones;
int leftPushed;
int RightPushed;
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

    if (SWL_Pushed(SWL_LEFT))
    {

      if (index > 0)
      {

        index--;
      }
    }
    if (SWL_Pushed(SWL_RIGHT))
    {

      if (index < 3)
      {
        index++;
      }
    }

    if (SWL_Pushed(SWL_UP))
    {
      switch (index)
      {
      case 0:
        thousands++;
        break;
      case 1:
        hundreds++;
        break;

      case 2:
        tens++;
        break;

      case 3:
        ones++ : break;

      default:;
      }
    }

    if (SWL_Pushed(SWL_DOWN))
    {
      switch (index)
      {
      case 0:
        thousands--;
        break;
      case 1:
        hundreds--;
        break;

      case 2:
        tens--;
        break;

      case 3:
        ones-- : break;

      default:;
      }
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

  int thousands2;
  int hundreds2;
  int tens2;
  int ones2;


  thousands2 = trueValue / 1000;
  hundreds2 = (trueValue % 1000) / 100;
  tens2 = (trueValue % 100) / 10;
  ones2 = trueValue % 10;

  if (index = 0)
  {
    Segs_Normal(0, thousands2, Segs_DP_ON);
    Segs_Normal(1, hundreds2, Segs_DP_OFF);
    Segs_Normal(2, tens2, Segs_DP_OFF);
    Segs_Normal(3, ones2, Segs_DP_OFF);
  }
  if (index == 1)
  {
    Segs_Normal(0, thousands2, Segs_DP_OFF);
    Segs_Normal(1, hundreds2, Segs_DP_ON);
    Segs_Normal(2, tens2, Segs_DP_OFF);
    Segs_Normal(3, ones2, Segs_DP_OFF);
  }
  if (index == 2)
  {
    Segs_Normal(0, thousands2, Segs_DP_OFF);
    Segs_Normal(1, hundreds2, Segs_DP_OFF);
    Segs_Normal(2, tens2, Segs_DP_ON);
    Segs_Normal(3, ones2, Segs_DP_OFF);
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
