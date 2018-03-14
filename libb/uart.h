#ifndef _UART_H_
#define _UART_H_

#include <stc12c5a60s2.h>

void UART_Init(void);
void UART_sendChar(unsigned char dat);
void UART_sendStr(unsigned char *str);

#endif