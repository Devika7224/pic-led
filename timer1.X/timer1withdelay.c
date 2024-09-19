/*
 * File:   timer1withdelay.c
 * Author: 91974
 *
 * Created on 26 August, 2024, 9:19 AM
 */


#include <xc.h>
void delay (void);
int a;
#define fosc 20000000
#define pre 8
#define del 0.1
#define max 65536
#define a max-((int)(fosc*del)/(4*pre));//equation ivde direct kodukkam tycast syntax type_name
void main(void)
{
    //TRISC=0X00;
    TRISC=0X00;
    T1CON=0X31;
    TMR1=a;//counter register,timer0 overflow interrupt flag no delay so 00
    
    while(1)
    {
      PORTC=0XFF;
      delay();
      PORTC=0X00;
      delay();
    }
    return;
}
void delay (void)
{
    while(TMR1IF==0);//TMR0IF FLAG ANN ATHINE ADYAM 1 AKUNONN NOKKANM
    {
        TMR1IF=0;//FLAG CLR CHEYYANM
        TMR1=a;//INITIAL VALUE SET CHEYYAN
    }
    
}
