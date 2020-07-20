/*
 * lcd_test_162c.cpp
 *
 * Created: 03.06.2015 17:52:29
 *  Author: Zephram
 */ 


#include <avr/io.h>
#include "lcd-routines.h"
#include "lcd-routines.c"

int main(void)
{

	
	lcd_init();
	
	// Text in einzelnen Zeichen ausgeben
	//lcd_data( 'T' );
	//lcd_data( 'e' );
	//lcd_data( 's' );
	//lcd_data( 't' );
	
	// Die Ausgabemarke in die 2te Zeile setzen
	lcd_setcursor( 0, 1 );
	
	// erneut Text ausgeben, aber diesmal komfortabler als String
	lcd_string("Hello World! :)");
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}