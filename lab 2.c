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

//Other system includes or your includes go here
#include <stdlib.h>
#include "SWL_LED.h"
#include "clock.h"
#include "rti.h"
#include "misc.h"
#include "segs.h"
#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
int counter=0;
int countDecimal;
int HexorDec;
int countHex;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/


/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    RTI_Delay_ms(50);
    counter++;
   if (counter==20 ){
  
    countHex++;
    countDecimal++;
    SWL_TOG(SWL_GREEN);
    if ((countDecimal == 1000))
    {
      countDecimal=0;
    }
    if (countHex==0xFFFF;)
    {
      countHex=0x0000;
    }
   }


    if (SWL_Pushed(SWL_CTR))
    {
      countDecimal=0;
      countHex=0;
    }


   if (!DecOrHex){
    
    {
      
      Segs_16D(countDecimal,Segs_LineTop);
    }
  
  
   }
    if(DecOrHex)
    {
      
      Segs_16H(countHex,Segs_LineTop)

    }



   }

    SWL_TOG(SWL_RED);

  }                   

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
