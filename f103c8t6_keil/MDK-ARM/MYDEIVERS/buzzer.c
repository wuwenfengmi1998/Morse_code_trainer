#include "buzzer.h"

notes_buff buzzer_play_buff;

void BUZZER_PLAY(uint16_t freq,float duty)
{
	TIM2->ARR  = (uint32_t)((72000000/freq)-1);
	TIM2->CCR3 = (uint32_t)(((72000000/freq)-1)*((float)duty/100));
}

void BUZZER_PLAY_INIT()
{
	buzzer_play_buff.head=NULL;
	buzzer_play_buff.end=NULL;
	buzzer_play_buff.play_busy=0;

	BUZZER_PLAY(0,0);
}


void BUZZER_PLAY_NOTES(uint16_t freq,uint16_t delay,uint8_t duty)
{
	note *buff,*buff2;
	buff =(note*)malloc(sizeof(note));
	if(buff!=NULL)
	{
		buff->delay=delay;
		buff->duty=duty;
		buff->freq=freq;
		buff->next=NULL;
	}else{return ;}
	if(buzzer_play_buff.head==NULL)
	{
		buzzer_play_buff.head=buff;
		buzzer_play_buff.end=buff;
	}else
	{
		buff2=buzzer_play_buff.end;
		buff2->next=buff;
		buzzer_play_buff.end=buff;
	}
}

void BUZZER_PLAY_SERVER()
{
	note *buff;
	char data;
	if(buzzer_play_buff.play_busy)
		{
			if(HAL_GetTick()>buzzer_play_buff.play_time)
			{
				buzzer_play_buff.play_busy=0;
				BUZZER_PLAY(0,0);
			}
		}else
		{
			if(buzzer_play_buff.head!=NULL)
			{
				buzzer_play_buff.play_busy=1;
				buzzer_play_buff.play_time=HAL_GetTick()+buzzer_play_buff.head->delay;
				buff=buzzer_play_buff.head->next;
				BUZZER_PLAY(buzzer_play_buff.head->freq,buzzer_play_buff.head->duty);
				free(buzzer_play_buff.head);
				buzzer_play_buff.head=buff;
			}

		}
}



