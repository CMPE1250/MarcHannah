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
void QuestionA(void);
void QuestionB(void);
void QuestionC(void);
void UpdateSegs(void);
void QuestionD(void);
/********************************************************************/
// Global Variables
/********************************************************************/
unsigned char input;
int loopCount;
int count = 0;
char stringBuffer[20];
int index;
char binaryBuffer[18] = "0000000000000000\0";
int seconds;
int minutes;
int tenths;
int NameDisplayed = 0;
int leftCurrent;
int rightCurrent;
int upCurrent;
int downCurrent;
int centerCurrent;
unsigned char input;
unsigned char myName[12] = "MARCHANNAH";

unsigned char data;
int oldLeftState = 0;
int oldRightState = 0;
int oldUpState = 0;
int oldDownState = 0;
int oldCenterState = 0;

int randomGet;
int char1;
int char2;
int char3;
int char4;
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

  sci0_InitEnum(BAUD_9600);
  RTI_Init();
  SWL_Init();
  Segs_Init();
  lcd_Init();
  // lcd_Ins(00001111);
  // sci0_txStrXY(40, 12, stringBuffer);
  // testInit();
  sci0_txStr("\x1b[2J");
  // UpdateSegs();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    // QuestionA();
    // QuestionB();
    // QuestionC();

    if (!randomGet)
  {
    int random = GetRandomMin(0,9999)+1;
    Segs_16D(random, Segs_LineTop);
    randomGet = 1;
  }
 
  if (sci0_Peek())
  {
    if (count == 0)
    {
      sci0_bread(&input);
      char1 = input;
      Segs_Normal(4, char1, Segs_DP_OFF);
      
    }
   
     if (count == 1)
     {
      sci0_bread(&input); 
       char2 = char1;
       char1 = input;

      Segs_Normal(4, char1, Segs_DP_OFF);
      Segs_Normal(5, char2, Segs_DP_OFF);
      
    }
     if (count == 3)
    { 
      sci0_bread(&input); 
       char3 = char2;
       char2 = char1;
       char1 = input;

       Segs_Normal(4, char1, Segs_DP_OFF);
       Segs_Normal(5, char2, Segs_DP_OFF);
       Segs_Normal(6, char3, Segs_DP_OFF);
      
     }
    if (count == 3)
     {  sci0_bread(&input); 
       char4=char3;
       char3 = char2;
       char2 = char1;
       char1 = input;

       Segs_Normal(4, char1, Segs_DP_OFF);
       Segs_Normal(5, char2, Segs_DP_OFF);
       Segs_Normal(6, char3, Segs_DP_OFF);
      Segs_Normal(7,char4,Segs_DP_OFF);
    
     }

    count++;
     if(count==4){count=0;}
   }
 }
}
  

/********************************************************************/
// Functions
/********************************************************************/
void QuestionA(void)
{

  if (!NameDisplayed)
  {
    sci0_txStr("\x1b[37m");
    sci0_txStr("\x1b[0;0H");

    sci0_txStr("Hannah");
    NameDisplayed += 1;
  }

  RTI_Delay_ms(100);
  count++;

  if (count % 10 == 0)
  {
    tenths++;
  }
  if (tenths == 10)
  {
    tenths = 0;
    seconds++;
  }
  if (seconds == 60)
  {
    seconds = 0;
    minutes++;
  }

  sprintf(stringBuffer, "%02d:%02d:%1d", minutes, seconds, tenths);

  sci0_txStrXY(40, 12, stringBuffer);

  Segs_16D(count, Segs_LineTop);

  if (count == 9999)
  {
    count = 0;
  }
}

void QuestionB(void)
{

  {
    leftCurrent = SWL_Pushed(SWL_LEFT);

    if ((leftCurrent != oldLeftState) && leftCurrent)
    {

      if (index > 6)
      {
        index++;
        UpdateSegs();
      }
    }

    oldLeftState = leftCurrent;
  }

  {
    rightCurrent = SWL_Pushed(SWL_RIGHT);

    if ((rightCurrent != oldRightState) && rightCurrent)
    {

      if (index <= 0)
      {
        index--;
        UpdateSegs();
      }
    }

    oldRightState = rightCurrent;
  }
}

void QuestionC(void)
{
  if (sci0_Peek())
  {

    sci0_bread(&input);
    sci0_txByte(input);
    count++;
  }

  Segs_16D(count, Segs_LineTop);
  Segs_16H(input, Segs_LineBottom);
}

void QuestionD(void)
{
  if (!randomGet)
  {
    int random = GetRandomMin(0,9999);
    Segs_16D(random, Segs_LineTop);
    randomGet = 1;
  }
 
  if (sci0_Peek())
  {
    if (count == 0)
    {
      sci0_bread(&input);
      char1 = input;
      Segs_Normal(4, char1, Segs_DP_OFF);
      count++;
    }
    else if (count == 1)
    {
      char2 = char1;
      char1 = input;

      Segs_Normal(4, char1, Segs_DP_OFF);
      Segs_Normal(3, char2, Segs_DP_OFF);
    }
    else if (count == 3)
    {
      char3 = char2;
      char2 = char1;
      char1 = input;

      Segs_Normal(4, char1, Segs_DP_OFF);
      Segs_Normal(5, char2, Segs_DP_OFF);
      Segs_Normal(6, char3, Segs_DP_OFF);
    }
   else if (count == 3)
    {
      char4=char3;
      char3 = char2;
      char2 = char1;
      char1 = input;

      Segs_Normal(4, char1, Segs_DP_OFF);
      Segs_Normal(5, char2, Segs_DP_OFF);
      Segs_Normal(6, char3, Segs_DP_OFF);
      Segs_Normal(char4,char4,Segs_DP_OFF);
    }
  }
}

void UpdateSegs(int index)
{

  Segs_Normal(0, '77', Segs_DP_OFF);
  Segs_Normal(1, myName[index + 1], Segs_DP_OFF);
  Segs_Normal(2, myName[index + 2], Segs_DP_OFF);
  Segs_Normal(3, myName[index + 3], Segs_DP_OFF);
}

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

// {
//      leftCurrent=SWL_Pushed(SWL_LEFT);

//     if ((leftCurrent!=oldLeftState)&&leftCurrent)
//     {

//     }

//     oldLeftState=leftCurrent;

// }

// {
//    rightCurrent=SWL_Pushed(SWL_RIGHT);

//     if ((rightCurrent!=oldRightState)&&rightCurrent)
//     {

//     }

//     oldRightState=rightCurrent;

// }

// {
//  upCurrent=SWL_Pushed(SWL_UP);

//     if ((upCurrent!=oldUpState)&&upCurrent)
//     {

//     }

//     oldUpState=upCurrent;
// }
// {
//    downCurrent=SWL_Pushed(SWL_DOWN);

//     if ((downCurrent!=oldDownState)&&downCurrent)
//     {

//     }
//     oldDownState=downCurrent;
// }
// {
//      centerCurrent=SWL_Pushed(SWL_LEFT);

//     if ((centerCurrent!=oldCenterState)&&centerCurrent)
//     {

//     }

//     oldLeftState=leftCurrent;

// }
