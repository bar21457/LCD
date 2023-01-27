/* 
 * File:   configLCD.h
 * Author: byron
 *
 * Created on January 26, 2023, 10:59 PM
 */

#ifndef CONFIGLCD_H
#define	CONFIGLCD_H

// This is a guard condition so that contents of this file are not included
// more than once.  

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

#ifndef RS
#define RS PORTDbits.RD2
#endif

#ifndef EN
#define EN PORTDbits.RD3
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

void Lcd_Port(char a);

void Lcd_Cmd(char a);

void Lcd_Clear(void);

void Lcd_Set_Cursor(char a, char b);

void Lcd_Init(void);

void Lcd_Write_Char(char a);

void Lcd_Write_String(char *a);

void Lcd_Shift_Right(void);

void Lcd_Shift_Left(void);

#endif	/* CONFIGLCD_H */


