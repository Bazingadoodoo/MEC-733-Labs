#include <mechbotShield.h>
#include <USART.h>
#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab3_Task2.h"

int main ()
{
    Port_D_init();
    Loop_Button_LED_Loop();

    return 0;
}
