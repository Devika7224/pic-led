/*
 * File:   display 1.c
 * Author: 91974
 *
 * Created on 30 August, 2024, 9:13 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0X00;
    
    while(1)
    {
        PORTC=0X02;
        PORTC=0X04;
    }
    return;
}
