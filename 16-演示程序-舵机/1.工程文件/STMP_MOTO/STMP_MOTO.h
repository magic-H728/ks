#ifndef	__STMP_MOTO_H
#define	__STMP_MOTO_H

#include	"config.h"
#include "GPIO.h"

/************************************************************
宏定义区：
************************************************************/
#define INA  	P61
#define INB 	P62
#define INC		P63
#define IND 	P64


/************************************************************
变量声明区：
************************************************************/

/************************************************************
函数声明区：
************************************************************/
void STEP_MOTO_RUN(u16 speed);
void	STMP_MOTO_GPIO_config(void);

#endif
