/*
 * File:   setupINTOSC.c
 * Author: byron
 *
 * Created on January 26, 2023, 11:14 PM
 */

#include <xc.h>
#include "configINTOSC.h"

void setupINTOSC(int OsciladorInterno) {
    
    if (OsciladorInterno == 125)
    {
    OSCCONbits.IRCF = 0b0001 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 250)
    {
    OSCCONbits.IRCF = 0b0010 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 500)
    {
    OSCCONbits.IRCF = 0b0011 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 1)
    {
    OSCCONbits.IRCF = 0b0100 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 2)
    {
    OSCCONbits.IRCF = 0b0101 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 4)
    {
    OSCCONbits.IRCF = 0b0110 ;
    OSCCONbits.SCS = 1;
    }
    
    if (OsciladorInterno == 8)
    {
    OSCCONbits.IRCF = 0b0111 ;
    OSCCONbits.SCS = 1;
    }
}
