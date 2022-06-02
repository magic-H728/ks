#include "REMOTO.h"
/*********************************************************************
�ļ����ƣ�LED88.h
��    ����V1.0
˵    ����88LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/
#define kServoPWMCountMax   2000


u16 ServoPWMCount = 0;

u16 ServoHighPulse = 50;  //50-250

#define T1MS1 (65536-MAIN_Fosc/100000)      //1Tģʽ
/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void REMOTO_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_6;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//��ʼ��
}

void Time1_16_Config_Init_1(void)
{
	AUXR |= 0x40;

    TMOD = 0x00;
    TL1 = T1MS1;
    TH1 = T1MS1 >> 8;
    TR1 = 1;
    ET1 = 1;
    EA = 1;
}


//50usһ���ж�
void tm1_isr() interrupt 3
{
	
	ServoPWMCount++;

	if(ServoPWMCount>=kServoPWMCountMax)
	{
		ServoPWMCount=0;
	}
	if(ServoPWMCount>=ServoHighPulse)
	{
		P06 = 0;
	}
	else
	{
		P06 = 1;
	}


}


