#include "avr/io.h"
#include "Lab1.h"
#define DDRD 0x0A

//set port D all connections 0~7 as output direction, and send low to all port D 's pins  to turn off LEDs
.global init_port_D_out
init_port_D_out:

//set port D all pins 0~7 as output direction
sbi 0X0A,0     
sbi 0X0A,1
sbi 0X0A,2
sbi 0X0A,3
sbi 0X0A,4
sbi 0X0A,5
sbi 0X0A,6
sbi 0X0A,7

//send low voltage to all port D 's pins  to turn off LED 0~7
cbi 0x0B,0         
cbi 0x0B,1
cbi 0x0B,2
cbi 0x0B,3
cbi 0x0B,4
cbi 0x0B,5
cbi 0x0B,6
cbi 0x0B,7
ret

//Define the function port_D_0_high: set port D's Pin0 as high  
.global port_D_0_high
port_D_0_high:
sbi 0x0B,0
ret

//Define the function port_D_1_high: set port D's Pin1 as high  
.global port_D_1_high
port_D_1_high:
sbi 0x0B,1
ret

//Define the function port_D_2_high: set port D's Pin2 as high 
.global port_D_2_high
port_D_2_high:
sbi 0x0B,2
ret

//Define the function port_D_3_high: set port D's Pin3 as high 
.global port_D_3_high
port_D_3_high:
sbi 0x0B,3
ret

//Define the function port_D_4_high: set port D's Pin4 as high 
.global port_D_4_high
port_D_4_high:
sbi 0x0B,4
ret

//Define the function port_D_5_high: set port D's Pin5 as high  
.global port_D_5_high
port_D_5_high:
sbi 0x0B,5
ret

//Define the function port_D_6_high: set port D's Pin6 as high 
.global port_D_6_high
port_D_6_high:
sbi 0x0B,6
ret

//Define the function port_D_7_high: set port D's Pin7 as high 
.global port_D_7_high
port_D_7_high:
sbi 0x0B,7
ret
