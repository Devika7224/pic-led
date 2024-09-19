/*
 * File:   ADC LCD.c
 * Author: 91974
 *
 * Created on 4 September, 2024, 9:57 AM
 */


#include <xc.h>
void cmd(unsigned char a );
void data(unsigned char a );
void display(const char *p);

void main(void) 
{
    TRISC=0X00;
    TRISD=0X00;
    cmd(0x01);
    cmd(0x0f);
    display("ADC");
    while(1);
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