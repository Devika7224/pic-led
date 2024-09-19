/*
 * File:   RIGHTSCROLL.c
 * Author: 91974
 *
 * Created on 7 August, 2024, 10:12 AM
 */


#include <xc.h>
void cmd(unsigned char a );
void data(unsigned char a );
void display(const char *p);

void main(void)
{
TRISC=0X00;
TRISD=0X00;
cmd(0x0f);//ITH DISPLAY OFF AKAN//
cmd(0x0c);//cursor off akan//
cmd(0x93);//FIRST bit lottu pokan vndittu A7-NUMBER OF CHARACTERS//
display("HELLOWORLDANDME");
while(1)//ith kodthillel or screenil per vnnond irikm//
{
                for(int i=0;i<31;i++)//ivide total 16 bit anu ullathu so athinte koode nmml kodthekkuna NAMEINTA LETTER  koode add chynm athanu for loop ilu i < kodthekkna num//
                {
                cmd(0x1C); //RIGHT shift//
                 
                 for(long i=0;i<=30000;i++);
                }
                cmd(0x02);//home cmnd lcd reset chayan ulla //
            }

return;

}
void cmd(unsigned char a )
{
    RC0=0;
    RC1=0;//data enable cheyyan vnditu 2m 0 kodkunn//
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);
}
void data(unsigned char a )
{
   
    RC0=1;//rs=0//
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
