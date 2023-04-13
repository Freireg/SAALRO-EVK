/*
 * flash_mem.c
 *
 *  Created on: Apr 6, 2023
 *      Author: freire
 */

#include "flash_mem.h"

uint8_t txData[260];
uint8_t rxData[260];


uint8_t dev_ext_flsh_enable_write(uint8_t ID, bool enable)
{
	HAL_StatusTypeDef Hal_Result;

	if(enable)
		txData[0] = FLASH_INSTRUCTION_WRITE_ENABLE;
	else
		txData[0] = FLASH_INSTRUCTION_WRITE_DISABLE;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_RESET);
	Hal_Result = HAL_SPI_Transmit(&hspi5, txData, 1, 100);
	if(Hal_Result != HAL_OK)
		return 1;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_SET);

	return 0;

}

uint8_t dev_ext_flsh_read_status(uint8_t ID, uint8_t *Status)
{
	HAL_StatusTypeDef Hal_Result;
	txData[0] = FLASH_INSTRUCTION_READ_STATUS_REGISTER;

	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_RESET);
	Hal_Result = HAL_SPI_TransmitReceive(&hspi5, txData, rxData, 2, 100);
	if(Hal_Result != HAL_OK)
		return 1;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_SET);
	if(Hal_Result == HAL_OK)
	{
		*Status = rxData[1];
		return 0;
	}

	return 0;
}

uint8_t dev_ext_flash_read(uint8_t ID, uint32_t Address, uint8_t *Data, uint32_t Size)
{
	HAL_StatusTypeDef Hal_Result;

	txData[0] = FLASH_INSTRUCTION_NORMAL_READ;
	txData[1] = Address >> 16 & 0xff;
	txData[2] = Address >> 8 & 0xff;
	txData[3] = Address & 0xff;

	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_RESET);
	Hal_Result = HAL_SPI_TransmitReceive(&hspi5, txData, rxData, Size + 4, 100);
	if(Hal_Result != HAL_OK)
		return 1;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_SET);
	if(Hal_Result == HAL_OK)
		memcpy(Data, rxData + 4, Size);
	return 0;

}

uint8_t dev_ext_flash_write(uint8_t ID, uint32_t Address, uint8_t *Data, uint32_t Size)
{
	HAL_StatusTypeDef Hal_Result;
	uint8_t Memory_Status;

	if(dev_ext_flsh_enable_write(ID, true) != 0)
		return 1;

	txData[0] = FLASH_INSTRUCTION_PAGE_PROGRAM;
	txData[1] = Address >> 16 & 0xff;
	txData[2] = Address >> 8 & 0xff;
	txData[3] = Address & 0xff;
	memcpy(txData + 4, Data, Size);

	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_RESET);
	Hal_Result = HAL_SPI_Transmit(&hspi5, txData, Size + 4, 100);
	if(Hal_Result != HAL_OK)
		return 1;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_SET);

	while(Memory_Status & FLASH_STATUS_BIT_WIP)
	{
		dev_ext_flsh_read_status(ID, &Memory_Status);
	}

	return 0;

}
uint8_t dev_ext_flash_erase_sector(uint8_t ID, uint32_t SectorAddress)
{
	HAL_StatusTypeDef Hal_Result;
	uint8_t Memory_Status;

	if(dev_ext_flsh_enable_write(ID, true) != 0)
		return 1;
	txData[0] = FLASH_INSTRUCTION_SECTOR_ERASE;
	txData[1] = SectorAddress >> 16 & 0xff;
	txData[2] = SectorAddress >> 8 & 0xff;
	txData[3] = SectorAddress & 0xff;

	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_RESET);
	Hal_Result = HAL_SPI_Transmit(&hspi5, txData, 4, 100);
	if(Hal_Result != HAL_OK)
		return 1;
	HAL_GPIO_WritePin(EXT_MEM_CS_GPIO_Port, EXT_MEM_CS_Pin, GPIO_PIN_SET);

	while(Memory_Status & FLASH_STATUS_BIT_WIP)
	{
		dev_ext_flsh_read_status(ID, &Memory_Status);
	}
	return 0;

}



int block_device_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size)
{
	dev_ext_flash_read(0, (block * c->block_size + off), (uint8_t*)buffer, size);
	return 0;
}
int block_device_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size)
{
	dev_ext_flash_write(0, (block * c->block_size + off), (uint8_t*)buffer, size);
	return 0;
}
int block_device_erase(const struct lfs_config *c, lfs_block_t block)
{
	dev_ext_flash_erase_sector(0, (block * c->block_size));
	return 0;
}
int block_device_sync(const struct lfs_config *c)
{
	return 0;
}


