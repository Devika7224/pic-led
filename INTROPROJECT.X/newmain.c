/*
 * File:   newmain.c
 * Author: 91974
 *
 * Created on 24 July, 2024, 9:51 AM
 */


#include <xc.h>

void main(void)
{
    TRISC=0X00;

while(1)
{
    PORTC=0XFF;
    PORTC=0X00;
}
return;
}
