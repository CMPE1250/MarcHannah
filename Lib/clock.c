


#include "derivative.h"
#include <hidef.h>  
#include "clock.h"


  DEF_BUS_CLOCK 8000000; 

void Clock_EnableOutput(ClockOutDiv)
{
    PLLCTL=ClockOutDiv;
}

void Clock_Set8MHZ(void)
{
    CLKSEL_PLLSEL = 0; 
}
void Clock_Set20MHZ(void)
{
    SYNR = 4;
    REFDV = 3;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK)
        CLKSEL_PLLSEL = 1;
}
void Clock_Set24MHZ(void) {
    SYNR = 3;
    REFDV = 2;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK)
        CLKSEL_PLLSEL = 1; }

void Clock_Set40MHZ(void){
    SYNR =5;
    REFDV = 2;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b11111111;
    while (!CRGFLG_LOCK)
        CLKSEL_PLLSEL = 1;
    
    DEF_BUS_CLOCK
    } // Set clock to 40MHZ using PLL

unsigned long Clock_GetBusSpeed(void)
{long bSpeed=DEF_BUS_CLOCK;
return bSpeed;}