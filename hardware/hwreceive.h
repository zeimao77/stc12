#ifndef _HWRECEIVE_H_
#define _HWRECEIVE_H_

#include <stc12c5a60s2.h>
#include "delay.h"

sbit RECE = P3^3;

unsigned char* getcodedata();

const unsigned char code  MP3HWTAB[][2];

#endif