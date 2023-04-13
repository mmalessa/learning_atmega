#include "uart.h"

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

void uart_init(unsigned int ubrr)
{
    // unsigned int ubrr = BAUD_RATE_115200_BPS;
	/* Set Baudrate  */
	UBRR0H = (ubrr>>8); // Shift the 16bit value ubrr 8 times to the right and transfer the upper 8 bits to UBBR0H register.
	UBRR0L = (ubrr);    // Copy the 16 bit value ubrr to the 8 bit UBBR0L register,Upper 8 bits are truncated while lower 8 bits are copied
	
	UCSR0C = 0x06;       /* Set frame format: 8data, 1stop bit  */
	UCSR0B = (1<<TXEN0); /* Enable  transmitter                 */

}

void uart_print(char *message, ...)
{
	int i = 0;
    while(message[i] != 0) /* print the String  "Hello from ATmega328p" */
    {
        while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer       */
                                            /* When UDRE0 = 0,data transmisson ongoing.                         */
                                            /* So NOT{[UCSR0A & (1<<UDRE0)] = 0} = 1 ,While(1) loop stays there */
                                            /* When UDRE0 = 1,data transmisson completed.                       */
                                            /* So NOT{[UCSR0A & (1<<UDRE0)] = 1} = 0 ,While(0) loop fails       */
        UDR0 = message[i];					 /* Put data into buffer, sends the data */
        i++;                             /* increment counter                    */
    }
    while (!( UCSR0A & (1<<UDRE0)));
    UDR0 = '\n';
    while (!( UCSR0A & (1<<UDRE0)));
    UDR0 = '\r';
}