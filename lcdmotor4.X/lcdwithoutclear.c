/*
 * File:   lcdmotor4.c
 * Author: 91974
 *
 * Created on 6 August, 2024, 9:47 AM
 */



    #include <xc.h>
void cmd(unsigned char a );
void data(unsigned char b );
void display(const char *p);
void main(void) {
       TRISC=0X30;
     TRISD=0X00;
     TRISB=0X00;
      cmd(0x01);//lcd clear
    cmd(0x0f);//lcd display enable cheyyaan
    cmd(0x38);//two line enable cheyyaan
    
      int c1=-1,c2=-1;//declaration and initializing
    while(1){
        cmd(0x0C);
        if(RC4==1)
        {
            if(c2==2)
            {
                c2=-1;
            }
            c2++;
            while(RC4==1);
           cmd(0xC0);
         if(c2==0)
            {
            RB0=1; RB1=0;
             display("MOTOR2CLOCKWISE ");
            }
else if(c2==1)
            {
            RB0=0; RB1=1;
             display("MOTOR2ANTICLOCK");
            }
            else  if(c2==2)
            {
                RB0=0; RB1=0; 
                 display("MOTOR2STOP      ");//ANTICLOCK bhaakii display kaanikkathe irikkaan
            }
        }
        if(RC5==1)
        {
            if(c2==2)
            {
                c2=-1;
            }
            c2++;
            while(RC5==1);
           cmd(0xC0);
         if(c2==0)
            {
            RB2=1; RB3=0;
             display("MOTOR2CLOCKWISE ");
            }
else if(c2==1)
            {
            RB2=0; RB3=1;
             display("MOTOR2ANTICLOCK");
            }
            else  if(c2==2)
            {
                RB2=0; RB3=0; 
                 display("MOTOR2STOP      ");//ANTICLOCK bhaakii display kaanikkathe irikkaan
            }
        }}
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