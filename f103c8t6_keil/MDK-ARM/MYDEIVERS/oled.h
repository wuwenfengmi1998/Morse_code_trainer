/*
 * oled.h
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */

#ifndef OLED_H_
#define OLED_H_

#include "main.h"
#include "hread_interface.h"

#define OLED_ADDRESS 0x78
#define PI 3.141592654
#define X_WIDTH 128
#define Y_WIDTH 64
#define Y_WIDTH_ 8

void OLED_Init(void);

void OLED_Cache_to_hardware();

void OLED_set_dot(unsigned char x,unsigned char y,unsigned char dot_type);
void OLED_Pix(unsigned char x,unsigned char y,unsigned char w,unsigned char h,const char *p,unsigned char type);

void OLED_Ascii(unsigned char x,unsigned char y,unsigned char size,char chr,unsigned char type);
void OLED_Str(unsigned char x,unsigned char y,unsigned char size,char *str,unsigned char type);

void OLED_AL(int sx,int sy,int ex,int ey,unsigned char dot_type);
#endif /* OLED_H_ */
