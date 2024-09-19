/*
 * File:   led blink.c
 * Author: 91974
 *
 * Created on 26 July, 2024, 9:51 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0X00;
    while(1)
    {
        PORTC=0X80;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X40;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X20;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X10;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X08;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X04;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X02;
         for(unsigned int i=0;i<=60000;i++);
         PORTC=0X01;
         for(unsigned int i=0;i<=60000;i++);
        
    }
    return;
}
