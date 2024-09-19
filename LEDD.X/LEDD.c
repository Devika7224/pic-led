/*
 * File:   LEDD.c
 * Author: 91974
 *
 * Created on 28 July, 2024, 2:10 PM
 */


#include <xc.h>

void main(void)
{
    TRISC = 0X00; 
    while(1)
    {
        
        for(PORTC = 0X80; PORTC >= 0X01; PORTC >>= 1);
        {
            
            for(unsigned int i = 0; i < 55000; i++);
        }
    }
    return;
}

    return;
}
