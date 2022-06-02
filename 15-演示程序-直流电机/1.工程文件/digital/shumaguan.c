#include "shumaguan.h"


unsigned char code dis_t[] = {0xFC,0x90,0xE5,0xF1,0x99,0x79,0x7D,0xD0,0xFD,0xF9,0xDD,0x3D,0x6C,0xB5,0x6D,0x4D,0x02, 0x01};
//                            '0'  '1'  '2'  '3'  '4'  '5'  '6'  '7'  '8'  '9'  'a'  'b'  'c'  'd'  'e'  'f'  '.'   '-'

unsigned char smg_data[8] ={0};
static unsigned char cnt = 0, sec = 0, min = 0;


//局部短延时
static void delay_us(unsigned int ms)
{
	while(ms--)
		_nop_();
}

//根据数据的bit位将相应的bit位输出到138译码器的3个输入端
void HC138_bit(unsigned char dat)
{
	A138_Bit = (dat & 0x01) ? 1 : 0;
	B138_Bit = (dat & 0x02) ? 1 : 0;
	C138_Bit = (dat & 0x04) ? 1 : 0;
}

//数码管驱动
void Smg_test(void)
{
	unsigned char i;
	
	for(i=0; i<8; i++)
	{
		HC138_bit(i);
		Data_Bit = dis_t[smg_data[i]];
		delay_us(600);
		Data_Bit = 0x00;
	}
}

void updata_display(void)
{
	smg_data[0] = min / 10;
	smg_data[1] = min % 10;
	
	smg_data[2] = 17;
	
	smg_data[3] = sec / 10;
	smg_data[4] = sec % 10;
	
	smg_data[5] = 17;
	
	smg_data[6] = cnt / 10;
	smg_data[7] = cnt % 10;
}

void timer1_cnt_fun(void)
{
	if(cnt > 99)
	{
		cnt = 0;
		if(sec > 59)
		{
			sec = 0;
			min++;
		}else
		{
			sec++;
		}
	}else
	{
		cnt++;
	}
	
	updata_display();//更新显示八段数码管的缓存
}


