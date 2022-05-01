/*
 * mymain.c
 *
 *  Created on: 2022年4月15日
 *      Author: wuwen
 */
#include "mymain.h"


#define morse_t1 150
#define morse_t2 (morse_t1*3)
#define morse_hz 100

#define morse_play_t1 50
#define morse_play_t2 (morse_play_t1*3)
#define morse_play_hz 100



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


button  B1;//创建一个按钮
encoder E1;//创建一个编码器
int mode=0;
uint32_t run_tick=0,jump_tick=0;
char str[16];
uint16_t fps=0,fps_=0;
char sys_lan=0;

int encode_c=0;

int test_code=0;

menu menu_main=
{
		"Back\nInput mode\nBuzzer\nDisplay\nLanguage\nAbout",
	"返回\n输入模式\n蜂鸣器\n显示\n语言\n关于",

		0,0
};

void mymain()
{
	PWR_EN(1);
	
	//按钮定义接口
	B1.GPIOx=en_c_GPIO_Port;
	B1.GPIO_Pin=en_c_Pin;
	
	
	OLED_Init();//屏幕初始化
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);//启动n通道的pwm
	HAL_TIM_Base_Start_IT(&htim3);
	MUTE(0);

	//play_ones(1000,50);
	while(1)
	{
		GEI_BUTTON_CODE(&B1);//循环更新按钮
		encode_c=GET_ENCODE(&E1);
		
		switch(mode)
		{
			case 0:
				//启动跳转模式
				//用于读取系统配置后跳转到其他程序
			
				mode=1;
				break;
			case 1:
				//主界面
			
				

			
				fps_++;
				sprintf(str,"FPS:%d",fps);
				OLED_Str(0,56,8,str,1);
			
				if(B1.code==255)
				{
					mode=2;
					jump_tick=HAL_GetTick()+10000;
				}
				
				break;
			case 2:
				//菜单界面
				if(encode_c!=0)
				{
					jump_tick=HAL_GetTick()+10000;
				}
				switch(SHOW_MENU(&menu_main,encode_c,B1.code,sys_lan))
				{
					case 0:
						mode=1;
						break;
				}
				if(HAL_GetTick()>jump_tick){mode=1;}
				break;
		
		}

		
		
		
		OLED_Cache_to_hardware();//刷新屏幕
		
		if(HAL_GetTick()>run_tick)
		{
			run_tick+=1000;
			RUNLED_TICK();
			fps=fps_;
			fps_=0;
		}
	
	}
}

//外部中断回调
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	switch (GPIO_Pin)//中断线监测
	{
  	case en_a_Pin: //编码器A脚 这个脚在config是只监测下降沿
			switch(HAL_GPIO_ReadPin(en_b_GPIO_Port,en_b_Pin))//监测编码器B脚
			{
				case 1://通过监测B脚的状态识别正反转
					E1.code+=1;
					E1.move_flag=1;//发生旋转的标记
					break;
				case 0:
					E1.code-=1;
					E1.move_flag=1;
					break;
			}
		break;

		//外部电键输入
		case tack_a_Pin:
			test_code++;
		break;
		case tack_b_Pin:
			test_code--;
		break;
		
		
		case en_c_Pin://编码器C脚 按钮
			switch(en_c())//监测是上升沿还是下降沿
			{
				case 0:
					
					mo_one_tick(0);
					break;
				case 1:
					
					mo_one_tick(1);
					break;
			}
			break;
  	default:
  	break;

  	//__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
  }
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//1ms
{
    if (htim == (&htim3))
		{
		
		}
}