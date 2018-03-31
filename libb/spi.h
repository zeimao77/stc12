#ifndef _SPI_H_
#define _SPI_H_

#include <stc12c5a60s2.h>

//发送和接收的位顺序[高位优先]
#define DORD_HTL 0x00
//发送和接收的位顺序[低位优先]
#define DORD_LTH 0x20

//SPICLK时钟选择[空闲高电平]
#define CPOL_HIGH 0x80
//SPICLK时钟选择[空闲低电平]
#define CPOL_LOW 0x00

sbit SS = P1^4;

void SPI_init(unsigned char DORD,unsigned char CPOL);

void SPI_writeByte(unsigned char DAT);

unsigned char readByte();


#endif