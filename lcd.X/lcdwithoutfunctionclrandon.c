/*
 * File:   lcdwithoutfunctionclrandon.c
 * Author: 91974
 *
 * Created on 2 August, 2024, 9:38 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0X00;
    TRISD=0X00;
    RC0=0;//R0//
    RC1=0;//RW=0//
    PORTD=0X01;//D0 MATRAM ON//
    RC2=1;//ENABLE PIN ON//
    for(int i=0;i<=100;i++);//enableinte delay //
    RC2=0;
    for(int i=0;i<=5000;i++);//IVIDEMARA CLEAR AKAN OLLATH//
    RC0=0;//ON AKAN OLLATH//
    RC1=0;
    PORTD=0X0F;
    RC2=1;//ENABLE PIN ON//
    for(int i=0;i<=100;i++);//enableinte delay //
    RC2=0;
    for(int i=0;i<=5000;i++);
    
       
        
    return;
}
