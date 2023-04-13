#ifndef FILE_UART_H
#define FILE_UART_H

#if defined F_CPU && F_CPU == 16000000UL
#define BAUD_RATE_4800_BPS  207
#define BAUD_RATE_9600_BPS  103
#define BAUD_RATE_14400_BPS  68
#define BAUD_RATE_19200_BPS  51
#define BAUD_RATE_28800_BPS  34
#define BAUD_RATE_38400_BPS  25
#define BAUD_RATE_57600_BPS  16
#define BAUD_RATE_76800_BPS   12
#define BAUD_RATE_115200_BPS  8
#define BAUD_RATE_230400_BPS  3
#endif

void uart_init(unsigned int);
void uart_print(char *, ...);

#endif