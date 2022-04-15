/*
 * hread_interface.c
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */

#include "hread_interface.h"

void IIC_SAND_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,char *DATAS,uint16_t LONG)
{
	HAL_I2C_Mem_Write(&hi2c1,DEVICE_ADD,IN_DEVICE_ADD,I2C_MEMADD_SIZE_8BIT,DATAS,LONG,100);
}

void IIC_READ_DATE(uint16_t DEVICE_ADD,uint16_t IN_DEVICE_ADD,char *DATAS,uint16_t LONG)
{
	HAL_I2C_Mem_Read(&hi2c1,DEVICE_ADD,IN_DEVICE_ADD,I2C_MEMADD_SIZE_8BIT,DATAS,LONG,100);
}
