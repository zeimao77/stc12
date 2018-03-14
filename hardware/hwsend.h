#ifndef _HWSEND_H_
#define _HWSEND_H_
  
#include <stc12c5a60s2.h>
#include "delay.h"

#define ST 1;
#define SE 0;

sbit SENDHW = P1^2;

void sendhw(unsigned char codedata[]);
	
#endif