#include "adc.h"

void ADC_init(unsigned char CHS,unsigned char ADC_SPEED){
  CHS &= 0x70;
  P1ASF = 0xff;
  P1M1 = 0xff;
  P1M0 = 0x00;
  ADC_CONTR = 0x80 | ADC_SPEED | CHS;
  Delay1ms(2);
}

// ‰»Î0-1024
unsigned int ADC_Read(){
  unsigned char ADFLAG = 0x00;
  ADC_CONTR |= 0x08;
  _nop_();
  _nop_();
  _nop_();
  while(!(ADC_CONTR & 0x10));
  ADC_CONTR &= 0xef;
  return (ADC_RES << 2 | ADC_RESL);
}