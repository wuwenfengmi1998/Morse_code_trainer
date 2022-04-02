/*
 * buzzer.c
 *
 *  Created on: 2022年4月2日
 *      Author: wuwen
 */


#include "buzzer.h"

void play_ones(uint16_t freq,uint8_t dutya)
{
//寄存器写法  需要根据单片机的时钟来写。
TIM14->ARR  = (uint32_t)((48000000/freq)-1);TIM14->CCR1 = (uint32_t)(((48000000/freq)-1)*((float)dutya/100));
}

