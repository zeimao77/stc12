#ifndef _HCSR04_H_
#define _HCSR04_H_

#include <stc12c5a60s2.h>
#include "delay.h"
#include "uart.h"

//如果需要修改端口 需要注意修改函数中的端口以推挽输入方式驱动测距模块
sbit TRIG = P1^0;
sbit ECHO = P3^2;

void HCSR04_init();

unsigned int testdistance();

#endif