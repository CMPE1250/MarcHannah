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
void CountUp(void);
void CountHex(void);
void MoveDecimal(void);

/********************************************************************/
// Global Variables
/********************************************************************/
int countOnes;
int count10s;
int count100s;
int count1000s;
int countDelays;
int decOrHex = 1;
int countActual;
int countPoints = 0;

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
  Segs_Init();
  SWL_Init();
  RTI_Init();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    RTI_Delay_ms(50);
    countDelays++;

    SWL_TOG(SWL_RED);

    if (countDelays % 20 == 0)
    {
      if (decOrHex == 1)
      {
        CountUp();
      }
      if (decOrHex == 2)
      {
        CountHex();
      }
    }

    if (countDelays % 4 == 0)
    {
      MoveDecimal();
    }

    if (SWL_Pushed(SWL_CTR))
    {
      countActual = 0;
    }

    if (SWL_Pushed(SWL_UP))
    {
      decOrHex = 2;
    }
    if (SWL_Pushed(SWL_DOWN))
    {
      decOrHex = 1;
    }
  }
}
/********************************************************************/
// Functions
/********************************************************************/
void CountUp(void)
{

  countActual++;
  SWL_TOG(SWL_GREEN);

  Segs_16D(countActual, Segs_LineTop);
}

void CountHex(void)
{
  countActual++;
  Segs_16H(countActual, Segs_LineTop);
  SWL_TOG(SWL_GREEN);
}

void MoveDecimal(void)
{
  if(countPoints==0)
  
  {

    
    
    countPoints++;
    }

  if (countPoints == 1)
  {
    Segs_Custom(4,0b00000000); Segs_Custom(5,0b10000000); Segs_Custom(6,0b10000000); Segs_Custom(7,0b10000000);
    countPoints++;
  }
  if(countPoints==2)
  {
    
    Segs_Custom(4,0b00000000); Segs_Custom(5,0b00000000); Segs_Custom(6,0b10000000); Segs_Custom(7,0b10000000);
    countPoints++;
  }
  if(countPoints==3)
  {
    Segs_Custom(4,0b00000000); Segs_Custom(5,0b00000000); Segs_Custom(6,0b00000000); Segs_Custom(7,0b10000000);
    countPoints++;
  }
  if(countPoints==4)
  {
    Segs_Custom(4,0b00000000); Segs_Custom(5,0b00000000); Segs_Custom(6,0b00000000); Segs_Custom(7,0b00000000);
   countPoints++;
   
  }
  if(countPoints==5)
  {
   // Segs_ClearLine(Segs_LineBottom);
   Segs_Custom(4,0b10000000); Segs_Custom(5,0b10000000); Segs_Custom(6,0b10000000); Segs_Custom(7,0b10000000);
    countPoints=0;
  

  }

  
  
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
