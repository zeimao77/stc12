#ifndef _ADC_H_
#define _ADC_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define ADC_SPEED_90 0x60;
#define ADC_SPEED_180 0x40;
#define ADC_SPEED_360 0x20;
#define ADC_SPEED_540 0x00;

void ADC_init(unsigned char CHS,unsigned char ADC_SPEED);

//Êä³ö0-1024
unsigned int ADC_Read();

#endif