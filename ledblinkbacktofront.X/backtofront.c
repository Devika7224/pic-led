/*
 * File:   backtofront.c
 * Author: 91974
 *
 * Created on 29 July, 2024, 9:34 AM
 */

#include <xc.h>
void main(void) 
{
   
    TRISC=0X00; 
    while(1)
    {
        
        for(int j=1;j<=128;j=j*2)
        {
            PORTC=j;
            for(unsigned int i = 0; i < 55000; i++);
        }
    }
    return;
}
