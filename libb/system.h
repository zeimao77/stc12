#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stc12c5a60s2.h>

//0x101000
#define WDT_2DP 0x00;    //二分频       12Mhz   65.5ms
#define WDT_4DP 0x01;    //四分频       12Mhz   131.0ms
#define WDT_8DP 0x02;    //八分频       12Mhz   262.1ms
#define WDT_16DP 0x03;   //十六分频     12Mhz   524.2ms
#define WDT_32DP 0x04;   //三二分频     12Mhz   1.0485s
#define WDT_64DP 0x05;   //六四分频     12Mhz   2.0971s
#define WDT_128DP 0x06;  //一二八分频   12Mhz   4.1943s
#define WDT_256DP 0x07;  //二五六分频   12Mhz   8.3886s

//启动初始化看门狗
//如果flag=1则在空闲模式计数，默认空闲模式不计数
//wdt_xdp设置分频
void sys_en_wdt(bit flag,unsigned char wdt_xdp);
//喂狗
void sys_feed_wdt();
//掉电模式
void sys_pd();
//空闲模式
void sys_idle();

#endif