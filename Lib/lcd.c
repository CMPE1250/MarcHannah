#include "lcd.h"
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */






#define lcd_RWUP DDRH=0; PORTK|=2;

#define lcd_RWDown PORTK&=(~2); DDRH=0xFF;

#define lcd_EUp PORTK |=1;

#define lcd_RSUp PORTK |=4;

#define lcd_RSDown PortK &=(~4);

#define lcd_MicroDelay {char __x=1; while (--__x);}


char lcd_Busy (void)
{
   
   
   
    unsigned char inVal=0;
   
    lcd_RSDown;
    lcd_RSUp;


}



void lcd_Ins (unsigned char  data){} //LCD_Inst



