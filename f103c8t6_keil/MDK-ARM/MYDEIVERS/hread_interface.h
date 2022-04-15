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

#define RUNLED(x)    HAL_GPIO_WritePin(run_led_GPIO_Port, run_led_Pin, x)
#define RUNLED_TICK()  HAL_GPIO_TogglePin(run_led_GPIO_Port, run_led_Pin)

void IIC_SAND_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,uint8_t *DATAS,uint16_t LONG);
void IIC_READ_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,uint8_t *DATAS,uint16_t LONG);
#endif /* HREAD_INTERFACE_H_ */
