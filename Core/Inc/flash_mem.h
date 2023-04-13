/*
 * flash_mem.h
 *
 *  Created on: Apr 6, 2023
 *      Author: freire
 */

#ifndef INC_FLASH_MEM_H_
#define INC_FLASH_MEM_H_

#include "main.h"

#define FLASH_INSTRUCTION_NORMAL_READ				      	0x03
#define FLASH_INSTRUCTION_PAGE_PROGRAM				    	0x02
#define FLASH_INSTRUCTION_SECTOR_ERASE				    	0xD7
#define FLASH_INSTRUCTION_32KB_BLOCK_ERASE			  		0x52
#define FLASH_INSTRUCTION_64KB_BLOCK_ERASE			  		0xD8
#define FLASH_INSTRUCTION_CHIP_ERASE				      	0xC7
#define FLASH_INSTRUCTION_WRITE_ENABLE				    	0x06
#define FLASH_INSTRUCTION_WRITE_DISABLE				    	0x04
#define FLASH_INSTRUCTION_WRITE_STATUS_REGISTER				0x01
#define FLASH_INSTRUCTION_READ_STATUS_REGISTER				0x05
#define FLASH_INSTRUCTION_READ_FUNCTION_REGISTER			0x48
#define FLASH_STATUS_BIT_WIP						        0x01



int block_device_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size);
int block_device_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size);
int block_device_erase(const struct lfs_config *c, lfs_block_t block);
int block_device_sync(const struct lfs_config *c);
uint8_t dev_ext_flash_read(uint8_t ID, uint32_t Address, uint8_t *Data, uint32_t Size);
uint8_t dev_ext_flash_write(uint8_t ID, uint32_t Address, uint8_t *Data, uint32_t Size);
uint8_t dev_ext_flash_erase_sector(uint8_t ID, uint32_t SectorAddress);

#endif /* INC_FLASH_MEM_H_ */
