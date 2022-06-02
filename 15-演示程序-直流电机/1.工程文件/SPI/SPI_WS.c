#include "SPI_WS.h"
/*********************************************************************
�ļ����ƣ�LED88.h
��    ����V1.0
˵    ����88LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	SPI_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	//��ʼ��
}



/*********************************************************************
����ԭ�ͣ�static void SPI_Delay(u16 t)
�������ܣ�SPI��ʱ
�����������
�����������
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
����ԭ�ͣ�static u8 SPI_SendReadData(u8 dat)
�������ܣ�SPI��д����
�����������
�����������
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
//ʹ��Flashд��
void SPIFlashEnablewrite()
{
	SPI_CS = 0;
	SPI_SendReadData(0x06);
	SPI_CS = 1;
}

//��ֹFlashд��
void SPIFlashDisablewrite()
{
	SPI_CS = 0;
	SPI_SendReadData(0x04);
	SPI_CS = 1;
}

//�ȴ�Flashд��������
void SPIFlashWaitForEnd(void)
{
	SPI_CS = 0;
    SPI_SendReadData(0x05);
    while((SPI_SendReadData(0x00)&0x01)==1);
	SPI_CS = 1;
}

//����һ������  4096��С
//addr����Ϊ4096����������������4096ȡ��
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

//��Flash��ȡ����
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

//��Flashд������
//len���256��һ������������д256���ֽ�
//ע��д������ǰ����Ҫд������Ӧ�������������޷�д��
//��ַ�����256����������������ܵ���len������256��С���0��ʼ
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

