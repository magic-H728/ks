#include	"GPIO.h"
/*************************************************************************************************
оƬ�ϵ��������PWM��ص�IO�ھ�Ϊ����̬,�轫��Щ������Ϊ׼˫��ڻ�ǿ����ģʽ��������ʹ��
���IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2/P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
���⻹��P1.0/P1.4���������ϵ�ʱΪǿ�������,�����ʼ��ʱҲ�轫������������Ϊ������׼˫���ģʽ
*************************************************************************************************/

/*********************************************************************
����ԭ�ͣ�void Special_IO_Init(void)
�������ܣ�IAP15W4K58S4��Ƭ������˿ڳ�ʼ�����ֲ����ݣ�
�����������
�����������
*********************************************************************/
void Special_IO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;										//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//���������ʽ
	GPIO_InitStructure.Pin  = GPIO_Pin_6 | GPIO_Pin_7;			//���õ�����
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
����ԭ�ͣ�unsigned char	GPIO_Inilize(unsigned char GPIO, GPIO_InitTypeDef *GPIOx)
�������ܣ�GPIO��Ҫ��ʼ����GPIO�˿ڣ�GPIOx�����õĽṹ��
�����������
�����������
*********************************************************************/
unsigned char	GPIO_Inilize(unsigned char GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P7)						return 1;	//�ղ���
	if(GPIOx->Mode > GPIO_OUT_PP)	return 2;	//����
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P6)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P6M1 &= ~GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P6M1 |=  GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P6M1 |=  GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P6M1 &= ~GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //�������
	}
		if(GPIO == GPIO_P7)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P7M1 &= ~GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		  P7M1 |=  GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P7M1 |=  GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P7M1 &= ~GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //�������
	}
	return 0;	//�ɹ�
}
