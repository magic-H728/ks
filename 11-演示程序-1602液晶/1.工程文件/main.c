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
#include "FOURLED.h"
#include "LED88.h"
#include "LED1616.h"
#include "LCD1602.h"
#include "stdio.h"

u8 i, buffer[16];
u16 count = 0;
void main(void)
{

	Special_IO_Init();		//特殊端口初始化函数
	LCD1602_GPIO_config();
	lcd1602_init();
	lcd1602_clear();
	
	lcd1602_show_str(0x00,"-CGRAM:"); //显示-CGRAM
	for(i=0;i<8;i++)
	{
		lcd1602_show_char(7+i,i);
	}
	lcd1602_show_str(0x0F,"-");
	lcd1602_show_str(0x40,"-REMOTE-MCU");
	lcd1602_show_str(0x4F,"-");
	
	while(1)							//循环
	{
		count++;
		if(count>=10000)count=0;
		sprintf((char*)buffer,"%04d",count);
		lcd1602_show_str(0x4B,buffer);
		delay_ms(1000);
	}
}

