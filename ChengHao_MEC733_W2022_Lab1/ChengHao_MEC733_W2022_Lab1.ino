#include<mechbotShield.h>
#include "Lab1.h"

int main()
{   
  
 init_port_D_out();
 delay_ms(2000); 

 port_D_1_high();     
 delay_ms(2000);
 init_port_D_out();
 delay_ms(2000);
 
 port_D_3_high();
 delay_ms(2000);
 init_port_D_out();
 delay_ms(2000);
 
 port_D_5_high();
 delay_ms(2000);
 init_port_D_out();
 delay_ms(2000);
 
 port_D_7_high();
 delay_ms(2000);
 init_port_D_out();
 delay_ms(2000);
  
    return;
}
