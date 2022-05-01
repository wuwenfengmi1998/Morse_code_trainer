#include "encode.h"

void GEI_BUTTON_CODE(button *bt)
{
    #define t 500 //????(ms)
	
		bt->flag=HAL_GPIO_ReadPin(bt->GPIOx,bt->GPIO_Pin);
    bt->code=0;
    if(bt->flag==0)
    {
        if(bt->lock==0)
        {
            if(HAL_GetTick()<bt->time+t)//??????????
            {
            	bt->times++;
            	bt->time=HAL_GetTick();
            	bt->lock=1;

            }else
            {
            	bt->times=1;             //??????
            	bt->time=HAL_GetTick();
            	bt->lock=1;
            }

        }
        if(bt->lock==1)
        {
            if(HAL_GetTick()>bt->time+t)//??????t ms
            {
            	bt->code=255;
            	bt->times=255;
            }                  //????
        }

    }

    if(bt->flag==1)
    {
        if(bt->lock==1)
        {
            if(bt->code==255)
            {

            }else
            {
            	bt->code=bt->times;
            }
            bt->lock=0;
        }

    }



}

int GET_ENCODE(encoder *e)
{
	int buff;
	buff=e->code;
	e->code=0;
	return buff;
}