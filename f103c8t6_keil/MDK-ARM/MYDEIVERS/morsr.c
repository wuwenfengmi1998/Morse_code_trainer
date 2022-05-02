#include "morsr.h"


#define morsecodenum 38
const struct morsecode morsecodes[morsecodenum]=
{
		{
				2,0x40,'A'
		},
		{
				4,0x80,'B'
		},
		{
				4,0xa0,'C'
		},
		{
				3,0x80,'D'
		},
		{
				1,0x00,'E'
		},
		{
				4,0x20,'F'
		},
		{
				3,0xc0,'G'
		},
		{
				4,0x00,'H'
		},
		{
				2,0x00,'I'
		},
		{
				4,0x70,'J'
		},
		{
				3,0xa0,'K'
		},
		{
				4,0x40,'L'
		},
		{
				2,0xc0,'M'
		},
		{
				2,0x80,'N'
		},
		{
				3,0xe0,'O'
		},
		{
				4,0x60,'P'
		},
		{
				4,0xd0,'Q'
		},
		{
				3,0x40,'R'
		},
		{
				3,0x00,'S'
		},
		{
				1,0x80,'T'
		},
		{
				3,0x20,'U'
		},
		{
				4,0x10,'V'
		},
		{
				3,0x60,'W'
		},
		{
				4,0x90,'X'
		},
		{
				4,0xb0,'Y'
		},
		{
				4,0xc0,'Z'
		},
		{
				5,0x78,'1'
		},
		{
				5,0x38,'2'
		},
		{
				5,0x18,'3'
		},
		{
				5,0x08,'4'
		},
		{
				5,0x00,'5'
		},
		{
				5,0x80,'6'
		},
		{
				5,0xc0,'7'
		},
		{
				5,0xe0,'8'
		},
		{
				5,0xf0,'9'
		},
		{
				5,0xf8,'0'
		},
		{
				6,0x30,'?'
		},
		{
				5,0x90,'/'
		},

};

char get_morse_code(uint8_t len,uint8_t code)
{
	for(int a=0;a<morsecodenum;a++)
	{
		if((morsecodes[a].len==len)&&(morsecodes[a].code==code))
		{
			return morsecodes[a].letter;
		}

	}
	return ' ';
}



char moser_buff[64+8]={0};
uint8_t  moser_buff_int=0;
uint8_t  moser_code_len=0;
uint8_t  moser_code=0;
uint32_t moser_tick_time=0;
uint8_t  moser_input_flag=0;

void mo_server()
{
	
	if(moser_input_flag==1&&HAL_GetTick()>moser_tick_time)
	{
		moser_input_flag=0;
		for(int a=0;a<8;a++)
		{
			moser_buff[moser_buff_int+a]='\0';
		}
		moser_buff[moser_buff_int]=get_morse_code(moser_code_len,moser_code);
		moser_buff_int+=1;
		if(moser_buff_int==64)
		{
			for(int a=0;a<64;a++)
			{
				moser_buff[a]='\0';
			}
			moser_buff_int=0;
		}		
		moser_code_len=0;
		moser_code=0;
	}

}

void mo_di()
{
	moser_buff[moser_buff_int+moser_code_len]='.';
	moser_code_len+=1;
	if(moser_code_len==8){moser_code_len=0;}
	moser_tick_time=HAL_GetTick()+400;
	moser_input_flag=1;
}

void mo_da()
{
	moser_buff[moser_buff_int+moser_code_len]='-';
	moser_code|=(0x80>>moser_code_len);
	moser_code_len+=1;
	if(moser_code_len==8){moser_code_len=0;}
	moser_tick_time=HAL_GetTick()+400;
	moser_input_flag=1;
}

void mo_one_tick(uint8_t i)
{
	static uint8_t last_input=1;
	static uint32_t tick_time;
	uint16_t tick_time_cat;
	if(i!=last_input)
	{
		last_input=i;
		
		switch(last_input)
		{
			case 0:
				tick_time=HAL_GetTick();
				break;
			case 1:
				tick_time_cat=HAL_GetTick()-tick_time;
				if(tick_time_cat<100)
				{
					
				}else if(tick_time_cat<200)
				{
					mo_di();
				}else if(tick_time_cat<400)
				{
					mo_da();
				}else
				{
					
				}
				break;
		}
	
	}
	
}