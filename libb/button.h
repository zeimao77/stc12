#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define BUTTON1 P1^2
//长按时间定义超过3s
#define LONG_TIME 3000
//双击空隙
#define INTERVAL_TIME 1000

//单击事件实现此方法
void Button1_click();
//双击事件实现此方法
void Button1_dbclick();
//长按事件实现此方法
void Button1_lclick();

//按键检测程序
void Button1_enable();
	

#endif