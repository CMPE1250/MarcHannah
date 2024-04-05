/********************************************************************/
// HC12 Program:  ICA 9 SCI strings
// Processor:     MC9S12XDP512
// Bus Speed:     16 MHz
// Author:        Marc Hannah
// Details:       A more detailed explanation of the program is entered here
// Date:          march 18,2024
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
#include "sci.h"
#include <stdio.h>

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void partA(void);

void partB(void);

void partC(void);
/********************************************************************/
// Global Variables
/********************************************************************/

/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  // Any main local variables must be declared here

    int count=0;


  // main entry point
  _DISABLE_COP();
  // EnableInterrupts;

  /********************************************************************/
  // one-time initializations
  /********************************************************************/
  SWL_Init();
  Clock_Set20MHZ();
  // sci0_Init2();
  sci0_InitEnum(BAUD_19200);
  RTI_Init();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
 // partA();
  // partB2();
 /*  
     int sum=0;
    char letter;
    int i = 0;
    char vowelstring[22];
    char buffer[10];


    RTI_Delay_ms(250);

    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));

        vowelstring[i] = letter; 

        sum+=letter;
    }
   
    sprintf(buffer, "   %04d  ",sum );
  
  
  
    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);

    sci0_txByte(' ');
  
    
  
    sci0_txStr(buffer);
    sci0_txByte(' ');
    SWL_OFF(SWL_RED);

*/

 
    int sum = 0;
    char letter;
    int i = 0;
    char vowelstring[22] = "";
    char buffer[10] = "";
    char myName[20] = "Marc Hannah";
    char countBuffer[12];
    int NameDisplayed=0;




    RTI_Delay_ms(250);
    SWL_OFF(SWL_RED);

  
    if (!NameDisplayed)
    {   sci0_txStr( "\x1b[0;0H");
        sci0_txStr("\x1b[31m");
        sci0_txStr(myName);
        NameDisplayed += 1;

        
    }







    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));
        sum+=letter;
        vowelstring[i] = letter; 
    }
   
   
   
    SWL_ON(SWL_RED); 
   
    sci0_txStr("\x1b[31m");
   
   
    sci0_txStr("\x1b[2B" );
    
    sci0_txStr("\x1b[32m");
    
    sci0_txStr(vowelstring);
   
    sci0_txByte(' ');
   
    sprintf(buffer, "%04d", sum);
   
    sci0_txStr("\x1b[33m");
   
    sci0_txStr(buffer);
    
   
    sci0_txByte(' ');
   
    sprintf(countBuffer, "%04d", count);
    
   
    sci0_txStr("\x1b[37m");
  
    sci0_txStr("\x1b[2B");
   
    sci0_txStr(countBuffer);
   
    SWL_OFF(SWL_RED);

    
    count++;


  }
}
/********************************************************************/
// Functions
/********************************************************************/
void partA(void)
{
 char letter;
    int i = 0;
    char vowelstring[22] = "";



    RTI_Delay_ms(250);
    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));
        vowelstring[i] = letter;
    }

    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);
    SWL_OFF(SWL_RED);

}
 
 
 


void PartB2(void)

{
    int sum=0;
    char letter;
    int i = 0;
    char vowelstring[22];
    char buffer[10];




    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));

        vowelstring[i] = letter; 

        sum+=letter;
    }
   
    sprintf(buffer, "   %04d  ",sum );
  
  
  
    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);

    sci0_txByte(' ');
  
    
  
    sci0_txStr(buffer);
    sci0_txByte(' ');
    SWL_OFF(SWL_RED);
}








/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
