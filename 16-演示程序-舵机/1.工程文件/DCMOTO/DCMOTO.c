#include "DCMOTO.h"
///*********************************************************************
//�ļ����ƣ�LED88.h
//��    ����V1.0
//˵    ����88LED��غ��������ļ�
//�޸ļ�¼��2021-11-11
//*********************************************************************/

//#define T1MS (65536-MAIN_Fosc/1000)      //1Tģʽ
///*********************************************************************
//����ԭ�ͣ�void LED_GPIO_config(void)
//�������ܣ�LED�˿ڳ�ʼ������
//�����������
//�����������
//*********************************************************************/
//void DCMOTO_GPIO_config(void)
//{
//	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	
//	GPIO_InitStructure.Pin  = GPIO_Pin_6;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
//	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//��ʼ��
//	
//	GPIO_InitStructure.Pin  = GPIO_Pin_0 |GPIO_Pin_1;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
//	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��	
//	
//}
//void Time0_16_Config_Init(void)
//{
//    AUXR |= 0x80;                   //��ʱ��0Ϊ1Tģʽ
////  AUXR &= 0x7f;                   //��ʱ��0Ϊ12Tģʽ

//    TMOD = 0x00;                    //���ö�ʱ��Ϊģʽ0(16λ�Զ���װ��)
//    TL0 = T1MS;                     //��ʼ����ʱֵ
//    TH0 = T1MS >> 8;
//    TR0 = 1;                        //��ʱ��0��ʼ��ʱ
//    ET0 = 1;                        //ʹ�ܶ�ʱ��0�ж�
//    EA = 1;
//}
//void DCMoto_Sta(u8 sta,u8 dir)
//{

//	switch(sta)
//	{
//		case 0: TR0 = 0;	IN1 = 0;IN2 =0; break;
//		case 1:TR0 = 1;
//		switch(dir)
//		{
//			case 1:
//				IN1 = 1;
//				IN2 =0;
//				break;	
//		
//			case 2:
//				IN1 = 0;
//				IN2 =1;
//				break;	
//		}break;	
//}
//}





//void tm0_isr() interrupt 1 using 1
//{
//    P06= ! P06;                    //�����Կ�ȡ��
//}


