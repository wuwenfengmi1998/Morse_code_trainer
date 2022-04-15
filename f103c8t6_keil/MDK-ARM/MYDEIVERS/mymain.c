/*
 * mymain.c
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */
#include "mymain.h"
#include "hread_interface.h"


const char testbmp[]=
{
0x00,0x00,0x00,0x00,0x16,0x1D,0x10,0x18,0x08,0x0C,0x06,0x07,0x02,0x03,0x02,0x02,
0x06,0x05,0x05,0x0D,0x79,0x51,0xC1,0x73,0x1D,0x07,0x03,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0x2C,0x19,0x11,0x33,0x22,0x26,
0x64,0x44,0x4C,0xC8,0xC8,0x58,0x90,0x11,0x90,0xB0,0x30,0x20,0x30,0x20,0x60,0xC0,
0xE6,0x3F,0x1F,0x03,0x01,0x00,0x00,0x00,0x00,0x01,0x1F,0x7E,0xFF,0xC0,0x80,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0x00,0x00,0x00,
0x00,0x20,0x30,0x70,0x51,0x7D,0x57,0xF1,0xE1,0x7B,0x0F,0x07,0x7B,0xE3,0x07,0xBF,
0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
0x03,0x03,0x63,0x43,0xC3,0xC3,0x8B,0x9F,0xBB,0x23,0xB3,0x23,0x63,0x43,0xC3,0x03
};


void mymain()
{
uint32_t run_tick=0;
	
	OLED_Init();
	

	OLED_Pix(0,0,36,32,testbmp);
	while(1)
	{

		
		//OLED_Cache_to_hardware();
		if(HAL_GetTick()>run_tick)
		{
				run_tick+=500;
				RUNLED_TICK();
		}
	
	}
}
