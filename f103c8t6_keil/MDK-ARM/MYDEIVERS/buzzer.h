#ifndef BUZZER_H_
#define BUZZER_H_

#include "main.h"




typedef struct note
{
	struct note *next;
	uint16_t    freq;          //??
	uint8_t     duty;           //???
	uint16_t    delay;         //????
}note;

typedef struct notes_buff
{
	note *head;
	note *end;
	uint32_t play_time;
	uint8_t  play_busy:1;

}notes_buff;


void BUZZER_PLAY_INIT();
void BUZZER_PLAY_NOTES(uint16_t freq,uint16_t delay,uint8_t duty);
void BUZZER_PLAY_SERVER();
void BUZZER_PLAY(uint16_t freq,float duty);




#endif /* BUZZER_H_ */
