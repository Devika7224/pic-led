/*
 * File:   function.c
 * Author: 91974
 *
 * Created on 14 August, 2024, 10:15 AM
 */


#include <xc.h>
void transmission (void);
void main(void) 
{
    TRISC=0X00;//note book
    TXSTA =0X24;
    RCSTA =0X90;
    SPBRG=129;
    BAUDCON=0X00;
    transmission();
    return;
}
void transmission (void)//definition
{
   TXREG='A';//transmit registerilott character A ne load cheyyunnu
    while(TXIF==0);//flaginn wait cheyyunnu; 
    TXIF=0; 
}