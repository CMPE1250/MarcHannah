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

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

void DrawTop(void);
int valueMath(void);


/********************************************************************/
// Global Variables
/********************************************************************/
int index;
int trueValue;
int thousands;
int hundreds;
int tens;
int ones;

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

      if (index == 3)
      {
        index = 0;
      }
      else
      {
        index++;
      }
    }
    if (SWL_Pushed(SWL_RIGHT))
    {

      if (index == 3)
      {
        index = 0;
      }
      else
      {
        index--;
      }
    }
    
  
    }










    DrawTop();
    Segs_16H(trueValue, Segs_LineBottom);
  }


/********************************************************************/
// Functions
/********************************************************************/

void DrawTop(void)
{

  thousands = trueValue / 1000;
  hundreds = (trueValue % 1000) / 100;
  tens = (trueValue % 100) / 10;
  ones = trueValue % 10;

  if (index = 0)
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

int valueMath(void)
{
  int value;

  value=(thousands*1000)+(hundreds*100)+(tens*10)+(ones);

return value;

}




/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
