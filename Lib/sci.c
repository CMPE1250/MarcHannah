#include "derivative.h"
#include <hidef.h>
#include "sci.h"
#include "SWL_LED.h"
#include <stdio.h>
#include <stdlib.h>

void sci0_txByte(  unsigned char data)
{
    while (!(SCI0SR1 & SCI0SR1_TDRE_MASK))
    {
        ;
    }

    SCI0DRL = data;
}




unsigned char sci0_bread(unsigned char *pData) {
    while (!(SCI0SR1 & SCI0SR1_RDRF_MASK)) {
        // Wait until a character is received
    }
    *pData = SCI0DRL; // Read the character
    return 1; // Success: character read
}

int sci0_rxByte(unsigned char *pData)
{

    if (SCI0SR1 & SCI0SR1_RDRF_MASK) // Check if a character has been received
    {


        
        *pData = SCI0DRL;
        return 1;
    }
    return 0;
}

void sci0_Init2(void)
{
    // Set baud rate//
    SCI0BD = 130;

    // Enable transfer - Set TE bit in SCI0CR2 register
    SCI0CR2 |= (1 << 3);

    // Enable receiver - Set RE bit in SCI0CR2 register
    SCI0CR2 |= (1 << 2);
}

  void sci0_InitEnum( BaudRate br)
{
    SCI0BD = br;
   
   
    SCI0CR2 |= (1 << 3);

 
    SCI0CR2 |= (1 << 2);


}  

void sci0_txStr(const char* straddr)
{
   for(;*straddr;++straddr)
   {sci0_txByte(*straddr);}
}




void sci0_GotoXY(int iCol, int iRow) {
   
   char location[22];
   
   
   
    sprintf(location,"\x1B[%d;%dH", iRow, iCol);
   
    sci0_txStr(location);
    
}

// Function to print a string at a specific position
void sci0_txStrXY(int iCol, int iRow, char const *straddr) {
   
   
    sci0_GotoXY(iCol, iRow);
   
   
   sci0_txStr(straddr);
}


void sci0_txByteXY(int iCol, int iRow, unsigned char c) {
   
   
    sci0_GotoXY(iCol, iRow);
   
   
   sci0_txByte(c);
}






void sci0_ClearScreen (void)
{
    sci0_txStr("\x1b[2J");
}



int sci0_Peek (void)
{
if (SCI0SR1 & SCI0SR1_RDRF_MASK)
{
    return 1;
}
else return 1;
}

void sci0_ShowBin16(unsigned int iVal, int position) {
    char binBuffer[17];
    int i;

    // Construct the binary string
    for (i = 15; i >= 0; i--) {
        binBuffer[15 - i] = ((iVal >> i) & 1) ? '1' : '0'; 
    }
    
    binBuffer[16] = '\0';

    if(position == 1)
        sci0_txStrXY(11,8,binBuffer);
  
     if(position == 2)
        sci0_txStrXY(11,9,binBuffer);

     if(position == 3)
        sci0_txStrXY(11,11,binBuffer);

}