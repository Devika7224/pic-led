/*
 * File:   LEDBLINKSHORT.c
 * Author: 91974
 *
 * Created on 28 July, 2024, 11:52 AM
 */


#include <xc.h>

void main(void)
{
    TRISC = 0X00; 
    while(1)
    {
        
        for(int j=0X01;j<=0X80;j=j*2);
        {
            PORTC=j;
            for(unsigned int i = 0; i < 55000; i++);
        }
    }
    return;
}
