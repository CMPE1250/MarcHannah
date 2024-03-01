


#include "derivative.h"
#include <hidef.h>  
#include "clock.h"


  

void Clock_EnableOutput(ClockOutDiv Clock_Mask)
{
    PLLCTL=Clock_Mask;
}

void Clock_Set8MHZ(void)
{
    CLKSEL_PLLSEL = 0; 
   // DEF_BUS_CLOCK=8000000;
}
void Clock_Set20MHZ()
{
    SYNR = 4;
    REFDV = 3;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK){;}
        CLKSEL_PLLSEL = 1;
       // DEF_BUS_CLOCK=20000000;
}
void Clock_Set24MHZ() {
    SYNR = 2;
    REFDV = 1;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK){;}
        CLKSEL_PLLSEL = 1;
      //  DEF_BUS_CLOCK=24000000; 
}
void Clock_Set40MHZ(){
    SYNR =4;
    REFDV = 1;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK){;}
        CLKSEL_PLLSEL = 1;
    
   // DEF_BUS_CLOCK=40000000;
    } 

unsigned long Clock_GetBusSpeed()
{long bSpeed=DEF_BUS_CLOCK;
return bSpeed;}