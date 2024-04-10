
#include <hidef.h>      
#include "derivative.h"
#include "segs.h"



#define Segs_WLATCH PORTA &= (~0x01); PORTA |= 0x01
#define Segs_ML PORTA &= (~0x02)
#define Segs_MH PORTA |= 0x02

