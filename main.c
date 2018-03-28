#include "hcsr04.h"
#include "oled12864spi.h"
#include "adc.h"
#include "uart.h"

void display(unsigned int dat);

unsigned int ZERO_LINE = 512;

void main(){
  unsigned int val;
  OLED_Init();
  ADC_init(0x01,ADC_SPEED_180);
  while(1){
  val = ADC_Read();
	display(val);
	//**********************************************	
	//**********************************************	
	Delay1ms(1000);
  }
}

void display(unsigned int dat){
  unsigned char qian,bai,shi,ge;
  qian = dat/1000;
  bai = (dat%1000)/100;
  shi = (dat%100)/10;
  ge = dat%10;
  OLED_drawAscii(0x00,1,qian + 0x30);
  OLED_drawAscii(0x10,1,bai + 0x30);
  OLED_drawAscii(0x20,1,shi + 0x30);
  OLED_drawAscii(0x30,1,ge + 0x30);
}