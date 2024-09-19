/*
 * File:   project1.c
 * Author: 91974
 *
 * Created on 14 August, 2024, 9:57 AM
 */


#include <xc.h>

void main(void) 
{
    TRISC=0X00;//note book
    TXSTA =0X24;
    RCSTA =0X90;
    SPBRG=129;
    BAUDCON=0X00;
    TXREG='A';
    while(TXIF==0);
    TXIF=0;//Flag clear cheyyan
    return;
}
