/*
 * File:   TWOPORT2.c
 * Author: 91974
 *
 * Created on 29 July, 2024, 10:28 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0X00;
    TRISD=0X00;
    while(1)
    {
        for(int j=0X01;j<=0X80;j=j*2)
            
        {
            PORTC=j;
            for(unsigned int i=0;i<=55000;i++);
        }
            PORTC=0X00;//PORTC THERNITT ADTHATH KATHAN//
    
    
        for(int j=0X80;j>=0X01;j=j/2)
            
        {
            PORTD=j;
            for(unsigned int i=0;i<=55000;i++);
        }
            PORTD=0X00;
    }
    return;
}
