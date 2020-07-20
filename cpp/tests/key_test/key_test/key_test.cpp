/*
 * pollin0.cpp
 *
 * Created: 19.03.2015 02:20:59
 *  Author: Zephram
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

const char direction = 1; // 1 or 2

int main(void)
{
	if(direction == 1)			
	{
		DDRB  = 0b11111111;
		DDRD  = 0b00000000;
	}
	else
	{
		DDRD  = 0b11111111;
		DDRB  = 0b00000000;
	}
	
	PORTB = 0b00000000;
	PORTD = 0b00000000; 
	
    while(1)
    {
		if(direction == 1)
			PORTB = PIND;
		else
			PORTD = PINB;
    }
}