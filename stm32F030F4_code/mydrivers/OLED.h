/*
 * OLED.h
 *
 *  Created on: 2022年3月27日
 *      Author: wuwen
 */

#ifndef OLED_H_
#define OLED_H_

#include "main.h"
#include "interface.h"
#define OLED_ADDRESS 0x78
#define PI 3.141592654
#define X_WIDTH 128
#define Y_WIDTH 64
#define Y_WIDTH_ 8


void OLED_Init(void);
void OLED_Init_Display_Buffer(char a);
void OLED_ShowChar(unsigned char x,unsigned char y,unsigned char chr);


#endif /* OLED_H_ */
