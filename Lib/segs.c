
#include <hidef.h>
#include "derivative.h"
#include "segs.h"

#define Segs_WLATCH   \
    PORTA &= (~0x01); \
    PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;

void Segs_Normal(unsigned char Addr, unsigned char Value, Segs_DPOption dp)
{
    Addr &= 0x07;

    Addr |= 0b01011000;

    if (dp)
        Value &= (~0x80);
    else
        Value |= 0x80;

    // present controlbyte
    PORTB = Addr;
    Segs_MH

    Segs_WLATCH
    PORTB = Value;
    Segs_ML

    Segs_WLATCH
}

void Segs_Custom(unsigned char Addr, unsigned char Value)
{

    Addr &= 0x07;

    Addr |= 0b01111000;


    PORTB = Addr;
   
    Segs_MH

    Segs_WLATCH

    PORTB = Value;
   
    Segs_ML

    Segs_WLATCH
}

void Segs_8H(unsigned char Addr, unsigned char value)
{
   
    if (Addr > 7)
    {
        return;
    }
    else{
    unsigned int char1=value>>4;
    unsigned int char2=value & 0x0F;
    
    Segs_Normal(Addr,char1,Segs_DP_OFF);
    
    if(Addr+1==8)
    {
        Segs_Normal(0,char2,Segs_DP_OFF);
    }
    else{Segs_Normal(Addr+1,char2,Segs_DP_OFF);}



    }

}

void Segs_16H(unsigned int Value, Segs_LineOption lineOption)
{
    char first = (Value >> 12) & 0x000f;
    char second = (Value >> 8) & 0x000f;
    char third = (Value >> 4) & 0x000f;
    char fourth = Value & 0x000f;

    if (!lineOption)
    {
        Segs_Normal(0,first,Segs_DP_OFF);
        Segs_Normal(1,second,Segs_DP_OFF);
        Segs_Normal(2,third,Segs_DP_OFF);
        Segs_Normal(3,fourth,Segs_DP_OFF);


    }
    else
    {
        Segs_Normal(4,first,Segs_DP_OFF);
        Segs_Normal(5,second,Segs_DP_OFF);
        Segs_Normal(6,third,Segs_DP_OFF);
        Segs_Normal(7,fourth,Segs_DP_OFF);




    }
  }


void Segs_Clear(void)
{
    int i = 0;

    for (i; i < 8; i++)
    {
        Segs_Custom(i, 0b10000000);
    }
}



void Segs_ClearLine(Segs_LineOption line)
{
   
    if(line == Segs_LineTop){

    int i;
    for (i=0; i < 4; i++)
    {
        Segs_Custom(i, 0b10000000);
    }}
    if(line == Segs_LineBottom)
    {   int i;
         for (i=4; i < 8; i++)
    {
        Segs_Custom(i, 0b10000000);
    }
    }
}





void Segs_Init(void)
{

    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB |= 0xFF;

    Segs_Clear();

     Segs_Normal(4,'3',Segs_DP_OFF);
     Segs_8H(7,0x00E4);
     

    

    Segs_Custom(1,0b01001010);

    Segs_Custom(2,0b11110000);

    Segs_Custom(5,0b10001011);

     Segs_Custom(6,0b10110001);
}
