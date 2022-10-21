#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab3_Task1.h"

//delay

Delay: 
LDI R25, 0xFF
LDI R24, 0XFF

Delay_Loop:
nop
nop
SBIW R24, 1
BRNE Delay_Loop
RET

Interval:
LDI R16, 41

Delay_Interval_Loop:
call Delay
SUBI R16, 1
BRNE Delay_Interval_Loop
RET
                 
//------------------------------------
//initialization

.global Port_D_init
Port_D_init:
LDI R16, 0b00010000
OUT 0x0A, R16
LDI R16, 0b00000010
OUT 0x0B, R16

//Loop_Button_LED_Loop

.global Loop_Button_LED_Loop
Loop_Button_LED_Loop:

Start:  IN R16, 0x09
        ANDI R16, 0b00000010
        CPI R16, 0b00000000
        BREQ Flash
        JMP Start

Flash:  SBI 0x0B, 4
        ;call Delay_Interval_Loop
        call Interval
        CBI 0x0B, 4
        ;call Delay_Interval_Loop
        call Interval
        JMP Start
        RET
