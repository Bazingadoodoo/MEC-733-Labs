#include <avr/io.h>
#include <util/delay.h>
#include <mechbotShield.h>

#define MAX_SELECTION 4

void testLED (void) {
	uint8_t i=0, value;
	DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);
	DDRD |= (1 << PD6) | (1 << PD7);
	

	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Testing");
	moveLCDCursor(16);
	lcdPrint("LEDS");
	delay_ms(2000);
	

	for(i=0;i<8;i++) {
		value = (1<<i);
		PORTB &= 0b11000000;// Zero out PB0-PB5
		PORTB |= value & 0b00111111; //Mask out bits 6-7 of i

		PORTD &= 0b00111111; //Zero out PD6-PD7
		PORTD |= value & 0b11000000; //Mask out bits 0-5 of i
		delay_ms(350);
	}

	//Light up one led at at time from left to right
	for(i=8;i>0;i--) {
		value = (1<<(i-1));
		PORTB &= 0b11000000;// Zero out PB0-PB5
		PORTB |= value & 0b00111111; //Mask out bits 6-7 of i

		PORTD &= 0b00111111; //Zero out PD6-PD7
		PORTD |= value & 0b11000000; //Mask out bits 0-5 of i
		delay_ms(350);
	}

	value = 0;
	//Display binary representation of i to LED
	for(i=0;i<8;i++) {
		value |=  (1<<i);
		PORTB &= 0b11000000;// Zero out PB0-PB5
		PORTB |= value & 0b00111111; //Mask out bits 6-7 of i

		PORTD &= 0b00111111; //Zero out PD6-PD7
		PORTD |= value & 0b11000000; //Mask out bits 0-5 of i
		delay_ms(350);
	}
	value = 0xff;
	//Display binary representation of i to LED
	for(i=8;i>0;i--) {
		value &= ~(1<<(i-1));
		PORTB &= 0b11000000;// Zero out PB0-PB5
		PORTB |= value & 0b00111111; //Mask out bits 6-7 of i

		PORTD &= 0b00111111; //Zero out PD6-PD7
		PORTD |= value & 0b11000000; //Mask out bits 0-5 of i
		delay_ms(350);
	}
	
	
	PORTB &= 0b11000000;
	PORTD &= 0b00111111;
	
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Exiting ");
	moveLCDCursor(16);
	lcdPrint("Test");
	delay_ms(2000);
	clrLCD();

}

