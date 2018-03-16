
//步进电机*********************************************************
//#include "motor.h"

//sbit LED = P2^5;

//void main(){
//	LED =0;
//  MOTOR_off();
//	while(1){
//		LED = 0;
//	  MOTOR_run(0,4076,120);
//		LED = 1;
//		MOTOR_run(1,4076,120);
//	}
//	
//}


//SPI驱动液晶屏*********************************************************

//#include "oled12864spi.h"

//void main(){
//  OLED_Init();
//	while(1){
//		OLED_clear();
//		OLED_drawChinese(0,0,0);
//		OLED_drawChinese(16,0,1);
//		OLED_drawChinese(32,0,2);
//		OLED_drawAscii(0,2,0x7a);
//		OLED_drawAscii(8,2,0x65);
//		OLED_drawAscii(16,2,0x69);
//		OLED_drawAscii(24,2,0x6d);
//		OLED_drawAscii(32,2,0x61);
//		OLED_drawAscii(40,2,0x6f);
//		OLED_drawAscii(48,2,0x37);
//		OLED_drawAscii(56,2,0x37);
//		Delay1ms(1000);
//		OLED_clear();
//	  OLED_drawImg(BMP2);
//		Delay1ms(1000);
//	}
//}


//呼吸灯***********************************************************

//#include "pwm.h"
//#include "delay.h"

//typedef unsigned char u8;
//typedef unsigned int u16;

//int main(){
//	u8 ind = 0;
//	PWM0_init();
//  while(1){
//	  for(;ind <= 0x33;ind++){
//		 PWM0_set(ind * 5);
//		 Delay1ms(20);
//		}
//		Delay1ms(1000);
//		for(ind = 0x33;ind >= 0x01;ind--){
//		 PWM0_set(ind * 5);
//		 Delay1ms(20);
//		}
//		Delay1ms(700);
//	}
//}