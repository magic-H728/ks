#ifndef	__TIMER_H
#define	__TIMER_H

#include "config.h"

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4

#define	TIM_16BitAutoReload					0
#define	TIM_16Bit										1
#define	TIM_8BitAutoReload					2
#define	TIM_16BitAutoReloadNoMask		3

#define	TIM_CLOCK_1T				0
#define	TIM_CLOCK_12T				1
#define	TIM_CLOCK_Ext				2

typedef struct
{
	unsigned char	TIM_Mode;		//����ģʽ,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	unsigned char	TIM_Polity;		//���ȼ�����	PolityHigh,PolityLow
	unsigned char	TIM_Interrupt;	//�ж�����		ENABLE,DISABLE
	unsigned char	TIM_ClkSource;	//ʱ��Դ		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	unsigned char	TIM_ClkOut;		//�ɱ��ʱ�����,	ENABLE,DISABLE
	unsigned int	TIM_Value;		//װ�س�ֵ
	unsigned char	TIM_Run;		//�Ƿ�����		ENABLE,DISABLE
}TIM_InitTypeDef;

unsigned char	Timer_Inilize(unsigned char TIM, TIM_InitTypeDef *TIMx);

#endif
