/*
 * File:   pushbutton.c
 * Author: 91974
 *
 * Created on 30 July, 2024, 9:18 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0XFF;
    TRISD=0X00;
    while(1)
    {
        if(RC0==1)
        {
            PORTD=0XFF;
        }
        else
        {
            PORTD=0X00;
        }
    }
        
    
    return;
}
