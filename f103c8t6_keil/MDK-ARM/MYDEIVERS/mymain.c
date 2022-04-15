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
uint32_t run_tick=0;
	
	OLED_Init();
	
	
	
	while(1)
	{

		
		OLED_Cache_to_hardware();
		if(HAL_GetTick()>run_tick)
		{
				run_tick+=500;
				RUNLED_TICK();
		}
	
	}
}
