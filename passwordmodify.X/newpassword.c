/*
 * File:   newpassword.c
 * Author: 91974
 *
 * Created on 13 August, 2024, 10:00 AM
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
    
   
    PORTB=0X0E;
    
       if(RB7==0)
       {
            //cmd(0X83);//cmd(0X01);
            cmd(0x10);//LEFT SHIFT
          display(" ");
           cmd(0x10);// SPACE VARUNNADTH THIRICH CURSOR KOND VARAN
           while(RB7==0);
            
       }
       PORTB=0X0D;
       
       
        if(RB7==0)
       {
            cmd(0X87);cmd(0X01);
            
            while(RB7==0);
       }
       
       PORTB=0X0B;
       
      
        if(RB7==0)
       {
            cmd(0X8B);cmd(0X01);
            
           
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
        if(RB6==0)
       {
            cmd(0X8E);cmd(0X01);
            
           cmd(0x01);
           while(RB6==0);
       }
        else if(RB7==0)
       {
            cmd(0X8F);cmd(0X01);
            
          
           while(RB7==0);
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
        return '7';
    }
    else if(RB5==0)
    {
        return '8';
    }
    else if(RB6==0)
    {
        return '9';
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
    
    PORTB=0X0B;
     if(RB4==0)
    {
         return '1';
    }
    else if(RB5==0)
    {
        return '2';
    }
    else if(RB6==0)
    {
        return '3';
    }
    
    PORTB=0X07;
    
    if(RB5==0)
    {
        return '0';
    }
    
    }
}