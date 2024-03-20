

#include "derivative.h"
#include <hidef.h>
#include "sci.h"

void sci0_txByte( char data)
{
    while (!(SCI0SR1 & SCI0SR1_TDRE_MASK))
    {
        ;
    }

    SCI0DRL = data;
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

void sci0_InitEnum(BaudRate br)
{
    SCI0BD = br;
    SCI0CR2 |= (1 << 3);

    // Enable receiver - Set RE bit in SCI0CR2 register
    SCI0CR2 |= (1 << 2);
}