/*
 * buzzer.h
 *
 *  Created on: 2022年4月2日
 *      Author: wuwen
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "main.h"

extern   TIM_HandleTypeDef htim14;


void play_ones(uint16_t freq,uint8_t dutya);

#endif /* BUZZER_H_ */
