#ifndef BUZZER_H_
#define BUZZER_H_

#include "main.h"

struct notes             
{
	uint16_t freq;          
	uint8_t duty;           
	uint16_t deley;         
	struct notes *next_note;
};

void play_ones(uint16_t freq,uint8_t dutya);
void add_a_note(uint16_t freq,uint8_t duty,uint16_t deley);
char buzzer_play_server();

#endif /* BUZZER_H_ */
