#include "lcd.h"
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include <stdlib.h>
#include <stdio.h>
#include "rti.h"



#define lcd_RWUP DDRH=0; PORTK|=2;

#define lcd_RWDown PORTK&=(~2); DDRH=0xFF;

#define lcd_EUp PORTK |=1;

#define lcd_EDown PORTK&=(~4);

#define lcd_RSUp PORTK |=4;

#define lcd_RSDown PortK &=(~4);

#define lcd_MicroDelay {char __x=1; while (--__x);}


char lcd_Busy (void)
{
   
   
   
    unsigned char inVal=0;
   
    lcd_RSDown;
    lcd_RSUp;

    do
    {
        lcd_EUp;
        lcd_MicroDelay;


        inVal=PTH;

        lcd_EDown
    }while ((inVal&0x80));


}



void lcd_Ins (unsigned char  val)
{
    lcd_Busy;
    lcd_RSDown;

    PTH=val;

    lcd_EUp;

    lcd_EDown;

} 


void lcd_Data (unsigned char  val)
{
    lcd_Busy;
    lcd_RSUp;

    PTH=val;

    lcd_EUp;

    lcd_EDown;

} 


void lcd_Init (void)
{
PTH=0;


lcd_EDown;

lcd_RSDown;

lcd_RWDown;
DDRK=|=0b00000111;
lcd_MicroDelay;
PTH=0x38;
lcd_EUp;
lcd_EDown;
RTI_Delay_ms(15);
lcd_EUp;
lcd_EDown;
RTI_Delay_ms(1);

lcd_Ins(0x38);
lcd_Ins(0x0C);
lcd_Ins(0x01);
lcd_Ins(0x06);


}