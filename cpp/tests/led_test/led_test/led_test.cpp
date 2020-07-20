/*
 * pollin0.cpp
 *
 * Created: 19.03.2015 02:20:59
 *  Author: Zephram
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 255;
	PORTC = 255;
	
	
	
	
	// PD1 ist äußere Leitung = gelb
	// PD2 ist innere Leitung = grün
				
	DDRB  = 0b11111111;
	PORTB = 0b00000000;
	DDRD  = 0b11111111; // Board-LEDs auf Ausgabe, Drähte auf Eingabe
	PORTD = 0b00000000; // Pull-Up 
	
	volatile char counter = 0;
	volatile bool forward = true;

    while(1)
    {
		PORTD = 0;
		PORTB = 0;
		
		if(counter <= 7) PORTB = 1 << counter;
		if(counter > 7) PORTD = 1 << (counter-8);
		
		if(forward)counter++; else counter--;
		
		if(counter == 15) forward = false;
		
		if(counter == 0) forward = true;
		
		_delay_ms(100);
		
    }
}