/*
 * File:   configLCD_8bits.c
 * Author: byron
 *
 * Created on February 1, 2023, 5:46 PM
 */

#include <xc.h>
#include "configLCD_8bits.h"

void Lcd_Port_8bits(char a) {
    if (a & 1)
        D0 = 1;
    else
        D0 = 0;

    if (a & 2)
        D1 = 1;
    else
        D1 = 0;

    if (a & 4)
        D2 = 1;
    else
        D2 = 0;

    if (a & 8)
        D3 = 1;
    else
        D3 = 0;
    
    if (a & 16)
        D4 = 1;
    else
        D4 = 0;

    if (a & 32)
        D5 = 1;
    else
        D5 = 0;
    
    if (a & 64)
        D6 = 1;
    else
        D6 = 0;

    if (a & 128)
        D7 = 1;
    else
        D7 = 0;
}

void Lcd_Cmd_8bits(char a) {
    RS = 0; // => RS = 0 // Dato en el puerto lo va interpretar como comando
    Lcd_Port_8bits(a);
    EN = 1; // => E = 1
    __delay_ms(4);
    EN = 0; // => E = 0
}

void Lcd_Clear_8bits(void) {
    Lcd_Cmd_8bits(0x01);
}

void Lcd_Set_Cursor_8bits(char a, char b) {
    char temp;
    if (a == 1) {
        temp = 0x80 + b - 1;
//        z = temp >> 4;
//        y = temp & 0x0F;
//        Lcd_Cmd(z);
//        Lcd_Cmd(y);
        Lcd_Cmd_8bits(temp);
    } else if (a == 2) {
        temp = 0xC0 + b - 1;
//        z = temp >> 4;
//        y = temp & 0x0F;
//        Lcd_Cmd(z);
//        Lcd_Cmd(y);
        Lcd_Cmd_8bits(temp);
    }
}

void Lcd_Init_8bits(void) {
    Lcd_Port_8bits(0x00);
    __delay_ms(110);
    Lcd_Cmd_8bits(0x30);
    __delay_ms(5);
    Lcd_Cmd_8bits(0x30);
    __delay_us(20);
    Lcd_Cmd_8bits(0x30);
    __delay_us(20);
    /////////////////////////////////////////////////////
    Lcd_Cmd_8bits(0x38); 
    __delay_us(55);
    Lcd_Cmd_8bits(0x08);
    __delay_us(55);
    Lcd_Cmd_8bits(0x01);
    __delay_us(55);
    Lcd_Cmd_8bits(0x06);
    Lcd_Cmd_8bits(0x0C);
}

void Lcd_Write_Char_8bits(char a) {
//    char temp, y;
//    temp = a & 0x0F;
//    y = a & 0xF0;
    RS = 1; // => RS = 1
    Lcd_Port_8bits(a); //Data transfer
    EN = 1;
    __delay_us(40);
    EN = 0;
}

void Lcd_Write_String_8bits(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++)
        Lcd_Write_Char_8bits(a[i]);
}

void Lcd_Shift_Right_8bits(void) {
    Lcd_Cmd_8bits(0x1C);
}

void Lcd_Shift_Left_8bits(void) {
    Lcd_Cmd_8bits(0x18);
}