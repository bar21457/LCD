/* 
 * File:   configLCD_8bits.h
 * Author: byron
 *
 * Created on February 1, 2023, 5:37 PM
 */

#ifndef CONFIGLCD_8BITS_H
#define	CONFIGLCD_8BITS_H

// This is a guard condition so that contents of this file are not included
// more than once.  

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

#ifndef RS
#define RS PORTEbits.RE0
#endif

#ifndef EN
#define EN PORTEbits.RE1
#endif

#ifndef D0
#define D0 PORTDbits.RD0
#endif

#ifndef D1
#define D1 PORTDbits.RD1
#endif

#ifndef D2
#define D2 PORTDbits.RD2
#endif

#ifndef D3
#define D3 PORTDbits.RD3
#endif

#ifndef D4
#define D4 PORTDbits.RD4
#endif

#ifndef D5
#define D5 PORTDbits.RD5
#endif

#ifndef D6
#define D6 PORTDbits.RD6
#endif

#ifndef D7
#define D7 PORTDbits.RD7
#endif

#include <xc.h>  

//LCD Functions Developed by electroSome

void Lcd_Port_8bits(char a);

void Lcd_Cmd_8bits(char a);

void Lcd_Clear_8bits(void);

void Lcd_Set_Cursor_8bits(char a, char b);

void Lcd_Init_8bits(void);

void Lcd_Write_Char_8bits(char a);

void Lcd_Write_String_8bits(char *a);

void Lcd_Shift_Right_8bits(void);

void Lcd_Shift_Left_8bits(void);

#endif	/* CONFIGLCD_8BITS_H */

