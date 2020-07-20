/*
 * dac_test.cpp
 *
 * Created: 04.06.2015 15:36:50
 *  Author: Zephram
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

const char mode = 1; // 1 or 2


int main(void)
{
	bool bState = false;
	char cOut = 0;
	
	DDRB = 0x08;                     // Setup PB3 as output

	TCCR0 |= (1<<WGM00)|(1<<WGM01)       // Start timer0 without
	|(1<<COM01)|(1<<CS00);      // prescaler in non
	// inverting fast PWM
	// mode. Connect OC0 in
	// non-inverting mode
	
	OCR0 = 64;
	
    while(1)
    {
		if(mode == 1)	// tri
		{
			OCR0 = cOut++;    
			_delay_us(5);
		}
	   
		if(mode == 2) // sqr
	    {
			if(!bState)
			{
				OCR0 = 192;
				bState = true;
			}
			else
			{
				OCR0 = 64;
				bState = false;
			}
	   
			_delay_us(600);
		}
	}
	   
}