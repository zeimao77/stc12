#include "pwm.h"
#include "delay.h"

typedef unsigned char u8;
typedef unsigned int u16;

int main(){
	u8 ind = 0;
	PWM0_init();
  while(1){
	  for(;ind <= 0x33;ind++){
		 PWM0_set(ind * 5);
		 Delay1ms(20);
		}
		Delay1ms(1000);
		for(ind = 0x33;ind >= 0x01;ind--){
		 PWM0_set(ind * 5);
		 Delay1ms(20);
		}
		Delay1ms(700);
	}
}