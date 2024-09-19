/*
 * File:   LED__.c
 * Author: 91974
 *
 * Created on 28 July, 2024, 2:05 PM
 */


#include <xc.h>

void main(void) 
{
    
    TRISC=0X00;
    while(1)
    {
        for(int i=0;i<=8;i++)
        {
            PORTC=1<<i;
            for(unsigned int i =0;i<65000;i++);
        }
    }
    return;
}
    
