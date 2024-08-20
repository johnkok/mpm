#ifndef INC_SPI_IF_H_
#define INC_SPI_IF_H_

#include "main.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "ina.h"

/* Functions */
HAL_StatusTypeDef ReadSpiData(SPI_HandleTypeDef hspi, uint16_t pin, uint8_t reg, uint8_t* data, uint8_t length);
HAL_StatusTypeDef WriteSpiData(SPI_HandleTypeDef hspi, uint16_t pin, uint8_t reg, uint8_t* data);

#endif /* INC_SPI_IF_H_ */
