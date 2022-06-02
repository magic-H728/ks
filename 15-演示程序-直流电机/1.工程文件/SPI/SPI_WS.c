#include "SPI_WS.h"
/*********************************************************************
文件名称：LED88.h
版    本：V1.0
说    明：88LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	SPI_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	//初始化
}



/*********************************************************************
函数原型：static void SPI_Delay(u16 t)
函数功能：SPI延时
输入参数：无
输出参数：无
*********************************************************************/
static void SPI_Delay(u16 t)
{
    u8  i;
    while (t--)
	{
		for(i=0;i<0x05;i++);
	}
}
/*********************************************************************
函数原型：static u8 SPI_SendReadData(u8 dat)
函数功能：SPI读写数据
输入参数：无
输出参数：无
*********************************************************************/
static u8 SPI_SendReadData(u8 dat)
{
	u8 i;
	u8 ret = 0;
	SPI_SCK = 0;
	for(i=0;i<8;i++)
	{
		SPI_MOSI = (dat&0x01)?1:0;
		SPI_SCK = 1;
		SPI_Delay(1);
		SPI_SCK = 0;
		dat>>=1;
		SPI_Delay(1);
		ret |= (SPI_MISO?1:0) << i;
	}
	SPI_Delay(1);
	return ret;
}
//使能Flash写入
void SPIFlashEnablewrite()
{
	SPI_CS = 0;
	SPI_SendReadData(0x06);
	SPI_CS = 1;
}

//禁止Flash写入
void SPIFlashDisablewrite()
{
	SPI_CS = 0;
	SPI_SendReadData(0x04);
	SPI_CS = 1;
}

//等待Flash写入操作完成
void SPIFlashWaitForEnd(void)
{
	SPI_CS = 0;
    SPI_SendReadData(0x05);
    while((SPI_SendReadData(0x00)&0x01)==1);
	SPI_CS = 1;
}

//擦除一个扇区  4096大小
//addr必须为4096的整数倍，否则按照4096取整
void SPIFlashEraseSector(u32 addr)
{
	SPIFlashEnablewrite();
	SPI_CS = 0;
	SPI_SendReadData(0x20);
	SPI_SendReadData(addr >> 16);
	SPI_SendReadData(addr >> 8);
	SPI_SendReadData(addr >> 0);
	SPI_CS = 1;
	SPI_Delay(100);
	SPIFlashWaitForEnd();
	SPIFlashDisablewrite();
}

//从Flash读取数据
void SPIFlashReadData(u32 addr, u8 *buffer, u16 len)
{
	SPI_CS = 0;
	SPI_SendReadData(0x03);
	SPI_SendReadData(addr >> 16);
	SPI_SendReadData(addr >> 8);
	SPI_SendReadData(addr >> 0);
	while(len--)
	{
		*buffer++ = SPI_SendReadData(0x00);
	}
	SPI_CS = 1;
}

//向Flash写入数据
//len最大256，一次最多可以连续写256个字节
//注意写入数据前，需要写擦除对应的扇区，否则无法写入
//地址最好是256的整数倍，否则可能导致len超过该256大小后从0开始
void SPIFlashWriteData(u32 addr, u8 *buffer, u16 len)
{
	SPIFlashEnablewrite();
	SPI_CS = 0;
	SPI_SendReadData(0x02);
	SPI_SendReadData(addr >> 16);
	SPI_SendReadData(addr >> 8);
	SPI_SendReadData(addr >> 0);
	if(len>256)
	{
		len = 256;
	}
	while(len--)
	{
		SPI_SendReadData(*buffer++);
		SPI_Delay(5);
	}
	SPI_CS = 1;
	SPI_Delay(100);
	SPIFlashDisablewrite();
}

