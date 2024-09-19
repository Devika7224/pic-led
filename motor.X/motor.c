/*
 * File:   motor.c
 * Author: 91974
 *
 * Created on 1 August, 2024, 9:13 AM
 */


#include <xc.h>

void delay(void);//declaration//
void main()
{
    TRISC=0X00;
    while(1)
    {
        PORTC=0X01;
        delay();//ivide delay declare cheytathukond elladthum ath koduth ponm//
        PORTC=0X02;
        delay();
        PORTC=0X00;
        delay();
    }
} //main functionte purath venm define cheyyan//
    void delay(void)//definition//
    {
    
        for(long i=0;i<=55000;i++);
    }
    
   

