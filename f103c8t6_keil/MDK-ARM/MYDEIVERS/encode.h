#ifndef ENCODER_H_
#define ENCODER_H_

#include "main.h"



typedef struct button
{
	uint8_t  flag;
	uint16_t  code;
	uint8_t   lock;
	uint32_t  time;
	uint16_t  times;
	uint8_t  config_longtimes;
} button;

typedef struct
{
	int  code;
	uint8_t   move_flag:1;
} encoder;

void GEI_BUTTON_CODE(button *bt,uint8_t flag);
int GET_ENCODE(encoder *e);
#endif /* ENCODER_H_ */
