#include "ina.h"

ch_meas_t ch_meas[10];

HAL_StatusTypeDef InitIna229(SPI_HandleTypeDef hspi, uint16_t cs)
{
	HAL_StatusTypeDef ret = HAL_OK;
	uint16_t data;

	// Reset device
	data = 0xC010U;
	ret = WriteSpiData(hspi, cs, CONFIG_REG, (uint8_t*)&data);
	osDelay(100);
    if (ret == HAL_OK) {
    	// 40.96mv full scale
    	data = 0x0010U;
    	ret = WriteSpiData(hspi, cs, CONFIG_REG, (uint8_t*)&data);
    }
    if (ret == HAL_OK) {
    	// continues voltage and shunt - 50uSec Vbus, 540uSec Shunt - 1 Avrg
    	data = 0xB500U;
    	ret = WriteSpiData(hspi, cs, ADC_CONFIG_REG, (uint8_t*)&data);
    }
    if (ret == HAL_OK) {
    	// 1-Ohm shunt, 100nA LSB ADCRANGE=1
    	data = 0xCCCDU;
    	ret = WriteSpiData(hspi, cs, SHUNT_CAL_REG, (uint8_t*)&data);
    }

	return ret;
}

HAL_StatusTypeDef InitAllIna(SPI_HandleTypeDef hspi1, SPI_HandleTypeDef hspi2)
{
	HAL_StatusTypeDef ret = HAL_OK;

	ret = InitIna229(hspi1, nCS_A0_Pin);
	if (ret == HAL_OK) {ret = InitIna229(hspi2, nCS_B0_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi1, nCS_A1_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi2, nCS_B1_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi1, nCS_A2_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi2, nCS_B2_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi1, nCS_A3_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi2, nCS_B3_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi1, nCS_A4_Pin);}
	if (ret == HAL_OK) {ret = InitIna229(hspi2, nCS_B4_Pin);}

	return ret;
}

HAL_StatusTypeDef ReadVbus(SPI_HandleTypeDef hspi, uint16_t cs, uint8_t * data)
{
	HAL_StatusTypeDef ret = HAL_OK;

	ret = ReadSpiData(hspi, cs, VBUS_REG, data, VBUS_SIZE);

    return ret;
}

HAL_StatusTypeDef ReadVshunt(SPI_HandleTypeDef hspi, uint16_t cs, uint8_t * data)
{
	HAL_StatusTypeDef ret = HAL_OK;

	ret = ReadSpiData(hspi, cs, VSHUNT_REG, data, VSHUNT_SIZE);

    return ret;
}

HAL_StatusTypeDef ReadAll_A(SPI_HandleTypeDef hspi1)
{
	HAL_StatusTypeDef ret = HAL_OK;

	if (ret == HAL_OK) {ret = ReadVbus(hspi1, nCS_A0_Pin, ch_meas[0].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi1, nCS_A0_Pin, ch_meas[0].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi1, nCS_A1_Pin, ch_meas[1].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi1, nCS_A1_Pin, ch_meas[1].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi1, nCS_A2_Pin, ch_meas[2].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi1, nCS_A2_Pin, ch_meas[2].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi1, nCS_A3_Pin, ch_meas[3].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi1, nCS_A3_Pin, ch_meas[3].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi1, nCS_A4_Pin, ch_meas[4].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi1, nCS_A4_Pin, ch_meas[4].vshunt);}

	return ret;
}

HAL_StatusTypeDef ReadAll_B(SPI_HandleTypeDef hspi2)
{
	HAL_StatusTypeDef ret = HAL_OK;

	if (ret == HAL_OK) {ret = ReadVbus(hspi2, nCS_B0_Pin, ch_meas[0].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi2, nCS_B0_Pin, ch_meas[0].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi2, nCS_B1_Pin, ch_meas[1].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi2, nCS_B1_Pin, ch_meas[1].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi2, nCS_B2_Pin, ch_meas[2].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi2, nCS_B2_Pin, ch_meas[2].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi2, nCS_B3_Pin, ch_meas[3].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi2, nCS_B3_Pin, ch_meas[3].vshunt);}
	if (ret == HAL_OK) {ret = ReadVbus(hspi2, nCS_B4_Pin, ch_meas[4].vbus);}
	if (ret == HAL_OK) {ret = ReadVshunt(hspi2, nCS_B4_Pin, ch_meas[4].vshunt);}

	return ret;
}
