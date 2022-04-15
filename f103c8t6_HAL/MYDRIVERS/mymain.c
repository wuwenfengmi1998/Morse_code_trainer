/*
 * mymain.c
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */
#include "mymain.h"
#include "hread_interface.h"

void mymain()
{


	//HAL_GPIO_WritePin(run_led_GPIO_Port, run_led_Pin, 1);
	//OLED_Init();
	//OLED_ShowStr(0,0,"test");
	while(1)
	{
		HAL_GPIO_WritePin(run_led_GPIO_Port, run_led_Pin, 1);
		HAL_GPIO_WritePin(run_led2_GPIO_Port, run_led2_Pin, 1);
		HAL_Delay(100);
		HAL_GPIO_WritePin(run_led_GPIO_Port, run_led_Pin, 0);
		HAL_GPIO_WritePin(run_led2_GPIO_Port, run_led2_Pin, 0);
		HAL_Delay(100);
	}
}
