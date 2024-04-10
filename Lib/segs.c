
#include <hidef.h>      
#include "derivative.h"
#include "segs.h"



#define Segs_WLATCH PORTA &= (~0x01); PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;


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

    Addr |= 0b01110000;

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
if(Addr>7)
{return;}


    lower_nibble = value & 0x0F;
    Segs_Normal(Addr, lower_nibble, Segs_DP_OFF);

    upper_nibble = (value >> 4) & 0x0F;
    Segs_Normal(Addr+1, upper_nibble, Segs_DP_OFF);


}

void Segs_16H(unsigned int Value, Segs_LineOption lineOption)
{
    char first=(Value >>12) % 0x000f;
    char second=(Value>>8) % 0x000f;
    char third=(Value>>4) % 0x000f;
    char fourth=Value & 0x000f;

    if(lineOption)
    {   int i;
        for ( i = 0; i <= 3; i++)
        {
           switch (i)
           {
           case 0:
            Segs_Custom(i,first);
            break;
         
           case 1:
           Segs_Custom(i,second);
           break;
          
           case 2:
           Segs_Custom(i,third);
            break;
           
           
            case 3:
            Segs_Custom(i,fourth);
          
           default:
            break;
           }

        }

    }
    else{ 
        for ( i = 0; i <= 3; i++)
        {
           switch (i)
           {
           case 0:
            Segs_Custom(i,first);
            break;
         
           case 1:
           Segs_Custom(i,second);
           break;
          
           case 2:
           Segs_Custom(i,third);
            break;
           
           
            case 3:
            Segs_Custom(i,fourth);
          
           default:
            break;
           }
         }
      }
}




void Segs_Clear(void)
{
    int i = 0;

    for (i; i < 7; i++)
    {
        Segs_Custom(i , 0b10000000);
    }
}

void Segs_Init(void)
{

    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB |= 0xFF;

   // Segs_Clear();
}
