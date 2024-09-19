/*
 * File:   withfunction.c
 * Author: 91974
 *
 * Created on 2 August, 2024, 9:54 AM
 */


#include <xc.h>

void display(unsigned char a);//DEFINITION//
    void main(void) 
    {
    TRISC=TRISD=0X00;
    display(0X01);//MATTAM OLLATH MATRAM IVIDE KODUTHU//
    display(0X0F); 
    return;
}
    void display(unsigned char a)//DECLARATION//
    {
    RC0=0;
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);//THAZA DELAY KUDUTHAL VENM BECUZ DELAY CLR AKAN TIME VENM//
    }