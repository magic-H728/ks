#include "FOURLED.h"
#include "delay.h"
/*********************************************************************
�ļ����ƣ�LED.h
��    ����V1.0
˵    ����LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/
code u8 FOUR_mum[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	FOURLED_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//��ʼ��
	
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_7;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P2, &GPIO_InitStructure);	//��ʼ��
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_0;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_1;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_2;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��
	DIG_A = 1;
	DIG_B = 1;
	DIG_C = 1;
	DIG_D = 1;
}

void FOUR_SMGShow(u16 num,u8 t)
{
	u8 housand=num/1000;
	u8 Hundred=num%1000/100;
	u8 Ten=num%100/10;
	u8 One=num%10;
	
	DIG_A = 0;	
	P7=FOUR_mum[housand];
	delay_ms(t);

	DIG_A = 1;	


	DIG_B = 0;	
	P7=FOUR_mum[Hundred];	
	delay_ms(t);
	DIG_B = 1;	


	DIG_C = 0;	
	P7=FOUR_mum[Ten];
	delay_ms(t);
	DIG_C = 1;	
	

	DIG_D = 0;	
	P7=FOUR_mum[One];
	delay_ms(t);
	DIG_D = 1;	
	

}

