/*
 * File:   calculatorlcd.c
 * Author: 91974
 *
 * Created on 9 August, 2024, 9:28 AM
 */


#include <xc.h>
void cmd(unsigned char a);
void data(unsigned char a);
void display(const char *p);
void main(void)
{
    ADCON1=0X0F;//ANALOG TO DIGITAL AKKAN//
    TRISB=0XF0;//FIRST 4 PIN 1 NEXT 4 0 BECUZ first 4 O\P PIN ANN 1111 0000 ivide pull up resistor ann use cheyyunnath //
    TRISC=0X00;//output//
    TRISD=0X00;//OUTPUT//
    cmd(0x0F);//ON//
    cmd(0X0C);//CURSOR OFF DISPLAY ON//
    int count=0;
    while(1)
    {
    PORTB=0X0E;
    if(RB4==0)
       {
       
           //cmd(0X80);//cmd(0X01);//CLEAR CHEYYN//
           display("7");
           while(RB4==0);//while koduthal switch press cheyyumbol matram oru vettam print akathe ollu RB4 PORT 0X0E on akanna timeil matram display akum//
        }
        else if(RB5==0)
       {
            
           //cmd(0X81);//cmd(0X01);
           display("8");
           while(RB5==0);
       }
        else if(RB6==0)
       {
            
            //cmd(0X82);//cmd(0X01);
            display("9");
            while(RB6==0);
       }
        else if(RB7==0)
       {
            //cmd(0X83);//cmd(0X01);
            cmd(0x10);//LEFT SHIFT
          display(" ");
           cmd(0x10);// SPACE VARUNNADTH THIRICH CURSOR KOND VARAN
           while(RB7==0);
            
       }
       PORTB=0X0D;
       
       if(RB4==0)
       {
           //cmd(0X84);//cmd(0X01);
           display("4");
           while(RB4==0);
       }
        else if(RB5==0)
       {
            //cmd(0X85);//cmd(0X01);
            display("5");
            while(RB5==0);
       }
        else if(RB6==0)
       {
            //cmd(0X86);//cmd(0X01);
            display("6");
            while(RB6==0);
       }
        else if(RB7==0)
       {
            //cmd(0X87);//cmd(0X01);
            
            while(RB7==0);
       }
       
       PORTB=0X0B;
       
       if(RB4==0)
       {
           //cmd(0X88);//cmd(0X01);
           
           display("1");
           while(RB4==0);
          
       }
        else if(RB5==0)
       {
            //cmd(0X89);//cmd(0X01);
           
           display("2");
           while(RB5==0);
       }
        else if(RB6==0)
       {
            //cmd(0X8A);//cmd(0X01);
            
           display("3");
           while(RB6==0);
       }
        else if(RB7==0)
       {
            //cmd(0X8B);//cmd(0X01);
            
           
           while(RB7==0);
       }
       
       PORTB=0X07;
       
        if(RB4==0)
    {
        if(count==0)
        {
            cmd(0x08);//DISPLAY OFF
            while(RB4==0);
             count++;
    }
        else if(count==1)
        {
            cmd(0x0E);//DISPLAY ON
             while(RB4==0);
             count=0;
        }
        }
        else if(RB5==0)
       {
           //cmd(0X8D);// cmd(0X01);
           
           display("0");
           while(RB5==0);
       }
        else if(RB6==0)
       {
            //cmd(0X8E);//cmd(0X01);
            
           cmd(0x01);
           while(RB6==0);
       }
        else if(RB7==0)
       {
            //cmd(0X8F);//cmd(0X01);
            
          
           while(RB7==0);
       }
    }
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

