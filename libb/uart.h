#ifndef _UART_H_
#define _UART_H_

#include <stc12c5a60s2.h>

void uartInit(void);
void sendChar(unsigned char dat);
void sendStr(unsigned char *str);

#endif