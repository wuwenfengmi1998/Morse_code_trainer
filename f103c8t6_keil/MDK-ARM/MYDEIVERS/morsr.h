#ifndef MORSE_H_
#define MORSE_H_

#include "main.h"

#define morse_t1 150
#define morse_t2 (morse_t1*3)
#define morse_hz 100

#define moser_buff_size 147
extern char moser_buff[moser_buff_size+8];

struct morsecode
{
	uint8_t len;
	uint8_t code;
	char letter;
};

void mo_server();
void mo_di();
void mo_da();
void mo_one_tick(uint8_t i);

#endif /* MYMAIN_H_ */