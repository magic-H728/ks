#include "config.h"
#include "GPIO.h"
#include "LED.h"
#include "delay.h"
#include "PULSE_IN_BIT_OUT.h"
#include "KEY.h"
#include "MKEY.h"
#include "BMKEY.h"
#include "YBUZZER.h"
#include "WBUZZER.h"
#include "ONELED.h"
#include "FOURLED.h"
#include "LED88.h"
#include "LED1616.h"
#include "LCD1602.h"
#include "stdio.h"
#include "LCD12864.h"
#include "SPI_WS.h"
#include "LCDTFT.h"
#include "STMP_MOTO.h"
#include "DCMOTO.h"
void main(void)
{

    Special_IO_Init(); //特殊端口初始化函数

    DCMOTO_GPIO_config();
    Time0_16_Config_Init();
    EA = 1;
    while (1) //循环
    {
        DCMoto_Sta(1, 1);
    }
}