void testIOSw(void) {
	uint8_t bumper=1, dipSw, i;
	
	PORTD |= (1<<PD3) | (1<<PD4) | (1<<PD5);
	DDRD &= ~((1<<PD3) | (1<<PD4) | (1<<PD5));
	
	PORTC |= (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
	DDRC &= ~((1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5));	
	
	clrLCD();	
	moveLCDCursor(0);
	lcdPrint("Testing");
	moveLCDCursor(16);
	lcdPrint("IO Switches");
	delay_ms(2000);
	clrLCD();
	
	while(bumper!=0) {		
		bumper = (PIND >> 3) & 0x07;
		bumper |= (PINC << 2) & 0x08;
		dipSw = (PINC>>2) ;

		/*	
		moveLCDCursor(0);
		lcdPrintByte(dipSw);
		*/	
		moveLCDCursor(0);
		lcdPrint("Bumper  DIP-SW");
		
		for (i=0; i<4; i++) {
			if (bumper & (1<<i)) {
				moveLCDCursor(16+i);
				lcdPrint("1");
			}
			else {
				moveLCDCursor(16+i);
				lcdPrint("0");
			}
			
			
			if (dipSw & (1<<i)) {
				moveLCDCursor(24+i);
				lcdPrint("1");
			}
			else {
				moveLCDCursor(24+i);
				lcdPrint("0");
			}			
		}
		
	}
	
	PORTB &= 0b11000000;
	PORTD &= 0b00111111;
	
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Exiting ");
	moveLCDCursor(16);
	lcdPrint("Test");
	delay_ms(2000);
	clrLCD();
	
	
}

void testADC(void) {

	uint8_t channel;
	uint8_t bumper=1;
	
	PORTD |= (1<<PD3) | (1<<PD4) | (1<<PD5);
	DDRD &= ~((1<<PD3) | (1<<PD4) | (1<<PD5));
	
	PORTC |= (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
	DDRC &= ~((1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5));	

		
	initADC();
	clrLCD();	
	moveLCDCursor(0);
	lcdPrint("Testing");
	moveLCDCursor(16);
	lcdPrint("ADC Functions");
	delay_ms(2000);
	clrLCD();
		
	
	while(bumper != 0) {
		bumper = (PIND >> 3) & 0x07;
		bumper |= (PINC << 2) & 0x08;
		
		channel = (PINC >> 2) & 0x07;
		moveLCDCursor(0);
		lcdPrint("Ch: ");
		lcdPrintDec(channel);
		
		moveLCDCursor(16);
		lcdPrint("Value: ");
		lcdPrintDec(analog(channel));
		
		delay_ms(300);

	}
	
	PORTB &= 0b11000000;
	PORTD &= 0b00111111;	
	
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Exiting ");
	moveLCDCursor(16);
	lcdPrint("Test");
	delay_ms(2000);
	clrLCD();
}

void testMotor(void) {
	uint16_t debouncePause = 5;
	uint8_t bumper=1;
	PORTD |= (1<<PD3) | (1<<PD4) | (1<<PD5);
	DDRD &= ~((1<<PD3) | (1<<PD4) | (1<<PD5));
	
	PORTC |= (1<<PC1);
	DDRC &= ~(1<<PC1) ;	
		
	int16_t speedLeft=0, speedRight=0;
	uint8_t speedStep = 10;
	initMotor();
	
	
	clrLCD();	
	moveLCDCursor(0);
	lcdPrint("Testing");
	moveLCDCursor(16);
	lcdPrint("Motors Functions");
	delay_ms(2000);
	clrLCD();
		
	
	while (bumper!=0) {
		bumper = (PIND >> 3) & 0x07;
		bumper |= (PINC << 2) & 0x08;
		
		moveLCDCursor(0);
		//lcdPrintByte(bumper);
		lcdPrint("Motor L  Motor R");
		moveLCDCursor(16);
		lcdPrintDec(speedLeft);
		moveLCDCursor(25);
		lcdPrintDec(speedRight);
		

		//Both Bumper 0 and 1 are activated
		if ((bumper & 0x03) == 0) {
			speedLeft = 0;
			delay_ms(debouncePause);
		}
		//Both Bumper 2 and 3 are activated
		else if ((bumper & 0x0C) == 0) {
			speedRight = 0;
			delay_ms(debouncePause);
		}
		//Bumper 0 is activated
		else if ((bumper & 0x01) == 0) {
			speedLeft-= speedStep;
			if (speedLeft < -1000) {
				speedLeft = -1000;
			}
			delay_ms(debouncePause);
		}
		//Bumper 1 is activated
		else if ((bumper & 0x02) == 0) {
			speedLeft+= speedStep;
			if (speedLeft > 1000) {
				speedLeft = 1000;
			}
			delay_ms(debouncePause);
		}
		//Bumper 2 is activated
		else if ((bumper & 0x04) == 0) {
			speedRight-= speedStep;
			if (speedRight < -1000) {
				speedRight = -1000;
			}
			delay_ms(debouncePause);
		}
		//Bumper 3 is activated
		else if ((bumper & 0x08) == 0) {
			speedRight+= speedStep;
			if (speedRight > 1000) {
				speedRight = 1000;
			}
			delay_ms(debouncePause);
		}
		
		motor(speedLeft,speedRight);
				
	}
	
	motor(0,0);
	disableMotor();

	PORTB &= 0b11000000;
	PORTD &= 0b00111111;
	
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Exiting ");
	moveLCDCursor(16);
	lcdPrint("Test");
	delay_ms(2000);
	clrLCD();
}

void testBuzzer(void) {
	uint16_t debouncePause = 300;
	uint8_t bumper=1;
	PORTD |= (1<<PD3) | (1<<PD4) | (1<<PD5);
	DDRD &= ~((1<<PD3) | (1<<PD4) | (1<<PD5));
	
	PORTC |= (1<<PC1);
	DDRC &= ~(1<<PC1) ;	
	
	int8_t selection = 0;	
	char *songs[] ={ "Shave & Haircut", "Super Mario", "SM Underworld", " "};
	
	clrLCD();	
	moveLCDCursor(0);
	lcdPrint("Testing");
	moveLCDCursor(16);
	lcdPrint("Buzzer");
	delay_ms(2000);
	clrLCD();
	
	while (bumper!=0) {
		bumper = (PIND >> 3) & 0x07;
		bumper |= (PINC << 2) & 0x08;


		//Bumper 0 is activated
		if ((bumper & 0x01) == 0) {
			selection++;
			if (selection >= 2) {
				selection = 2;
			}
			delay_ms(debouncePause);
			clrLCD();
		}
		//Bumper 1 is activated
		else if ((bumper & 0x02) == 0) {
			selection--;
			if (selection  < 0) {
				selection = 0;
			}
			delay_ms(debouncePause);
			clrLCD();
		}
		//Bumper 2 is activated
		else if ((bumper & 0x04) == 0) {
			
			delay_ms(debouncePause);
		}
		//Bumper 3 is activated
		else if ((bumper & 0x08) == 0) {
			switch(selection) {
				case 0: 	playShaveAndHaircut();
							break;
				case 1: 	playSuperMario();
							break;
				case 2: 	playSuperMarioUnderworld();
							break;			
			}
			delay_ms(debouncePause);
		}
		
		
		moveLCDCursor(0);
		lcdPrint(">");
		moveLCDCursor(1);
		lcdPrint(songs[selection]);
		moveLCDCursor(17);
		lcdPrint(songs[selection+1]);
		
	
	}
	
	PORTB &= 0b11000000;
	PORTD &= 0b00111111;
	
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Exiting ");
	moveLCDCursor(16);
	lcdPrint("Test");
	delay_ms(2000);
	clrLCD();

}




/*
	Main function
*/
int main(void) {
	
	
	uint16_t debouncePause = 300;
	uint8_t bumper;
	PORTD |= (1<<PD3) | (1<<PD4) | (1<<PD5);
	DDRD &= ~((1<<PD3) | (1<<PD4) | (1<<PD5));
	
	PORTC |= (1<<PC1);
	DDRC &= ~(1<<PC1) ;	
		
	int8_t selection = 0;	
	char *songs[] ={ "Test LED", "Test IO Sw", "Test ADC", "Test Motor", "Test Buzzer", " ", };
	
	
	initSoftSerial();
	setLCDBackLight(147);
	clrLCD();
	moveLCDCursor(0);
	lcdPrint("Ryerson U.");
	moveLCDCursor(16);
	lcdPrint("Mech Eng");
	delay_ms(3000);
	clrLCD();
			
	while (1) {
		bumper = (PIND >> 3) & 0x07;
		bumper |= (PINC << 2) & 0x08;


		//Bumper 0 is activated
		if ((bumper & 0x01) == 0) {
			selection++;
			if (selection >= MAX_SELECTION) {
				selection = MAX_SELECTION;
			}
			delay_ms(debouncePause);
			clrLCD();
		}
		//Bumper 1 is activated
		else if ((bumper & 0x02) == 0) {
			selection--;
			if (selection  < 0) {
				selection = 0;
			}
			delay_ms(debouncePause);
			clrLCD();
		}
		//Bumper 2 is activated
		else if ((bumper & 0x04) == 0) {
			
			delay_ms(debouncePause);
		}
		//Bumper 3 is activated
		else if ((bumper & 0x08) == 0) {
			switch(selection) {
				case 0: 	testLED();
							break;
				case 1: 	testIOSw();
							break;
				case 2: 	testADC();
							break;
				case 3: 	testMotor();
							break;
				case 4: 	testBuzzer();
							break;			
			}
			delay_ms(debouncePause);
		}
		
		
		moveLCDCursor(0);
		lcdPrint(">");
		moveLCDCursor(1);
		lcdPrint(songs[selection]);
		moveLCDCursor(17);
		lcdPrint(songs[selection+1]);
		
	
	}


	return 0;
}



