#include "spi_if.h"

HAL_StatusTypeDef ReadSpiData(SPI_HandleTypeDef hspi, uint16_t pin, uint8_t reg, uint8_t* data, uint8_t length)
{
	HAL_StatusTypeDef ret = HAL_OK;

	uint8_t add = (reg << 2) | 1;

	HAL_GPIO_WritePin(GPIOC, pin, GPIO_PIN_RESET);

    ret = HAL_SPI_Transmit(&hspi, &add, 1, 10);
    if (ret == HAL_OK) {
    	ret = HAL_SPI_Receive(&hspi, data, length, 10);
    }
    HAL_GPIO_WritePin(GPIOC, pin, GPIO_PIN_SET);

    return ret;
}

HAL_StatusTypeDef WriteSpiData(SPI_HandleTypeDef hspi, uint16_t pin, uint8_t reg, uint8_t* data)
{
	HAL_StatusTypeDef ret = HAL_OK;
	uint8_t add = (reg << 2);

    HAL_GPIO_WritePin(GPIOC, pin, GPIO_PIN_RESET);

    ret = HAL_SPI_Transmit(&hspi, &add, 1, 10);
    if (ret == HAL_OK) {
        ret = HAL_SPI_Transmit(&hspi, data, 2, 10);
    }
    HAL_GPIO_WritePin(GPIOC, pin, GPIO_PIN_SET);

    return ret;
}
