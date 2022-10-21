#include <mechbotShield.h>
#include <USART.h>
#include <avr/io.h>
#include <LiquidCrystal.h>

int main ()
{

  LiquidCrystal lcd(7,8,9,10,11,12);
  lcd.begin(16, 2);
  
  while(1)
  {
    lcd.setCursor(0, 0);
    lcd.print("doing MEC733 lab");
    lcd.setCursor(0,1);
    lcd.print("4");
    delay_ms(1000);
    lcd.clear();
    delay_ms(1000);
  }
  

return 0;
}
