/*
 * File:   pushbuttonmotor.c
 * Author: 91974
 *
 * Created on 1 August, 2024, 9:43 AM
 */


#include <xc.h>
  void main(void) 
  {
      TRISC=0x01;
      TRISD=0x00;
      int count=-1;//1 koduthal pinna count increment cheyyumbm
    while(1)
    {
        if(RC0==1)
        {
            if(count==2)
            {
                count=-1;
            }
            count++;
            
            while(RC0==1);
        }
         if(count==0)
            {
            PORTD=0X01;
            
            }
            else if(count==1)
            {
            PORTD=0X02;
            
            }
            else  if(count==2)
            {
             PORTD=0X00;   
                
            }
    }
  return;
  }