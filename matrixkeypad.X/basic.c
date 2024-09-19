/*
 * File:   basic.c
 * Author: 91974
 *
 * Created on 8 August, 2024, 9:48 AM
 */


#include <xc.h>

void main(void)
{
    ADCON1=0X0F;//ANALOG TO DIGITAL AKKAN//
    TRISB=0XF0;//FIRST 4 PIN 1 NEXT 4 0 BECUZ first 4 O\P PIN ANN 1111 0000 ivide pull up resistor ann use cheyyunnath //
    TRISC=0X00;//output//
    while(1)
    {
        PORTB=0X0E;//0000 1110 o\p ile oru pin 0 bakki ellam 1 ayitt kodukkanm//
        if(RB4==0)//ivide RB4 thott i\p ann so adym first switch on akkanm pull down circuit ayathukond switch press cheyyumbol 0//
        {
            RC0=1;//RC0 led ON akanm//
        }
        else if(RB5==0)//next switch press cheyyanm//
        {
            RC1=1;
        }
        else if(RB6==0)
        {
            RC2=1;
        }
        else if(RB7==0)
        {
            RC3=1;
        }
        PORTB=0X0D;//next o\p pin on akkanm 0000 1101 akkanm//
        if(RB4==0)
        {
            RC4=1;
        }
        else if(RB5==0)
        {
            RC5=1;
        }
        else if(RB6==0)
        {
            RC6=1;
        }
        else if(RB7==0)
        {
            RC7=1;
        }
        PORTB=0X0B;//0000 1011//
        if(RB4==0)
        {
            RC0=0;
        }
        else if(RB5==0)
        {
            RC1=0;
        }
        else if(RB6==0)
        {
            RC2=0;
        }
        else if(RB7==0)
        {
            RC3=0;
        }
        PORTB=0X07;//0000 0111//
        if(RB4==0)
        {
            RC4=0;
        }
        else if(RB5==0)
        {
            RC5=0;
        }
        else if(RB6==0)
        {
            RC6=0;
        }
        else if(RB7==0)
        {
            RC7=0;
        }
    }
    return;
}
