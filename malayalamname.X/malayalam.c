/*
 * File:   malayalam.c
 * Author: 91974
 *
 * Created on 20 August, 2024, 6:36 PM
 */


#include <xc.h>


void cmd(unsigned char a);
void data(unsigned char a);
void display(const char *p);
void createCustomChar(unsigned char location, unsigned char *pattern);


unsigned char char_a1[8] = {
  0x1E,
  0x12,
  0x1E,
  0x10,
  0x1E,
  0x12,
  0x1E,
  0x00
};
unsigned char char_a2[8] = {
  0x1F,
  0x11,
  0x11,
  0x17,
  0x11,
  0x11,
  0x17,
  0x00
};
unsigned char char_a3[8] =  {
  0x1D,
  0x15,
  0x15,
  0x15,
  0x15,
  0x15,
  0x17,
  0x00
};
unsigned char char_a4[8] = {
  0x1E,
  0x12,
  0x02,
  0x02,
  0x02,
  0x02,
  0x02,
  0x00
};
unsigned char char_a5[8] = {
  0x03,
  0x02,
  0x02,
  0x0F,
  0x0A,
  0x0E,
  0x03,
  0x00
};
unsigned char char_a6[8] ={
  0x1C,
  0x04,
  0x04,
  0x1F,
  0x05,
  0x05,
  0x1D,
  0x00
};

void main(void) 
{
    TRISC = TRISD = 0x00; // Set PORTC and PORTD as output
    cmd(0x01);  // Clear display
    cmd(0x0F);  // Display ON, cursor ON, blink cursor ON
    
    createCustomChar(0, char_a1); 
    createCustomChar(1, char_a2);
    createCustomChar(2, char_a3);   
    createCustomChar(3, char_a4);    
    createCustomChar(4, char_a5);
    createCustomChar(5, char_a6);
    
    cmd(0x80);  // Move to the first line
    
    data(0x00); 
    data(0x01); 
    data(0x02); 
    data(0x03);
    data(0x04);
    data(0x05);
    while(1); // Infinite loop to keep the display on
    return;
}

void cmd(unsigned char a) 
{
    RC0 = 0; // RS = 0 for command
    RC1 = 0; // RW = 0 for write
    PORTD = a; // Send command
    RC2 = 1; // Enable pulse
    for(int i = 0; i <= 100; i++); // Small delay
    RC2 = 0;
    for(int i = 0; i <= 5000; i++); // Larger delay
}

void data(unsigned char a)
{
    RC0 = 1; // RS = 1 for data
    RC1 = 0; // RW = 0 for write
    PORTD = a; // Send data
    RC2 = 1; // Enable pulse
    for(int i = 0; i <= 100; i++); // Small delay
    RC2 = 0;
    for(int i = 0; i <= 5000; i++); // Larger delay
}

void display(const char *p)
{
    while(*p) 
    {
        data(*p); // Display each character
        p++;
    }
}

void createCustomChar(unsigned char location, unsigned char *pattern) 
{
    if (location < 8)
    { // Only 8 custom characters are allowed in CGRAM
        cmd(0x40 + (location * 8)); // Set CGRAM address
        for(int i = 0; i < 8; i++) 
        {
            data(pattern[i]); // Write each row of the custom character to CGRAM
        }
    }
}