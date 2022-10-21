#include <mechbotShield.h>
#include <USART.h>
#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab2.h"

int main()  
{    
  uint8_t i,j;      
  
  port_D_init();          //initialze Port D's Pin 0~3 as outputs, 4~7 as inputs
  delay_ms(2000);
    
  initUSART();            //initialize communication 
  printString("We are doing lab 2!");
    
  while(1)
  { 
    i=port_D7_read();
    printString("\n i="); 
    printBinaryByte(i); 
    j=port_D6_read();
    printString("\n j="); 
    printBinaryByte(j); 
            
    if(i==0)
     {port_D3_high();}    
    if(i!=0)
     {port_D3_low();}     
    if(j==0)
     {port_D2_high();}    
    if(j!=0)
     {port_D2_low();}     
  }
}

     
