/*
 * File:   receptionwithlcd.c
 * Author: 91974
 *
 * Created on 20 August, 2024, 10:02 AM
 */


#include <xc.h>

void cmd(unsigned char a );
void data(unsigned char a );
void display (const char *p);
void main(void) 
{
   
    TRISC=0X80;
    TRISD=0X00;
    
    TXSTA =0X24;
    RCSTA =0X90;
    SPBRG=129;
    BAUDCON=0X00;
   
    char w;//ivide rcreg oru buffer ann so athinn del ayi pokum so oru variableil store cheyth vekkanm
    cmd(0X01);
    cmd(0X0F);
    cmd(0x80);
    cmd(0X06);
    
    while(1)
    {
    while(RCIF==0);
    w = RCREG;
    data(w);
    }
    return;
}

void cmd(unsigned char a )
{
    RC0=0;
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);
}
void data(unsigned char a )
{
    RC0=1;
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);
}
void display(const char *p)
{
    while(*p)
    {
        data(*p);
        p++;
    }    
}
