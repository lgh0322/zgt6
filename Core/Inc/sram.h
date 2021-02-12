#ifndef _sram_H
#define _sram_H

#include "main.h"
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;
#define Bank1_SRAM3_ADDR    ((u32)(0x68000000))	

void FSMC_SRAM_WriteBuffer(u8* pBuffer,u32 WriteAddr,u32 NumHalfwordToWrite);
void FSMC_SRAM_ReadBuffer(u8* pBuffer,u32 ReadAddr,u32 NumHalfwordToRead);


#endif

