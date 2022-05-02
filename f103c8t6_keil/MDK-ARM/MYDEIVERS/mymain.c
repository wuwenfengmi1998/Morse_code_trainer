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
#define morse_play_hz 1000







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

void di()
{
	BUZZER_PLAY_NOTES(morse_play_hz,morse_play_t1,50);
	BUZZER_PLAY_NOTES(0,morse_play_t1,0);
	mo_di();
}

void da()
{
	BUZZER_PLAY_NOTES(morse_play_hz,morse_play_t2,50);
	BUZZER_PLAY_NOTES(0,morse_play_t1,0);
	mo_da();
}

void mymain()
{
	PWR_EN(1);
	
	//按钮定义接口
	B1.GPIOx=en_c_GPIO_Port;
	B1.GPIO_Pin=en_c_Pin;
	
	
	OLED_Init();//屏幕初始化
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);//启动n通道的pwm
	HAL_TIM_Base_Start_IT(&htim3);
	BUZZER_PLAY_INIT();
	MUTE(0);

	BUZZER_PLAY_NOTES(1000,1000,50);
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
				if(encode_c>0)
				{
					di();
				}
				if(encode_c<0)
				{
					da();
				}			
				OLED_Str(0,0,8,moser_buff,1);

			
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

		
		mo_server();
		BUZZER_PLAY_SERVER();
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
			switch(tack_a())
			{
				case 0:
					//di();
					break;
				case 1:
					break;
			}
		break;
		case tack_b_Pin:
			switch(tack_b())
			{
				case 0:
					//da();
					break;
				case 1:
					break;
			}
		break;
		
		
		case en_c_Pin://编码器C脚 按钮
			switch(en_c())//监测是上升沿还是下降沿
			{
				case 0:
					
					//mo_one_tick(0);
					break;
				case 1:
					
					//mo_one_tick(1);
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