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

	OLED_ShowChar(0,0,48);

	while(1)
	{


	}
}
