#include "motor.h"

unsigned char MOTOR_STEP;

void MOTOR_off(){
  DPOUT1 = 0;
	DPOUT2 = 0;
	DPOUT3 = 0;
	DPOUT4 = 0;
}

//正转  角度 
void MOTOR_run(unsigned char rl,unsigned int num,unsigned int speed){
	for(;num>0;num--){
	  if(rl == 1){
		  MOTOR_STEP++;
			if(MOTOR_STEP > 7){
			  MOTOR_STEP = 0;
			}
		}else{
			if(MOTOR_STEP == 0){
			  MOTOR_STEP = 8;
			}
			MOTOR_STEP--;
		}
		MOTOR_Pi(MOTOR_STEP,speed);
	}
}

//单步八拍
void MOTOR_Pi(unsigned char pi,unsigned int speed){
  switch(pi){
	  case 0:
			DPOUT1 = 1;
		  DPOUT2 = 0;
		  DPOUT3 = 0;
		  DPOUT4 = 0;
		  break;
		case 1:
			DPOUT1 = 1;
		  DPOUT2 = 1;
		  DPOUT3 = 0;
		  DPOUT4 = 0;
			break;
		case 2:
			DPOUT1 = 0;
		  DPOUT2 = 1;
		  DPOUT3 = 0;
		  DPOUT4 = 0;
			break;
		case 3:
			DPOUT1 = 0;
		  DPOUT2 = 1;
		  DPOUT3 = 1;
		  DPOUT4 = 0;
			break;
		case 4:
			DPOUT1 = 0;
		  DPOUT2 = 0;
		  DPOUT3 = 1;
		  DPOUT4 = 0;
			break;
		case 5:
			DPOUT1 = 0;
		  DPOUT2 = 0;
		  DPOUT3 = 1;
		  DPOUT4 = 1;
			break;
		case 6:
			DPOUT1 = 0;
		  DPOUT2 = 0;
		  DPOUT3 = 0;
		  DPOUT4 = 1;
			break;
		case 7:
			DPOUT1 = 1;
		  DPOUT2 = 0;
		  DPOUT3 = 0;
		  DPOUT4 = 1;
			break;
		default:
			MOTOR_off();
			break;
	}
	Delay10us(speed);
	MOTOR_off();
}
