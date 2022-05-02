#ifndef MORSE_H_
#define MORSE_H_

#include "main.h"

extern char moser_buff[64+8];

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