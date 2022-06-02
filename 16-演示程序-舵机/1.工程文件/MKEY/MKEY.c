#include "MKEY.h"
#include	"delay.h"
/*********************************************************************
文件名称：LED.h
版    本：V1.0
说    明：LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	MKEY_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//初始化
}
/*********************************************************************
函数原型：u8 Mkey_Read(void)
函数功能：矩阵按键键值读取函数
输入参数：无
输出参数：无
*********************************************************************/
u8 Mkey_Read(void)
{
	u8 val=16;
		switch(P6)
		{
			case 0x11:  val = 0;
			break;
			case 0x21:  val = 1;
			break;			
			case 0x41:  val = 2;
			break;			
			case 0x81:  val = 3;
			break;
			
			case 0x12:  val = 4;
			break;			
			case 0x22:  val = 5;
			break;			
			case 0x42:  val = 6;
			break;			
			case 0x82:  val = 7;
			break;				
			
			case 0x14:  val = 8;
			break;			
			case 0x24:  val = 9;
			break;			
			case 0x44:  val = 10;
			break;			
			case 0x84:  val = 11;
			break;			
			
			case 0x18:  val = 12;
			break;			
			case 0x28:  val = 13;
			break;			
			case 0x48:  val = 14;
			break;			
			case 0x88:  val = 15;
			break;	
			default:val=16;
				break;
		}

return val;

}