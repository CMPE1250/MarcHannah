/********************************************************************/
// HC12 Program:  Lab2
// Processor:     MC9S12XDP512
// Bus Speed:    20 MHz
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
#include <stdio.h>
#include "SWL_LED.h"
#include "clock.h"
#include "rti.h"
#include "misc.h"
#include "sci.h"
#include <math.h>

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

void DrawState(unsigned int iOPA, unsigned int iOPB, int operation);



/********************************************************************/
// Global Variables
/********************************************************************/

unsigned char input;
int AorB;
int operation;
int opIndex;
unsigned int iOPA;
unsigned int iOPB;

/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  // Any main local variables must be declared here

  char opABuffer[5] = "0000";
  char opBBuffer[5] = "0000";

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
  Lab1Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    if (sci0_Peek())
    {

      sci0_bread(&input);

       if (input == '|')
      {
        operation = 1;
        sci0_txByteXY(9, 9, '|');
        
        sci0_GotoXY(13+opIndex,5+AorB);
      }

      if (input == '&')
      {
        operation = 0;
        sci0_txByteXY(9, 9, '&');
       
        sci0_GotoXY(13+opIndex,5+AorB);
      }

    if (input == '\x09')
{
    
    AorB = !AorB;
    
 
    opIndex = 0;

   
    if (!AorB)
        sci0_GotoXY(13,5);
    else 
        sci0_GotoXY(13,6);
}

      if (IsHexLetter(input))
      {
        if (AorB==0)
        {
          opABuffer[opIndex++] = input;

          sci0_txByte(input);
          sci0_GotoXY(13, 6 + opIndex);

          if (opIndex == 4)
          {
            
            opIndex = 0;
          }
        }
        if (AorB==1)
        {
          opBBuffer[opIndex++] = input;
          sci0_txByte(input);
          sci0_GotoXY(13, 7 + opIndex);
        }
        
        {
         

          if (opIndex >= 4)
          {
          
            opIndex = 0;
          }
        }



    iOPA = HexArrayToUInt16(opABuffer);
    iOPB = HexArrayToUInt16(opBBuffer);

    DrawState(iOPA, iOPB, operation);
  
}
}
}
}
/********************************************************************/
// Functions
/********************************************************************/

void DrawState(unsigned int iOPA, unsigned int iOPB, int operation)
{
  char aBuffer[8];
  char bBuffer[8];
  int result;

  sprintf(aBuffer, "(%05d)", iOPA);
  sprintf(bBuffer, "(%05d)", iOPB);
  sci0_txStrXY(18, 5, aBuffer);
  sci0_txStrXY(18, 6, bBuffer);

  sci0_ShowBin16(iOPA, 1);
  sci0_ShowBin16(iOPB, 2);

  if (operation == 0)
  {
    result = iOPA & iOPB;
    sci0_ShowBin16(result, 3);
  }

  if (operation == 1)
  {
    result = iOPA | iOPB;
    sci0_ShowBin16(result, 3);
  }


  sci0_GotoXY(13+opIndex,5+AorB);

}


/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
