#ifndef _SPI4_H_
#define _SPI4_h_

#include <stc12c5a60s2.h>
#include "delay.h"

#define SPI_SEND_START 0
#define SPI_SEND_STOP 1;

sbit SPI_CS = P1^0;
sbit SPI_CLK = P1^2;
sbit SPI_MISO = P1^3;
sbit SPI_MOSI = P1^4;


//向spi总线上写入一个字节
void SPI4_writeByte(unsigned char dat);

#endif