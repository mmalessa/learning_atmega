#define F_CPU 16000000UL

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	// LED(s)
	DDRC = 0xFF;
	PORTC = 0xFF;
	_delay_ms(100);

    uart_init(BAUD_RATE_115200_BPS);

	while(1) /* Loop the messsage continously */
	{ 
		PORTC = 0xFF; //Turns ON All LEDs        
        uart_print("Elo, elo!");
        _delay_ms(100);
		PORTC= 0x00; //Turns OFF All LEDs
        _delay_ms(900);
	}	
}





















