/*
 * File:   function3.c
 * Author: 91974
 *
 * Created on 20 August, 2024, 9:18 AM
 */


#include <xc.h>

void transmission (char a);
void main (void)
{
    
   char a[6]="devika";
    TRISC=0X00;//note book
    TXSTA =0X24;
    RCSTA =0X90;
    SPBRG=129;
    BAUDCON=0X00;
    for(int i=0;i<=5;i++)
    {
    transmission (a[i]);
    }
    while(1);
    
}
void transmission(char a)
{
    TXREG=a;//transmit registerilott character A ne load cheyyunnu
    while(TXIF==0);//flaginn wait cheyyunnu; 
    TXIF=0; 

}