/*
 * File:   pwm.c
 * Author: 91974
 *
 * Created on 28 August, 2024, 8:52 AM
 */


#include <xc.h>

void main (void)
{
    TRISC=0X00;
    T1CON=0X31;
    CCP1CON=0X02;
    CCPR1H=0X20;
    CCPR1L=0X10;
    
    while(1)
    {
        
    }
    
}
