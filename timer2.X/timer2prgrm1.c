/*
 * File:   timer2prgrm1.c
 * Author: 91974
 *
 * Created on 27 August, 2024, 7:18 PM
 */


#include <xc.h>
void delay(void);
 int a;
void main(void) {

    TRISC=0X00;
    T2CON=0X7E;//TIMER CONFIGURE
    PR2=255;
  
     while(1)
    {
            PORTC=0XFF;
            delay();
            PORTC=0X00;
            delay();
    }
    return;
}
void delay(void)
{
   
    while(TMR2IF==0);//FLAG 1 AANONN CHECK CHEYYAAN(OVERFLOW AAYONNN ARYAAN)
    TMR2IF=0;//1 AAYAL 0 AAKAAN
       PR2=255;
}
 //eqn idumbo float varum athukond nammakk int aakkanm so type cast