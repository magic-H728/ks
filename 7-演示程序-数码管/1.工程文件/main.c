#include "config.h"
#include "GPIO.h"
#include "LED.h"
#include "delay.h"
#include "PULSE_IN_BIT_OUT.h"
#include "KEY.h"
#include "MKEY.h"
#include "BMKEY.h"
#include "YBUZZER.h"
#include "WBUZZER.h"
#include "ONELED.h"

u8 count=16,i;
void main(void)
{
	Special_IO_Init();		//特殊端口初始化函数

	ONELED_GPIO_config();
	while(1)							//循环
	{
		for(i=0;i<16;i++)
		{
			P7=one_mum[i];
			delay_ms(500);
		}
	}
}

