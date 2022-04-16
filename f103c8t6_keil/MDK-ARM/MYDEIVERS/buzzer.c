#include "buzzer.h"

struct notes *notes;

void play_ones(uint16_t freq,uint8_t dutya)
{

TIM2->ARR  = (uint32_t)((72000000/freq)-1);TIM2->CCR3 = (uint32_t)(((72000000/freq)-1)*((float)dutya/100));
}



void add_a_note(uint16_t freq,uint8_t duty,uint16_t deley)
{
struct notes* buff;
buff = (struct notes*)malloc(sizeof(struct notes));
if (buff != NULL)
{
buff->freq = freq;
buff->duty = duty;
buff->deley = deley;
buff->next_note = NULL;

if (notes == NULL)
{
notes = buff;
}
else
{
struct notes *t = notes;
while (t->next_note != NULL)
{
t = t->next_note;
}
t->next_note = buff;
}
}

}

void delhead()                    
{
if (notes == NULL)
{
return;
}


if (notes->next_note == NULL)
{
free(notes);
notes = NULL;
}
else
{
struct notes *t = notes;
notes = notes->next_note;
free(t);

}



}

char buzzer_play_server()                    
{


static char busy_flag=0;
static uint32_t play_delay;

if(notes == NULL)
{
	//play_ones(0,0);
}else
{
	if(busy_flag==0)
	{
		busy_flag=1;
		play_delay=HAL_GetTick()+notes->deley;
		play_ones(notes->freq,notes->duty);
	}
	if(busy_flag==1)
	{
		if(HAL_GetTick()>play_delay)
		{
			busy_flag=0;
			delhead();
		}
	}
}



return busy_flag;
}