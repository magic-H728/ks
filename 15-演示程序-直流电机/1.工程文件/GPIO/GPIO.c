#include	"GPIO.h"
/*************************************************************************************************
芯片上电后所有与PWM相关的IO口均为高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2/P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
另外还有P1.0/P1.4两个口在上电时为强推挽输出,程序初始化时也需将这两个口设置为弱上拉准双向口模式
*************************************************************************************************/

/*********************************************************************
函数原型：void Special_IO_Init(void)
函数功能：IAP15W4K58S4单片机特殊端口初始化（手册内容）
输入参数：无
输出参数：无
*********************************************************************/
void Special_IO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;										//结构定义
	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//推挽输出方式
	GPIO_InitStructure.Pin  = GPIO_Pin_6 | GPIO_Pin_7;			//设置的引脚
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	

	GPIO_InitStructure.Mode = GPIO_OUT_PP;									
	GPIO_InitStructure.Pin  = GPIO_Pin_6 | GPIO_Pin_7| GPIO_Pin_0| GPIO_Pin_4;			
	GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	

	GPIO_InitStructure.Mode = GPIO_OUT_PP;									
	GPIO_InitStructure.Pin  = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_7;			
	GPIO_Inilize(GPIO_P2, &GPIO_InitStructure);	
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;									
	GPIO_InitStructure.Pin  = GPIO_Pin_7;			
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;									
	GPIO_InitStructure.Pin  = GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;			
	GPIO_Inilize(GPIO_P4, &GPIO_InitStructure);	
	P0M0 = P0M1 = 0x00;
	P1M0 = P1M1 = 0x00;
	P2M0 = P2M1 = 0x00;
	P3M0 = P3M1 = 0x00;
	P4M0 = P4M1 = 0x00;
	P5M0 = P5M1 = 0x00;
	P6M0 = P6M1 = 0x00;
	P7M0 = P7M1 = 0x00;
	
}
/*********************************************************************
函数原型：unsigned char	GPIO_Inilize(unsigned char GPIO, GPIO_InitTypeDef *GPIOx)
函数功能：GPIO：要初始化的GPIO端口，GPIOx：引用的结构体
输入参数：无
输出参数：无
*********************************************************************/
unsigned char	GPIO_Inilize(unsigned char GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P7)						return 1;	//空操作
	if(GPIOx->Mode > GPIO_OUT_PP)	return 2;	//错误
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P6)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P6M1 &= ~GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P6M1 |=  GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P6M1 |=  GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P6M1 &= ~GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //推挽输出
	}
		if(GPIO == GPIO_P7)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P7M1 &= ~GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		  P7M1 |=  GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P7M1 |=  GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P7M1 &= ~GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //推挽输出
	}
	return 0;	//成功
}
