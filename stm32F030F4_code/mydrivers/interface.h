/*
 * interface.h
 *
 *  Created on: 2022年3月27日
 *      Author: wuwen
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "main.h"
extern I2C_HandleTypeDef hi2c1;

void IIC_SAND_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,char *DATAS,uint16_t LONG);
void IIC_READ_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,char *DATAS,uint16_t LONG);


#endif /* INTERFACE_H_ */
