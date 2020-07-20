/*
 * adc_test.cpp
 *
 * Created: 03.06.2015 17:52:29
 *  Author: Zephram
 */ 

#define F_CPU 16000000

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd-routines.h"
#include "lcd-routines.c"

int main(void)
{
	ADMUX |= (1<<REFS0);  // Set Reference to AVCC and input to ADC0 (single)

	ADCSRA |= (1<<ADEN)|(1<<ADPS2 | ADPS1 | ADPS0); // Enable ADC, set prescaler to 16
									// Fadc=Fcpu/prescaler=16.000.000/128=125kHz
									// Fadc should be between 50kHz and 200kHz

	lcd_init();
	
	lcd_clear();
	
	lcd_string("adc test");
	
	_delay_ms(1000);
	
	lcd_clear();

    char szText[9];
    double fValue;
	
    while(1)
    {
        ADCSRA |= (1<<ADSC);        // Start a conversion
		
        while(ADCSRA & (1<<ADSC));  // What until the bit is reset by the
									// CPU after the conversion is finished
       
	   fValue = (double)ADC * 5.0 / 1024.0;

        sprintf(szText,"U = %.2f V",fValue);
		
		lcd_clear();
		lcd_string(szText);
		
		_delay_ms(1000);
    }
}


