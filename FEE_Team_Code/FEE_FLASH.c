#include "FEE_FLASH.h"
#include "stm32f1xx.h"                  // Device header


/***********************************WRITE FLASH********************************************/
void Flash_Erase(uint32_t address)
{
	HAL_FLASH_Unlock();
	FLASH_EraseInitTypeDef EraseIntStruct;
	EraseIntStruct.Banks = 1;
	EraseIntStruct.NbPages = 1;
	EraseIntStruct.PageAddress = address;
	EraseIntStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	uint32_t pageerr;
	HAL_FLASHEx_Erase(&EraseIntStruct, &pageerr);
	HAL_FLASH_Lock();
}

void Flash_Write_Int(uint32_t address, int value)
{
	HAL_FLASH_Unlock();
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, value);
	HAL_FLASH_Lock();
}
void Flash_Write_Float(uint32_t address, float f)
{
	HAL_FLASH_Unlock();
	uint8_t data[4];
	*(float*)data = f;
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *(uint32_t*)data);
	HAL_FLASH_Lock();
}

void Flash_Write_Array(uint32_t address, uint16_t *arr, uint16_t len)
{
	HAL_FLASH_Unlock();
	uint16_t *pt = (uint16_t*)arr;
	for(uint16_t i=0; i<(len+1)/2; i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + 2*i, *pt);
		pt++;
	}
	HAL_FLASH_Lock();
}

void Flash_Write_Struct(uint32_t address, wifi_info_t data)
{
	Flash_Write_Array(address, (uint16_t*)&data, sizeof(data));
}



/***************************************READ FLASH******************************************/
int Flash_Read_Int(uint32_t address)
{
	return *(__IO uint16_t *)(address);
}
	
float Flash_Read_Float(uint32_t address)
{
	uint32_t data = *(__IO uint32_t*)(address);
	return *(float*)(&data);
}

void Flash_Read_Array(uint32_t address, uint16_t *arr, uint16_t len)
{
	for(uint16_t i=0; i<(len+1)/2; i++)
	{
		*arr = *(__IO uint16_t*)(address + 2*i);
		*arr++;
	}
}
void Flash_Read_Struct(uint32_t address, wifi_info_t data)
{
		Flash_Read_Array(address, (uint16_t*)&data, sizeof(data));
}