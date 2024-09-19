/*
 * File:   DISPLAY.c
 * Author: 91974
 *
 * Created on 30 August, 2024, 9:31 AM
 */
#include <xc.h>
void delay(void);

void main(void) 
{
    TRISC=0x00;
    TRISD=0X00;
    TRISB=0X01;
    PORTD=0X00;
    PORTB=0XFF;
    
    ADCON1=0X0F;
    int j,l,m,n;
    
    unsigned char a[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//evide venelum kodkkam maininta akath kodthal local
    
    while(1)
    {
        
         PORTD=0x0e;
         PORTC=a[n];
         delay();
         PORTD=0x0d;
         PORTC=a[m];
         delay();
         PORTD=0x0b;
         PORTC=a[l];
         delay();
         PORTD=0x07;
         PORTC=a[j];
         delay();
         
        if(RB0==1)//switch press cheythal
        {
            j++;//j++ akum   j right sideile bit ann ath venm adym 1 akan
            if(j==10)//j 10 anel next loopil pokum
            {
            j=0;//10 anel 0 akkum
            l++;//then next digitilott pokum ath increment cheythond irikkum
            if(l==10)// l 10 ayonn nokkum
            {
            l=0;// 10 ayal 0 akkum then next digitilott pokum
            m++;
            if(m==10)
            {
            m=0;
            n++;
            if(n==10)
            {
            n=0;
            return;    
                }
            }
                }
            }
            while(RB0==1)//repear akatha irikkan
            {
                PORTD=0x0e;
                PORTC=a[n];
                delay();
                PORTD=0x0d;
                PORTC=a[m];
                delay();
                PORTD=0x0b;
                PORTC=a[l];
                delay();
                PORTD=0x07;
                PORTC=a[j];
                delay();

            }
            }
        }
    return;
}
        
void delay(void)
{
    for(unsigned int i=0;i<1000;i++);
}