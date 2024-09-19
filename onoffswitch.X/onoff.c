/*
 * File:   onoff.c
 * Author: 91974
 *
 * Created on 30 July, 2024, 12:16 PM
 */


#include <xc.h>

void main(void) 
{
  TRISC= 0X01;
  TRISD=0X00;
  int count=0;//oru extra counting variable kodukanm becuz ivde oru pressil on akanm oru pressil off akanm//
  while(1)
  {
      if(RC0==1)//adyam rco=0 arikkum blue clr so oro ms check cheyyum switch press cheyyumbm rc0=1 akum so nxt loopil pokum//
      {
          if (count==0)//count 0 anenn ondel next loopil pokum otherwise else condition//
          {
              PORTD=0X01;//count 0 anel output 0x01 akum (on) //
              count=1;//0 count 1 akum//
          }
          else
          {
              PORTD=0X00;
              count=0;
          }
          while(RC0==1);//ivide microcontroller speedil work cheyyum avde delay kond varan while//
      }
  }
    return;
}
