//IIC驱动oled12864***********************************************************
//#include "oled12864.h"

//void main(){
//  OLED_SSD1306_Init();
//	while(1){
//    OLED_SSD1306_clear();
//		OLED_SSD1306_drawChinese(0,0,0);
//		OLED_SSD1306_drawChinese(16,0,1);
//		OLED_SSD1306_drawChinese(32,0,2);
//		OLED_SSD1306_drawAscii(0,2,0x7a);
//		OLED_SSD1306_drawAscii(8,2,0x65);
//		OLED_SSD1306_drawAscii(16,2,0x69);
//		OLED_SSD1306_drawAscii(24,2,0x6d);
//		OLED_SSD1306_drawAscii(32,2,0x61);
//		OLED_SSD1306_drawAscii(40,2,0x6f);
//		OLED_SSD1306_drawAscii(48,2,0x37);
//		OLED_SSD1306_drawAscii(56,2,0x37);
//		Delay1ms(1000);
//		OLED_SSD1306_clear();
//	  OLED_SSD1306_drawImg(BMP2);
//		Delay1ms(1000);
//	}
//}


//红外遥控*********************************************************
//#include "hwreceive.h"
//#include "uart.h"

//void play(unsigned char key1,unsigned char key2){
//  if(key1 == MP3HWTAB[12][0] && key2 == MP3HWTAB[12][1]){
//	  P1 = 0x01;
//	}
//	else if(key1 == MP3HWTAB[13][0] && key2 == MP3HWTAB[13][1]){
//	  P1 = 0x02;
//	}
//	else if(key1 == MP3HWTAB[14][0] && key2 == MP3HWTAB[14][1]){
//	  P1 = 0x03;
//	}
//	else if(key1 == MP3HWTAB[15][0] && key2 == MP3HWTAB[15][1]){
//	  P1 = 0x04;
//	}
//	else if(key1 == MP3HWTAB[16][0] && key2 == MP3HWTAB[16][1]){
//	  P1 = 0x05;
//	}
//	else if(key1 == MP3HWTAB[17][0] && key2 == MP3HWTAB[17][1]){
//	  P1 = 0x06;
//	}
//	else if(key1 == MP3HWTAB[18][0] && key2 == MP3HWTAB[18][1]){
//	  P1 = 0x07;
//	}
//	else if(key1 == MP3HWTAB[9][0] && key2 == MP3HWTAB[9][1]){
//	  P1 = 0x00;
//	}
//}

//void main(){
//	unsigned char ind;
//	unsigned char *codedata;
//	UART_Init();
//	RECE = 1;
//	while(1){
//	  if(RECE == 0){
//	    Delay1ms(5);
//			if(RECE == 0){
//			  codedata = getcodedata();
//				for(ind = 0;ind < 4;ind ++){
//	        UART_sendChar(codedata[ind]);
//	      }
//				play(codedata[2],codedata[3]);
//			}
//	  }
//	}
//}


//eeprom*********************************************************

//#include "eeprom.h"
//#include "delay.h"
//#include "uart.h"

//#define IAP_ADDRESS 0x0000

//sbit BUTTON1 = P2^2;
//unsigned char readdata;

//void main(){
//	readdata = eeprom_read(IAP_ADDRESS);
//	P1 = readdata;
//	UART_Init();
//  BUTTON1 = 1;
//	while(1){
//	  if(BUTTON1 == 0){
//		  Delay1ms(20);
//			if(BUTTON1 == 0){
//			  readdata++;
//				UART_sendChar(readdata);
//				eeprom_write(IAP_ADDRESS,readdata);
//				P1 = readdata;
//				if(readdata > 0x07){
//				  readdata = 0x00;
//				}
//				while(BUTTON1 == 0);
//			}
//		}
//	}
//}


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