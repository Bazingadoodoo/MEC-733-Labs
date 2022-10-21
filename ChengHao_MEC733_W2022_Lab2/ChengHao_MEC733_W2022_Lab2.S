#include <avr/io.h>
#include "ChengHao_MEC733_W2022_Lab2.h"

.global port_D_init
port_D_init:
ldi r16,0b00001100; 
out 0x0A,r16; 
ldi r16,0b11000000; 
out 0x0B,r16;   
ret

.global port_D7_read
port_D7_read:
in r24,0x09;        
ANDI r24,0b10000000; 
ret

.global port_D6_read
port_D6_read:
in r24,0x09;         
ANDI r24,0b01000000;  
ret

.global port_D2_high
port_D2_high:
sbi 0x0B,2
ret

.global port_D2_low
port_D2_low:
cbi 0x0B,2
ret

.global port_D3_high
port_D3_high:
sbi 0x0B,3
ret

.global port_D3_low
port_D3_low:
cbi 0x0B,3
ret
