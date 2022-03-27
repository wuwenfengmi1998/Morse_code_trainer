/*
 * my.c
 *
 *  Created on: 2022年3月27日
 *      Author: wuwen
 */


#include "my.h"

void mymain()
{

	OLED_Init();
	OLED_Init_Display_Buffer(0);

	OLED_ShowStr(0,0,"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");


	while(1)
	{


	}
}
