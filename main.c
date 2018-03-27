#include "hcsr04.h"
#include "adc.h"
#include "uart.h"

void main(){
	ADC_init();
	UART_Init();
	while(1){
	  ADC_Read();
		UART_sendChar(ADC_RES);
		UART_sendChar(ADC_RESL);
	}
}