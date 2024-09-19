/*
 * File:   timerdelay.c
 * Author: 91974
 *
 * Created on 23 August, 2024, 9:20 AM
 */


#include <xc.h>
void delay (void);
void main(void) 
{
    //TRISC=0X00;
    TRISC=0X00;
    T0CON=0XC7;
    TMR0=00;//counter register,timer0 overflow interrupt flag no delay so 00
    while(1)
    {
      PORTC=0XFF;
      delay();
      PORTC=0X00;
      delay();
    }
    return;
}
void delay (void)
{
    while(TMR0IF==0);//TMR0IF FLAG ANN ATHINE ADYAM 1 AKUNONN NOKKANM
    {
        TMR0IF=0;//FLAG CLR CHEYYANM
        TMR0=00;//INITIAL VALUE SET CHEYYAN
    }
    
}
