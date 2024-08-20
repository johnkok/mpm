#ifndef INC_INA_H_
#define INC_INA_H_

#include "main.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "spi_if.h"

/* INA229 Registers */
#define CONFIG_REG			0
#define CONFIG_SIZE 		2
#define ADC_CONFIG_REG      1
#define ADC_CONFIG_SIZE 	2
#define SHUNT_CAL_REG      	2
#define SHUNT_CAL_SIZE 		2
#define SHUNT_TEMPCO_REG    3
#define SHUNT_TEMPCO_SIZE 	2
#define VSHUNT_REG  		4
#define VSHUNT_SIZE 		3
#define VBUS_REG      		5
#define VBUS_SIZE 			3
#define DIETEMP_REG      	6
#define DIETEMP_SIZE 		2
#define CURRENT_REG      	7
#define CURRENT_SIZE 		3
#define POWER_REG      		8
#define POWER_SIZE 			3
#define ENERGY_REG      	9
#define ENERGY_SIZE 		5
#define CHARGE_REG      	10
#define CHARGE_SIZE 		5
#define DIAG_ALRT_REG 		11
#define DIAG_ALRT_SIZE 		2
#define SOVL_REG			12
#define SOVL_SIZE			2
#define SUVL_REG 			13
#define SUVL_SIZE 			2
#define BOVL_REG			14
#define BOVL_SIZE			2
#define BUVL_SIZE 			15
#define BUVL_REG 			2
#define TEMP_LIMIT_REG		16
#define TEMP_LIMIT_SIZE 	2
#define PWR_LIMIT_REG		17
#define PWR_LIMIT_SIZE 		2
#define MANUFACTURER_ID_REG	 0x3E
#define MANUFACTURER_ID_SIZE 2
#define DEVICE_ID_REG		0x3F
#define DEVICE_ID_SIZE 		2

typedef struct ch_meas_ {
	uint8_t vbus[3];
	uint8_t vshunt[3];
}ch_meas_t;

HAL_StatusTypeDef InitIna229(SPI_HandleTypeDef hspi, uint16_t cs);
HAL_StatusTypeDef InitAllIna(SPI_HandleTypeDef hspi1, SPI_HandleTypeDef hspi2);
HAL_StatusTypeDef ReadVbus(SPI_HandleTypeDef hspi, uint16_t cs, uint8_t * data);
HAL_StatusTypeDef ReadVshunt(SPI_HandleTypeDef hspi, uint16_t cs, uint8_t * data);
HAL_StatusTypeDef ReadAll_A(SPI_HandleTypeDef hspi1);
HAL_StatusTypeDef ReadAll_B(SPI_HandleTypeDef hspi2);

#endif /* INC_SPI_IF_H_ */
