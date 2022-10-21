#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab3_Task2.h"

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

Interval_1:
LDI R16, 20

Delay_Interval_1_Loop:
call Delay
SUBI R16, 1
BRNE Delay_Interval_1_Loop
RET

Interval_2:
LDI R16, 20

Delay_Interval_2_Loop:
call Delay
SUBI R16, 1
BRNE Delay_Interval_2_Loop
RET

Interval_3:
LDI R16, 20

Delay_Interval_3_Loop:
call Delay
SUBI R16, 1
BRNE Delay_Interval_3_Loop
RET

//initialization
.global Port_D_init
Port_D_init:  LDI R16, 0b01110000
              OUT 0x0A, R16
              LDI R16, 0b00001110
              OUT 0x0B, R16

//start 
.global Loop_Button_LED_Loop
Loop_Button_LED_Loop:

Start:  IN R16, 0x09
        ANDI R16, 0b00000010
        CPI R16, 0b00000000
        BREQ Flash1
        IN R17, 0x09
        ANDI R17, 0b00000100
        CPI R17, 0b00000000
        BREQ Flash2
        IN R18, 0x09
        ANDI R18, 0b00001000
        CPI R18, 0b00000000
        BREQ Flash3
        JMP Start

Flash1: SBI 0x0B, 4
        call Interval_1
        CBI 0x0B, 4
        call Interval_1
        JMP Start
        RET

Flash2: SBI 0x0B, 5
        call Interval_2
        CBI 0x0B, 5
        call Interval_2
        JMP Start
        RET

Flash3: SBI 0x0B, 6
        call Interval_3
        CBI 0x0B, 6
        call Interval_3
        JMP Start
        RET
