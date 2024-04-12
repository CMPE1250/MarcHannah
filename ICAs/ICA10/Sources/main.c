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
void Tier1(void);
void Tier2(void);
void Tier3(void);
/********************************************************************/
// Global Variables
/********************************************************************/
int activateCount = 0;

unsigned char countActual;
unsigned char count10s;
unsigned char count100s;
unsigned char count1000s;
unsigned char count;
unsigned char count2;

unsigned int hexCount;
int addr;

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
    // Tier1();
    // Tier2();
    Tier3();
  }
}

/********************************************************************/
// Functions
/********************************************************************/
void Tier1(void)
{

  hexCount = 0xFFFF;

  if (SWL_Pushed(SWL_CTR))
  {
    if (!activateCount)
    {
      activateCount = 1;
    }
    else
    {
      activateCount = 0;
    }
  }

  while (activateCount)
  {

    count++;
    countActual++;

    RTI_Delay_ms(100);

    Segs_Normal(3, count, Segs_DP_OFF);
    if (count == 9)
    {
      count = 0;
      count10s += 1;
    }

    Segs_Normal(2, count10s, Segs_DP_OFF);
    if (count10s == 9)
    {
      count10s = 0;
      count100s += 1;
    }

    Segs_Normal(1, count100s, Segs_DP_OFF);
    if (count100s == 9)
    {
      count100s = 0;
      count1000s += 1;
    }

    Segs_Normal(0, count1000s, Segs_DP_OFF);

    Segs_16H(hexCount, Segs_LineBottom);

    hexCount = hexCount - countActual;
  }
}

void Tier2(void)
{

  count++;
  // while (count==10)
  //{

  if (SWL_Pushed(SWL_RIGHT))
  {
    addr = (addr + 1) % 4;
    Segs_ClearLine(Segs_LineTop);
    hexCount++;
  }

  if (SWL_Pushed(SWL_LEFT))
  {
    if (addr == 0)
    {
      addr = 3;
      Segs_ClearLine(Segs_LineTop);
    }
    else
    {
      addr = (addr - 1);
      Segs_ClearLine(Segs_LineTop);
    }

    hexCount++;
    //}

    count = 0;
    RTI_Delay_ms(100);
  }

  Segs_Custom(addr, 0b01000001);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b01100000);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b00011000);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b00000110);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b01000001);

  Segs_16H(hexCount, Segs_LineBottom);
}

void Tier3(void)
{


  if (SWL_Pushed(SWL_RIGHT))
  {
    count++;
  }
  if (count == 10)
  {
    addr=(addr + 1) % 4;    
    count = 0;
    
  }

  if (SWL_Pushed(SWL_LEFT))
  {
    count2++;
  }
  if (count2 == 10)
  {

    count = 0;
    (addr - 1) % 5;
  }

  Segs_Custom(addr, 0b01000001);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b01100000);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b00011000);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b00000110);
  RTI_Delay_ms(200);
  Segs_Custom(addr, 0b01000001);
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/