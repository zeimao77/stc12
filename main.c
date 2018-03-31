#include "hcsr04.h"
#include "oled12864spi.h"
#include "uart.h"

void display(unsigned int dat);



void main(){
	unsigned int val;
	UART_Init();
  HCSR04_init();
	OLED_Init();
  while(1){
		val = testdistance();
		display(val);
	  Delay1ms(100);
  }
}

void display(unsigned int dat){
  unsigned char qian,bai,shi,ge;
  qian = dat/1000 + 0x30;
  bai = (dat%1000)/100 + 0x30;
  shi = (dat%100)/10 + 0x30;
  ge = dat%10 + 0x30;
  OLED_drawAscii(0x00,1,qian);
  OLED_drawAscii(0x10,1,bai);
  OLED_drawAscii(0x20,1,shi);
  OLED_drawAscii(0x30,1,ge);
}