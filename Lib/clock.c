


#include "derivative.h"
#include <hidef.h>  
#include "clock.h"




void Clock_EnableOutput(ClockOutDiv)
{
    PLLCTL=ClockOutDiv;
}

void Clock_Set8MHZ(void)
{
    
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
void Clock_Set24MHZ(void) { SYNR = }

void Clock_Set40MHZ(void); // Set clock to 40MHZ using PLL

unsigned long Clock_GetBusSpeed(void);