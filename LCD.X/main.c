/*
 * File:   main.c
 * Author: byron
 *
 * Created on January 26, 2023, 8:42 PM
 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits 
                                            // (INTOSC oscillator: I/O function 
                                            // on RA6/OSC2/CLKOUT pin, I/O 
                                            // function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and 
                                // can be enabled by SWDTEN bit of the WDTCON 
                                // register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR 
                                // pin function is digital input, MCLR 
                                // internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code 
                                // protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code 
                                // protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit 
                                // (Internal/External Switchover mode disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit 
                                // (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin 
                                // has digital I/O, HV on MCLR must be used for 
                                // programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out 
                                // Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits 
                                // (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "configINTOSC.h"
#include "configADC.h"
#include "configLCD_4bits.h"

#define _XTAL_FREQ 8000000

#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RB5
#define D6 RD6
#define D7 RD7

void setup(void);

void main(void) {
    
  int OsciladorInterno;
  char ADC1[3];
  char ADC2[3];
  
  setup();
  setupINTOSC(8);
  setupADC(0);
  setupADC(1);
  Lcd_Init();
  
  while(1)
  {
      Lcd_Clear();
      Lcd_Set_Cursor(1,3);
      Lcd_Write_String("S1:");
      Lcd_Set_Cursor(1,7);
      Lcd_Write_String("S2:");
      
      readADC(0);
      
      sprintf(ADC1, "%d", ADRESH);
      Lcd_Set_Cursor(2,3);
      Lcd_Write_String(ADC1);
      
      readADC(1);
      
      sprintf(ADC2, "%d", ADRESH);
      Lcd_Set_Cursor(2,7);
      Lcd_Write_String(ADC2);
  }
    return;
}

//******************************************************************************
// Función para configurar GPIOs
//******************************************************************************
void setup (void){
    
    ANSEL = 0;
    ANSELH = 0;
    
    TRISB = 0;              //Configuración del PORTB como input
    TRISC = 0;              //Configuración del PORTC como output
    TRISD = 0;              //Configuración del PORTD como output
    TRISE = 0;              //Configuración del PORTE como output
    
    PORTB = 0;              //Limpiamos el PORTB
    PORTC = 0;              //Limpiamos el PORTC
    PORTD = 0;              //Limpiamos el PORTD
    PORTE = 0;              //Limpiamos el PORTD
}