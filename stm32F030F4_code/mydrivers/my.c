/*
 * my.c
 *
 *  Created on: 2022年3月27日
 *      Author: wuwen
 */


#include "my.h"

#define morse_t0 50
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

#define morse_input_buff_num 64

char morse_input_flag=0;
char morse_char_flag=0;
char morse_x=0,morse_y=0,morse_x_=0,morse_y_=0;
char morse_flah=0;
uint8_t morse_letter_temp=0;
uint8_t morse_letter_flag=0;
#define morsecodenum 38
const struct morsecode morsecodes[morsecodenum]=
{
		{
				2,0b01000000,'A'
		},
		{
				4,0b10000000,'B'
		},
		{
				4,0b10100000,'C'
		},
		{
				3,0b10000000,'D'
		},
		{
				1,0b00000000,'E'
		},
		{
				4,0b00100000,'F'
		},
		{
				3,0b11000000,'G'
		},
		{
				4,0b00000000,'H'
		},
		{
				2,0b00000000,'I'
		},
		{
				4,0b01110000,'J'
		},
		{
				3,0b10100000,'K'
		},
		{
				4,0b01000000,'L'
		},
		{
				2,0b11000000,'M'
		},
		{
				2,0b10000000,'N'
		},
		{
				3,0b11100000,'O'
		},
		{
				4,0b01100000,'P'
		},
		{
				4,0b11010000,'Q'
		},
		{
				3,0b01000000,'R'
		},
		{
				3,0b00000000,'S'
		},
		{
				1,0b10000000,'T'
		},
		{
				3,0b00100000,'U'
		},
		{
				4,0b00010000,'V'
		},
		{
				3,0b01100000,'W'
		},
		{
				4,0b10010000,'X'
		},
		{
				4,0b10110000,'Y'
		},
		{
				4,0b11000000,'Z'
		},
		{
				5,0b01111000,'1'
		},
		{
				5,0b00111000,'2'
		},
		{
				5,0b00011000,'3'
		},
		{
				5,0b00001000,'4'
		},
		{
				5,0b00000000,'5'
		},
		{
				5,0b10000000,'6'
		},
		{
				5,0b11000000,'7'
		},
		{
				5,0b11100000,'8'
		},
		{
				5,0b11110000,'9'
		},
		{
				5,0b11111000,'0'
		},
		{
				6,0b00110000,'?'
		},
		{
				5,0b10010000,'/'
		},

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
	return ' ';
}

void mymain()
{

	char str[16];
	char get_char_temp;

	OLED_Init();
	OLED_Init_Display_Buffer(0);

	//OLED_ShowStr(0,0,"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	//HAL_TIM_PWM_Start(&htim14,TIM_CHANNEL_1);//启动n通道的pwm
	//play_ones(1000,50);
	while(1)
	{

		push_key=KEY1;
		if(push_key!=last_key)
		{

			if(push_key==0)
			{
				morse_t=HAL_GetTick();
				//play_ones(morse_hz,50);
				//OLED_ShowStr(0,0,"1");
			}else
			{
				morse_temp=HAL_GetTick()-morse_t;
				if(morse_temp<morse_t0)
				{
					//time out error



				}else if(morse_temp>morse_t1)
				{
					//-

					OLED_ShowChar(morse_x,morse_y,'-');
					morse_letter_temp|=(0x80>>morse_letter_flag);
					morse_letter_flag++;
					morse_x+=8;
					if(morse_x>=X_WIDTH)
					{
						morse_x=0;
						morse_y+=2;
						if(morse_y>=Y_WIDTH_)
						{
							morse_y=0;

							OLED_Init_Display_Buffer(0);
						}
					}
				}else
				{
					//.

					OLED_ShowChar(morse_x,morse_y,'.');
					morse_letter_flag++;
					morse_x+=8;
					if(morse_x>=X_WIDTH)
					{
						morse_x=0;
						morse_y+=2;
						if(morse_y>=Y_WIDTH_)
						{
							morse_y=0;

							OLED_Init_Display_Buffer(0);
						}
					}

				}


				//play_ones(0,0);

				morse_input_flag=1;
			}


			last_key=push_key;
			morse_time_out=HAL_GetTick();
		}

		if(push_key==1&morse_input_flag==1)
		{
			//Get cursor on the screen
			if((HAL_GetTick()-morse_time_out)>morse_t1)
			{

				get_char_temp=getmorsecode(morse_letter_flag,morse_letter_temp);
				morse_letter_temp=0;

				while(morse_letter_flag!=0)
				{
					if(morse_x==0)
					{
						morse_x=X_WIDTH;
						morse_y-=2;
					}
					morse_x-=8;
					OLED_ShowChar(morse_x,morse_y,' ');
					morse_letter_flag--;
				}
				OLED_ShowChar(morse_x,morse_y,get_char_temp);
				morse_x+=8;
				if(morse_x>=X_WIDTH)
				{
					morse_x=0;
					morse_y+=2;
					if(morse_y>=Y_WIDTH_)
					{
						morse_y=0;

						OLED_Init_Display_Buffer(0);
					}
				}

				morse_input_flag=0;
			}


		}
	}
}
