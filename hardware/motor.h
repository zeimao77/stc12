#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <stc12c5a60s2.h>
#include "delay.h"

sbit DPOUT1=P2^0;
sbit DPOUT2=P2^1;
sbit DPOUT3=P2^2;
sbit DPOUT4=P2^3;

void MOTOR_off();
void MOTOR_run(unsigned char rl,unsigned int num,unsigned int speed);
void MOTOR_Pi(unsigned char pi,unsigned int speed);
#endif