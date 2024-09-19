/*
 * File:   betweentocharacters.c
 * Author: 91974
 *
 * Created on 21 August, 2024, 5:22 PM
 */


#include <xc.h>

char receive(void);
void trans(unsigned char a );
void main(void) 
{
    TRISD = 0X00;
    TRISC = 0X80;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129; 
char w;//w nn parayanna variable koduthu
    int start = 0;  // Flag to control transmission
    while(1)
    {
        w = receive();//receive cheyyunnath w
        if (w == '*') //receive cheythath * anel transmit cheyyanm
        {
            start = 1;// Start transmission when '*' is received
        } 
        else if (w == '#') 
        {
           start = 0;// Stop transmission when '#' is received
        } 
        else if (start) 
        {
            trans(w);// Only transmit if within '*' and '#'
        }
    }
}
char receive(void)
{
    while(RCIF == 0);
    return RCREG;
}

void trans(unsigned char a) 
{
    TXREG = a;
    while(TXIF == 0);
    TXIF = 0;
}