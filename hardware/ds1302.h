#ifndef _DS1302_H_
#define _DS1302_H_

#include <stc12c5a60s2.h>
#include "delay.h"
#include "uart.h"

#define DS1302_SEC_ADDR 0x80
#define DS1302_MIN_ADDR 0x82
#define DS1302_HOUR_ADDR 0x84
#define DS1302_DATE_ADDR 0x86
#define DS1302_MONTH_ADDR	0x88
#define DS1302_DAY_ADDR 0x8a
#define DS1302_YEAR_ADDR 0x8c
#define DS1302_CONTROL_ADDR 0x8e
#define DS1302_CHARGER_ADDR 0x90 					 
#define DS1302_CLKBURST_ADDR 0xbe

sbit DS1302_RST = P1^5;
sbit DS1302_DAT = P1^4;
sbit DS1302_SCK = P1^3;

struct DS1302_TIME{
  unsigned char year;
	unsigned char month;
	unsigned char date;
	unsigned char hour;
  unsigned char min;
	unsigned char sec;
	unsigned char day;
};

extern struct DS1302_TIME time_buff;

unsigned char time_buffer[];

void DS1302_init();

void DS1302_writeByte(unsigned char dat);

void DS1302_write(unsigned char addr,unsigned char dat);

void DS1302_writeTime(struct DS1302_TIME time_buffer);

//读取后的数据将保存在time_buff的结构体中
void DS1302_readTime();

unsigned char DS1302_readByte(unsigned char addr);

#endif