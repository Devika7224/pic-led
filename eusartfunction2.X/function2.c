/*
 * File:   function2.c
 * Author: 91974
 *
 * Created on 20 August, 2024, 8:56 AM
 */


#include <xc.h>
void transmission ( char a);
void main (void)
{
    TRISC=0X00;//note book
    TXSTA =0X24;
    RCSTA =0X90;
    SPBRG=129;
    BAUDCON=0X00;
    transmission ('a');
    while(1);
}
void transmission(char a)
{
    TXREG= a;//transmit registerilott character A ne load cheyyunnu
    while(TXIF==0);//flaginn wait cheyyunnu; 
    TXIF=0; 
    
}