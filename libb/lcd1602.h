#ifndef _LCD1602_H_
#define _LCD1602_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define DATA P2

sbit RS = P1^2;
sbit RW = P1^3;
sbit EN = P1^4;

void writecmd(unsigned char cmd);
void writedata(unsigned char dat);
void initLcd();

#endif