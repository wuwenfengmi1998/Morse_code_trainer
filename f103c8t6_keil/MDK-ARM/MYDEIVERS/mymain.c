/*
 * mymain.c
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */
#include "mymain.h"
#include "hread_interface.h"

#define morse_t1 150
#define morse_t2 (morse_t1*3)
#define morse_hz 100

#define morse_play_t1 50
#define morse_play_t2 (morse_play_t1*3)
#define morse_play_hz 100

char push_key=0,last_key=1;
uint32_t morse_t=0;
uint32_t morse_time_out=0;
uint16_t morse_temp;

#define morse_input_buff_num 128
char morse_input_buff[morse_input_buff_num+1];
int morse_input_flag=0;
int morse_char_flag=0;
int morse_x,morse_y;
char morse_flah=0;
uint8_t morse_letter_temp=0;
uint8_t morse_letter_flag=0;

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

const char testbmp[]=
{
0x00,0x00,0x02,0x00,0x0F,0x00,0x00,0x0F,0x00,0x0F,0x00,0x00,0x09,0x00,0x0F,0x0F,
0x00,0x0D,0x80,0x0F,0x05,0xC0,0x18,0x80,0x0F,0x0C,0x70,0xF0,0xC0,0x0F,0x08,0x3F,
0x81,0x70,0x0F,0x04,0x14,0x7F,0xF0,0x0F,0x0C,0x01,0xAC,0x18,0x0F,0x04,0x0F,0xC0,
0x38,0x0F,0x06,0x78,0x07,0xEC,0x0F,0x0D,0xC0,0x7E,0x86,0x0F,0x07,0x03,0xC0,0x06,
0x0F,0x06,0x1E,0x00,0x0E,0x0F,0x0C,0x70,0x00,0x0F,0x0F,0x0D,0xC0,0x10,0x07,0x8F,
0x0F,0x00,0x18,0x01,0x8F,0x1C,0x00,0x18,0x1F,0xCF,0x18,0x00,0x18,0x75,0xCF,0x38,
0x00,0x00,0x3F,0x4F,0x38,0x00,0x00,0x04,0x6F,0x38,0x00,0x00,0x06,0x3F,0x38,0x00,
0x00,0x02,0x7F,0x68,0x00,0x00,0x0F,0xFF,0x58,0x00,0x00,0xFA,0x2F,0xC8,0x00,0x03,
0xC0,0xEF,0xD8,0x00,0x02,0x0F,0x8F,0x98,0x00,0x00,0x1A,0x0F,0x98,0x00,0x00,0x38,
0x0F,0x38,0x00,0x00,0x10,0x0F
};



char getmorsecode(uint8_t len,uint8_t code)
{
	for(int a=0;a<morsecodenum;a++)
	{
		if((morsecodes[a].len==len)&&(morsecodes[a].code==code))
		{
			return morsecodes[a].letter;
		}

	}
	return 0;
}

void mymain()
{
	uint32_t run_tick=0;
	char str[16];
	uint16_t fps=0,fps_=0;
	
	OLED_Init();
	
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);//启动n通道的pwm
	MUTE(0);
	add_a_note(1000,50,1000);
	while(1)
	{
		
		char get_char_temp;
		push_key=tack_b();
		

	if(push_key!=last_key)
	{

		if(push_key==0)
		{
			morse_t=HAL_GetTick();
			play_ones(morse_hz,50);
		}else
		{
			morse_temp=HAL_GetTick()-morse_t;
			if(morse_temp>morse_t2)
			{
				//time out error
			}else if(morse_temp>morse_t1)
			{
				//-
				morse_input_buff[morse_input_flag]='-';
				morse_letter_temp|=(0x80>>morse_letter_flag);
			}else
			{
				//.
				morse_input_buff[morse_input_flag]='.';

			}
			morse_input_flag++;
			morse_letter_flag++;
			//if(morse_input_flag>=morse_char_flag+8){morse_input_flag=morse_char_flag;morse_letter_flag=0;}
			play_ones(0,0);
		}


		last_key=push_key;
		morse_time_out=HAL_GetTick();
	}

	if(push_key==1)
	{
		//Get cursor on the screen
		if((HAL_GetTick()-morse_time_out)>morse_t1)
		{
				if((morse_input_flag-morse_char_flag)>0)
				{

				get_char_temp=getmorsecode(morse_letter_flag,morse_letter_temp);
			
				morse_letter_flag=0;
				morse_letter_temp=0;
				if(get_char_temp!=0)
				{
					morse_input_buff[morse_char_flag]=get_char_temp;
					morse_flah=1;
					morse_char_flag+=1;
				}

				morse_input_flag=morse_char_flag;


			}
		}
		if((HAL_GetTick()-morse_time_out)>morse_t2)
		{
			if(morse_flah==1)
			{
				morse_input_buff[morse_char_flag]=' ';
				morse_char_flag+=1;
				morse_input_flag=morse_char_flag;
				morse_flah=0;
			}
		}
	}

	
		OLED_Str(0,0,8,morse_input_buff,1);
		
		
		fps_++;
		sprintf(str,"FPS:%d",fps);
		OLED_Str(0,56,8,str,1);
		OLED_Cache_to_hardware();
		buzzer_play_server();
		if(HAL_GetTick()>run_tick)
		{
			run_tick+=1000;
			RUNLED_TICK();
			fps=fps_;
			fps_=0;
		}
	
	}
}
