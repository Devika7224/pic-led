/*
 * File:   lcdmotor2.c
 * Author: 91974
 *
 * Created on 5 August, 2024, 9:49 AM
 */


#include <xc.h>
void cmd(unsigned char a );
void data(unsigned char b );
void display(const char *p);
 void delay(void);
void main(void) 
{
     TRISC=0X30;
     TRISD=0X00;
     TRISB=0X00;
    cmd(0x01);
    cmd(0x0F);//ITH DISPLAY ON AKAN OLLATH ith koduthillel display cheyyulla//
    int count=-1;//DIFF PORT AKUMBM SAME COUNT AYALUM MATHI//
while(1)
{
     if(RC4==1)
        {
            if(count==2)
            {
                count=-1;
            }
            count++;
            while(RC4==1);
            cmd(0x01); 
     if(count==0)
     {
         PORTB=0X01;
         display("CLOCKWISE");
         
     }
      else if(count==1)
            {
          PORTB=0X02;
          display("ANTICLOCKWISE");
           
        
}
      else if(count==2)
      {
          PORTB=0X03;
          display("STOP"); 
          
      }
     }
     
     {
     if(RC5==1)
        {
            if(count==2)
            {
                count=-1;
            }
            count++;
            while(RC5==1);
            cmd(0x01); //0x01 koduthillel crt display akulla 0x06 okka koduthal evdem thott anoo kodukkunne aa bit thotte display aku//
     if(count==0)
     {
         PORTB=0X04;
         display("CLOCKWISE");
         
     }
      else if(count==1)
            {
          PORTB=0X08;
          display("ANTICLOCKWISE");
           
        
}
      else if(count==2)
      {
          PORTB=0X60;
          display("STOP"); 
          
}
     }
     }
}
    return;
     
}



void cmd(unsigned char a )
{
    RC0=0;//clear command kodukkan rs=0
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);
}
void data(unsigned char b )
{
    RC0=1;//data display cheyyaan display cheyyaan rc0=rs=1
    RC1=0;
    PORTD=b;
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
