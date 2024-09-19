/*
 * File:   analogtodigital.c
 * Author: 91974
 *
 * Created on 4 September, 2024, 10:01 AM
 */



#include <xc.h>
#include <stdio.h>//sprintf kodukunnond
#define output_start 0 //ith ee orderil thanna ezuthanm
#define output_end 150ul
#define input_end 308ul
#define input_start 0
void delay(void);
unsigned char ar[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void main(void) 
{
    ADCON0=0X01;
    ADCON1=0X00;
    ADCON2=0X86;
    TRISC=TRISD=0X00;
    TRISA=0XFF;
   
    while(1)
   {
        int adc;
        int a;//ith eq nu vendi olla oru variable
        char cnv[15];
        GO=1;
        while(ADIF==0);
        ADIF=0;
        adc=ADRES;
        a = output_start + ((float)(output_end - output_start) / (input_end - input_start)) * (adc - input_start); //TEMP kand pidikan olla equation
        
        int rem1,rem2,rem3;
        rem1=a%10;//last digit kand pidikan
        a=a/10;//athine y 10 cheyyumbol decimal pokum
        rem2=a%10;
        a=a/10;
        rem3=a%10;
        a=a/10;
        
        PORTD=0X0E;
        PORTC=ar[0];
        delay();
        PORTD=0x0d;
        PORTC=ar[rem3];
        delay();
        PORTD=0x0b;
        PORTC=ar[rem2];
        delay();
        PORTD=0x07;
        PORTC=ar[rem1];
        delay();
    }
    return;
}
void delay(void)
{
    for(unsigned int i=0;i<100;i++);
}