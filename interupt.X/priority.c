/*
 * File:   priority.c
 * Author: 91974
 *
 * Created on 21 August, 2024, 5:55 PM
 */


#include <xc.h>
void delay(void);//delay kodukkan adyam declare cheythitt delay varunna elladthum call cheytha mathy
void main(void)
{
   
    TRISC = TRISD=0X00; 
    TRISB=0X01;
    ADCON1=0X0F;//ANALOF TO DIGITAL
    INTCON=0XD0;//interrupt ayathukond
    //led blink operation
    while(1)
    {
      PORTC=0XFF;
      delay();//elladthum delay call cheythu
      PORTC=0X00;
      delay();
    }


}
//interrupt (shift operation) eppozum main function purath venm kodukkan
void __interrupt() ISR()
{
    int i;
    if (INT0IF==1)//flag
    {
        PORTD=0X01;//Adyam oru bit set cheyth kodukkanm
        
        delay();
        for(i=0;i<7;i++)
        {
            PORTD<<=1;//shift
            delay();
        }
        INT0IF=0;//thirich flag set cheythu
    } 
  
}
void delay(void)//definition
{
    for(int i=0;i<300;i++)
    {
        for(int j=0;j<300;j++);
    }
}
    


