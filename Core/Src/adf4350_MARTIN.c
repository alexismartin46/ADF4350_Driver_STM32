/***************************************************************************//**
 *   @file   adf4350_MARTIN.c
 *   @brief  Implementation of ADF4350 Driver.
 *   @author A. MARTIN
********************************************************************************/


#include "adf4350_MARTIN.h"

// Hardware Structure init
uint8_t Hardware_Setup(STM32_Hardware_Struct *Hardware_struct, GPIO_TypeDef *GPIOx,
		uint16_t GPIO_Pin, SPI_HandleTypeDef *hspi)
{
	Hardware_struct -> GPIO_Pin = GPIO_Pin;
	Hardware_struct -> GPIOx = GPIOx;
	Hardware_struct -> hspi = hspi;
	return 1;
}

/**
  * @brief  Transmit 32bits in blocking mode on SPI bus with LE signal
  * @param  Hardware_struct Hardware structure with GPIO and SPI information
  * @param  pData pointer to data buffer (u8 or u16 data elements)
  * @retval HAL status
  */
HAL_StatusTypeDef SPI_Transmit_32(STM32_Hardware_Struct *Hardware_struct, uint32_t *pData)
{
	uint16_t data_16[2];
	data_16[0] = (uint16_t)(*pData >> 16);  // MSB 16-bit
	data_16[1] = (uint16_t)(*pData & 0xFFFF); // LSB 16-bit
	HAL_GPIO_WritePin(Hardware_struct->GPIOx, Hardware_struct->GPIO_Pin, GPIO_PIN_RESET);

	if (HAL_SPI_Transmit(Hardware_struct->hspi, data_16, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		return HAL_ERROR;
	}
	if (HAL_SPI_Transmit(Hardware_struct->hspi, data_16+1, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		return HAL_ERROR;
	}

	HAL_GPIO_WritePin(Hardware_struct->GPIOx, Hardware_struct->GPIO_Pin, GPIO_PIN_SET);

	return HAL_OK;
}

/**
  * @brief  Init PLL with Default values
  * @param  Hardware_struct Hardware structure with GPIO and SPI information
  * @retval HAL status
  */
HAL_StatusTypeDef Init_PLL(STM32_Hardware_Struct *Hardware_struct)
{
	uint32_t data;
	data = REGISTER5_DEFAULT + ADF4350_REG5;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}

	data = REGISTER4_DEFAULT + ADF4350_REG4;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}

	data = REGISTER3_DEFAULT + ADF4350_REG3;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}

	data = REGISTER2_DEFAULT + ADF4350_REG2;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}

	data = REGISTER1_DEFAULT + ADF4350_REG1;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}

	data = REGISTER0_DEFAULT + ADF4350_REG0;
	if(SPI_Transmit_32(Hardware_struct, &data)!= HAL_OK)
	{
		return HAL_ERROR;
	}
	return HAL_OK;
}
