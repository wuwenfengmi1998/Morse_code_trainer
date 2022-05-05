#include "encode.h"

void GEI_BUTTON_CODE(button *bt,uint8_t flag)
{
    #define t 500 //timeout (ms)
	
		bt->flag=flag;
    bt->code=0;
    if(bt->flag==0)
    {
        if(bt->lock==0)
        {
            if(HAL_GetTick()<bt->time+t)//
            {
            	bt->times++;
            }else
            {
            	bt->times=1;             //      	
            }
							bt->time=HAL_GetTick();
            	bt->lock=1;
							bt->code=bt->times;
        }
        if(bt->config_longtimes==1)
				{
					if(HAL_GetTick()>bt->time+t)//
					{
						bt->code=255;
						bt->times=255;
					}                		
				}
    }

    if(bt->flag==1)
    {
        if(bt->lock==1)
        {
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