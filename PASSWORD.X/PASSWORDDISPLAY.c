/*
 * File:   PASSWORDDISPLAY.c
 * Author: 91974
 *
 * Created on 12 August, 2024, 10:22 AM
 */


#include <xc.h>
#include <string.h>

unsigned char keypad(void);
void cmd(unsigned char a); //function declaration
void data(unsigned char a);
void display(const char *p);
char pass[]="1234",inp[]="0000";//char password array,nammal adikkunath store cheyyan inp[] koduthu//
unsigned char index=0;//input kodukkumbol position ariyan(adikkanna passwordinta position ariyan//
void main(void) 
{
    ADCON1=0X0F;
    TRISB=0XF0; //1111 0000
    TRISC=TRISD=0X00;
    cmd(0x38);
    cmd(0x01);
    cmd(0x0f);
    cmd(0x80);//first line//
              
    while(1)
    {
        cmd(0x01);//first clean cheyyanm lcd//
        display("Enter Password");
        cmd(0xc0);//next line//
        for(index=0;index<4;index++)
        {
         inp[index]=keypad();//nammal kodukkunna input arraylott save cheyyn//
         data(inp[index]);//ee indexina lcdlott snd cheyyn//
         while(RB4==0 || RB5==0 || RB6==0 || RB7==0 );
        }
        if(strcmp(inp,pass)==0)
        {
             for(long i=0;i<=100000;i++);
            cmd(0x01);
            display("Password Correct");
            for(long i=0;i<=1000000;i++);
        }
        else
        {
            for(long i=0;i<=100000;i++);
            cmd(0x01);
            display("Password Wrong");
            for(long i=0;i<=1000000;i++);
        }
    }
    return;
}

void cmd(unsigned char a)//function definition
{
     RC0=RC1=0;
    PORTD=a; 
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
     for(int i=0;i<=10000;i++);
}
void data(unsigned char a) //function definition
{
    RC0=1;
     RC1=0;
     PORTD=a; 
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0; 
    for(int i=0;i<=10000;i++);
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
    while(1)
    {
    PORTB=0X0E;
    if(RB4==0)
    {
        return '0';
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