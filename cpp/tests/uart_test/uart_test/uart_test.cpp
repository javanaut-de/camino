/*
 * uart_test.cpp
 *
 * Created: 04.06.2015 19:47:58
 *  Author: Zephram
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#include <util/setbaud.h>

#include <util/delay.h>
#include <avr/io.h>

#include "lcd-routines.h"
#include "lcd-routines.c"

//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
	//Wait untill a data is available

	while(!(UCSRA & (1<<RXC)))
	{
		//Do nothing
	}

	//Now USART has got data from host
	//and is available is buffer

	return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{
	//Wait untill the transmitter is ready

	while(!(UCSRA & (1<<UDRE)))
	{
		//Do nothing
	}

	//Now write the data to USART buffer

	UDR=data;
}

int main(void)
{
	char data;
	
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	
	#if USE_2X
	/* U2X-Modus erforderlich */
	UCSRA |= (1 << U2X);
	#else
	/* U2X-Modus nicht erforderlich */
	UCSRA &= ~(1 << U2X);
	#endif

		
	UCSRB |= (1<<(TXEN)) |  (1<<(RXEN));			// UART TX+RX einschalten
	UCSRC = (1<<URSEL)|(1 << UCSZ1)|(1 << UCSZ0);	// Asynchron 8N1

	lcd_init();
	
	lcd_clear();
	
    while(1)
    {
		//Readtest
		data=USARTReadChar();

		/* Now send the same data but but surround it in
		square bracket. For example if user sent 'a' our
		system will echo back '[a]'.
		*/

		USARTWriteChar('[');
		USARTWriteChar(data);
		USARTWriteChar(']');
    
		//Writetest
		//UDR = 'x';
		//_delay_ms(1000);
	
    }
}