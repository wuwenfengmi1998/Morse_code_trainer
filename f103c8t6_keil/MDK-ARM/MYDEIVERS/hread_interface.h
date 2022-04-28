/*
 * hread_interface.h
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */

#ifndef HREAD_INTERFACE_H_
#define HREAD_INTERFACE_H_

#include "main.h"


extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim2;
#define RUNLED(x)    HAL_GPIO_WritePin(run_led_GPIO_Port, run_led_Pin, x)
#define MUTE(x)      HAL_GPIO_WritePin(mute_GPIO_Port, mute_Pin, x)
#define tack_a()      HAL_GPIO_ReadPin(tack_a_GPIO_Port, tack_a_Pin)
#define tack_b()      HAL_GPIO_ReadPin(tack_b_GPIO_Port, tack_b_Pin)



#define RUNLED_TICK()  HAL_GPIO_TogglePin(run_led_GPIO_Port, run_led_Pin)

void IIC_SAND_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,uint8_t *DATAS,uint16_t LONG);
void IIC_READ_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,uint8_t *DATAS,uint16_t LONG);
#endif /* HREAD_INTERFACE_H_ */
