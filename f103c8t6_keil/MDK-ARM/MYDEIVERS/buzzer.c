#include "buzzer.h"

struct notes *notes;

void play_ones(uint16_t freq,uint8_t dutya)
{

TIM2->ARR  = (uint32_t)((72000000/freq)-1);TIM2->CCR3 = (uint32_t)(((72000000/freq)-1)*((float)dutya/100));
}



