/*
 * File:   calculatorwithfunc.c
 * Author: 91974
 *
 * Created on 12 August, 2024, 9:50 AM
 */
#include <xc.h>
unsigned char keypad(void);// varunna variable create cheyyunnu
void cmd(unsigned char a);
void data(unsigned char a);
void display(const char *p);
void main(void)
{
    ADCON1=0X0F;//ANALOG TO DIGITAL AKKAN
    TRISB=0XF0;//FIRST 4 PIN 1 NEXT 4 0 BECUZ first 4 O\P PIN ANN 1111 0000 ivide pull up resistor ann use cheyyunnath
    TRISC=0X00;//output
    TRISD=0X00;//OUTPUT
    cmd(0x0F);//ON
    cmd(0X38);//8 bit enable cheyyan, new line,5 by 7 lcd
    cmd(0X01);
    while(1)
    {
        unsigned char a;//a enn parayunna oru character koduthu
        a=keypad();//FUNCTION AYATHUKOND BRACKET OPEN CLOSE, aa varunna character enduann paranj kodukkan 
        data(a);//a ne display cheyyan
         while(RB4==0||RB5==0||RB6==0||RB7==0 );//hold cheyyan orumich koduthekkunn   
    }
return ;
}
void cmd(unsigned char a)//function definition
{
     RC0=RC1=0;
    PORTD=a; 
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
     for(int i=0;i<=5000;i++);
}
void data(unsigned char a) //function definition
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
unsigned char keypad(void)
{
    while(1)// oro vettavum return akannond loopil varan
    {
    PORTB=0X0E;
    if(RB4==0)
    {
        return '0';//condition satisfy ayal character ayitt o return akum aa 0 ail store akum ath data(a) il pokum angana display akum//
    }
    else if(RB5==0)
    {
        return '1';
    }
    else if(RB6==0)
    {
        return '2';
    }
    else if(RB7==0)
    {
        return '3';
    }
    PORTB=0X0D;
     if(RB4==0)
    {
         return '4';
    }
    else if(RB5==0)
    {
        return '5';
    }
    else if(RB6==0)
    {
        return '6';
    }
    else if(RB7==0)
    {
        return '7';
    }

PORTB=0X0B;
     if(RB4==0)
    {
         return '8';
    }
    else if(RB5==0)
    {
        return '9';
    }
    else if(RB6==0)
    {
        return 'A';
    }
    else if(RB7==0)
    {
        return 'B';
    }
    PORTB=0X07;
    if(RB4==0)
    {
        return 'C';
    }
    else if(RB5==0)
    {
        return 'D';
    }
    else if(RB6==0)
    {
        return 'E';
    }
    else if(RB7==0)
    {
        return 'F';
    }
}
}
