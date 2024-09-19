/*
 * File:   oneafteranother.c
 * Author: 91974
 *
 * Created on 29 July, 2024, 7:33 PM
 */


#include <xc.h>
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    while(1)
    {
        PORTC=0X01;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X03;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X07;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X0F;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X1F;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X3F;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X7F;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0XFF;
        for(unsigned int i=0;i<55000;i++);
        PORTC=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X01;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X03;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X07;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X0F;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X1F;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X3F;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X7F;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0XFF;
        for(unsigned int i=0;i<55000;i++);
        PORTD=0X00;
        for(unsigned int i=0;i<55000;i++);
    }
}
    
