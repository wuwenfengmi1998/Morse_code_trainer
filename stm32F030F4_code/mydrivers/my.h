/*
 * my.h
 *
 *  Created on: 2022年3月27日
 *      Author: wuwen
 */

#ifndef MY_H_
#define MY_H_

#include "main.h"
#include "OLED.h"

#define KEY0 HAL_GPIO_ReadPin(tack_A_GPIO_Port, tack_A_Pin)
#define KEY1 HAL_GPIO_ReadPin(tack_B_GPIO_Port, tack_B_Pin)
#define SW_C HAL_GPIO_ReadPin(SW_C_GPIO_Port, SW_C_Pin)


struct morsecode
{
	uint8_t len;
	uint8_t code;
	char letter;
};

void mymain();

#endif /* MY_H_ */
