#include "lcd.h"
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include <stdlib.h>
#include <stdio.h>
#include "rti.h"

#define lcd_RWUp DDRH = 0;    PORTK |= 2;

#define lcd_RWDown \PORTK &= (~2); DDRH = 0xFF;

#define lcd_EUp PORTK |= 1;

#define lcd_EDown PORTK &= (~4);

#define lcd_RSUp PORTK |= 4;

#define lcd_RSDown PORTK &= (~4);

char lcd_Busy(void)
{
    unsigned char cBusy;

    DDRH = 0b00000000;

    PORTK |= 0b00000011;

    PORTK &= 0b11111000;

    cBusy = PTH & 0b10000000;

    return cBusy;
}

void lcd_Ins(unsigned char val)
{
    while (lcd_Busy() != 0)
        ;


    PTH = val;

    PORTK |= 0b00000011;
    RTI_Delay_ms(10);
    PORTK &= 0b11111000;
}

void lcd_Data(unsigned char val)
{
   
    while (lcd_Busy() != 0)
        ;


    
    

    PTH = val;
    PORTK |= 0b00000101;
    RTI_Delay_ms(10);
    PORTK &= 0b11111000;

}

void lcd_Init(void)
{
    PTH = 0b00000000;
    DDRH = 0b11111111;

    PORTK &= 0b11111000;
    DDRK |= 0b00000111;

    RTI_Delay_ms(50);

    PTH = 0b00111000;

    PORTK |= 0b00000001;
    PORTK &= 0b11111000;

    RTI_Delay_ms(10);

    PORTK |= 0b00000001;
    PORTK &= 0b11111000;

    RTI_Delay_ms(10);

    PORTK |= 0b00000001;
    PORTK &= 0b11111000;

    RTI_Delay_ms(10);

    PORTK |= 0b00000001;
    PORTK &= 0b11111000;

    RTI_Delay_ms(10);

    lcd_Ins(0b00111000);

    lcd_Ins(0b00001110);

    lcd_Ins(0b00000001);

    lcd_Ins(0b00000110);
}