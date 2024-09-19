/*
 * File:   twomotor.c
 * Author: 91974
 *
 * Created on 1 August, 2024, 10:32 AM
 */


#include <xc.h>

  void main(void) 
  {
      TRISC=0X03;
     
      int c1=-1,c2=-1;//SAME PORT DIFFERENT COUNT//
    while(1)
    {
        if(RC0==1)
        {
            if(c1==2)
            {
                c1=-1;
            }
            c1++;
            while(RC0==1);
         if(c1==0)
            {
            RC2=1; RC3=0;
            
            }
else if(c1==1)
            {
            RC2=0; RC3=1;
            
            }
            else  if(c1==2)
            {
                RC2=0; RC3=0;  
            }}
        if(RC1==1)
        {
            if(c2==2)
            {
                c2=-1;
            }
            c2++;
            while(RC1==1);
        
         if(c2==0)
            {
            RC4=1; RC5=0;
            
            }
else if(c2==1)
            {
            RC4=0; RC5=1;
            
            }
            else  if(c2==2)
            {
                RC4=0; RC5=0;  
            }
        }
    }
      return;
  }