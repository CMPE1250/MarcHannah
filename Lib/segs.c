

#include "segs.h"

#define Segs_WLATCH   \
    PORTA &= (~0x01); \
    PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;

void Segs_Init(void)
{
    PORTA = 0x03;
    DDRA = 0x03;
    DDRB = 0xFF;

    Segs_Clear();
}

void Segs_Normal(unsigned char Addr, unsigned char Value, Segs_DPOption dp)
{
    Addr &= 0x07l;

    Addr |= 0b01011000;

    if (dp)
        Value &= (~0x80);
    else
        Value |= 0x80;

    // present controlbyte
    PORTB = Addr;
    Segs_MH;

    Segs_WLATCH;
    PORTB=Value;
    Segs_ML;

    Segs_WLATCH;
}

void Segs_Custom(unsigned char Addr, unsigned char Value)
{

    Addr &= 0x07l;

    Addr |= 0b01010000;

    Value &= (~0x80);

    Value |= 0x80;

    PORTB = Addr;
    Segs_MH;

    Segs_WLATCH;

    PORTB=Value;
    Segs_ML;

    Segs_WLATCH;
}

void Segs_8H(unsigned char Addr, unsigned char value)
{
    char lower_nibble;
    char upper_nibble;

    lower_nibble = value & 0x0F;
    Segs_Normal(Addr, lower_nibble, Segs_DP_OFF);

    upper_nibble = (value >> 4) & 0x0F;
    Segs_Normal(Addr+1, upper_nibble, Segs_DP_OFF);


}

void Segs_16H(unsigned int Value, Segs_LineOption lineOption)
{
    char lower_nibble;
    char upper_nibble;


    upper_nibble = (Value >> 12) & 0x0F;
   // Segs_Normal(Addr, upper_nibble, Segs_DP_OFF);

    lower_nibble = (Value >> 8) & 0x0F;
   // Segs_Normal(Addr, lower_nibble, Segs_DP_OFF);
}

void Segs_Clear(void)
{
    int i = 0;

    for (i; i < 7; i++)
    {
        Segs_Custom(i + 1, 0b10000000);
    }
}