/*
 * mymain.h
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */

#ifndef MYMAIN_H_
#define MYMAIN_H_

#include "main.h"
#include "oled.h"
#include "buzzer.h"
#include "encode.h"
#include "hread_interface.h"
struct morsecode
{
	uint8_t len;
	uint8_t code;
	char letter;
};

extern TIM_HandleTypeDef htim3;

void mymain();

#endif /* MYMAIN_H_ */
