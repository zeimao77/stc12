#ifndef _MCUID_H_
#define _MCUID_H_

#include "uart.h"

#define ID_ADDR_RAM 0XF1

//调用前请先初始化口
void printMCUID();
void checkMCUID();

#endif