

#include "derivative.h"
#include <hidef.h>
#include "sci.h"

void sci0_Init2(void)
{
    // set baud rate//
    SCI0BD = 130;
    // enable transfer//
    SCI0CR2_TE = 1;

    // enable receiver
    SCI0CR2_RE = 1;
}

unsigned int sci0_rxByte(unsigned char * pData)
{

    if (&pData)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
   
   
   
   
void sci0_txByte (unsigned char data)
    {

       while(!(SCI0SR1 & SCI0SR1_TDRE_MASK  ))
            {
             // Wait till transmit data register is empty
             SCI0DRL = data;
        
            }
    }
