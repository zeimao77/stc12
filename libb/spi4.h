#ifndef _SPI4_H_
#define _SPI4_h_

#include <stc12c5a60s2.h>
#include "delay.h"

#define SPI_SEND_START 0
#define SPI_SEND_STOP 1;

//时钟
sbit SPI_CLK = P2^0;
//主机输出
sbit SPI_MISO = P2^1;
//从机输入
sbit SPI_MOSI = P2^2;
//片选
sbit SPI_CS = P2^5;



//向spi总线上写入一个字节
void SPI4_writeByte(unsigned char dat);

void SPI4_readByte();

#endif