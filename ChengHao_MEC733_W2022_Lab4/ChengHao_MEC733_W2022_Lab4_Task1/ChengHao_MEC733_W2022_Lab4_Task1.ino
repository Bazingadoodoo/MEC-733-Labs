#include <mechbotShield.h>
#include <USART.h>
#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab4.h"

int main() {

  uint8_t i;

  initUSART();
  i=stack();

  printString("i=");
  printDecByte(i);
  
  return 0;
}
