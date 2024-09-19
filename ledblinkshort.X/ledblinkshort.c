/*
 * File:   ledblinkshort.c
 * Author: 91974
 *
 * Created on 29 July, 2024, 9:13 AM
 */


#include <xc.h>

void main(void) 
{
   
    TRISC = 0X00; 
    while(1)
    {
        
        for(int j=0X80;j>=0X01;j=j/2)
        {
            PORTC=j;
            for(unsigned int i = 0; i < 55000; i++);
        }
    }
    return;
}

   
