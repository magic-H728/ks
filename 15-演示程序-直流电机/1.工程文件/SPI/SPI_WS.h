#ifndef	__SPI_WS_H
#define	__SPI_WS_H

#include	"config.h"
#include "GPIO.h"

/************************************************************
宏定义区：
************************************************************/
#define SPI_CS    P14
#define SPI_SCK   P15
#define SPI_MOSI  P16
#define SPI_MISO  P17

/************************************************************
变量声明区：
************************************************************/

/************************************************************
函数声明区：
************************************************************/
void	SPI_GPIO_config(void);
static void SPI_Delay(u16 t);
static u8 SPI_SendReadData(u8 dat);
void SPIFlashEnablewrite();
void SPIFlashDisablewrite();
void SPIFlashWaitForEnd(void);
void SPIFlashEraseSector(u32 addr);
void SPIFlashReadData(u32 addr, u8 *buffer, u16 len);
void SPIFlashWriteData(u32 addr, u8 *buffer, u16 len);


#endif
