#include "stdio.h"
#include "Max7219.h"
#include "main.h"

extern SPI_HandleTypeDef hspi2;
#define MAX7219_REG_NUM 13
uint8_t Max7219_RegConfigStatus;
uint8_t reg_addr[MAX7219_REG_NUM] =
{
		/* Digit 0 Register Address*/
		REG_ADR_DIGIT_0,
		/* Digit 1 Register Address*/
		REG_ADR_DIGIT_1,
		/* Digit 2 Register Address*/
		REG_ADR_DIGIT_2,
		/* Digit 3 Register Address*/
		REG_ADR_DIGIT_3,
		/* Digit 4 Register Address*/
		REG_ADR_DIGIT_4,
		/* Digit 5 Register Address*/
		REG_ADR_DIGIT_5,
		/* Digit 6 Register Address*/
		REG_ADR_DIGIT_6,
		/* Digit 7 Register Address*/
		REG_ADR_DIGIT_7,
		/* Decode Register Address*/
		REG_ADR_DECODE_MODE,
		/* Intensity Register Address */
		REG_ADR_INTENSITY,
		/* Scan Limit Register Address */
		REG_ADR_SCAN_LIMIT,
		/* Shutdown Register Address */
		REG_ADR_SHUTDOWN,
		/* Test Mode Register Address */
		REG_ADR_DISPLAY_TEST
};
#define MAX7219_REG_ARR(i)   reg_addr[i]

void Max7219_SendData(uint8_t RegAddr, uint8_t Data)
{
	  uint16_t temp_data = (RegAddr) << 8 | Data;
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
	  HAL_SPI_Transmit(&hspi2, (uint8_t *)&temp_data, 1, HAL_MAX_DELAY);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}
void Max7219_Init()
{	Max7219_OpStatus status;
	Max7219_DecodeStruct tempDecodeStruct;
	status = Max7219_SetDisplayTest(MAX7219_DISPLAYMODE_NORMAL);
	if(status == Max7219_SetReg_OK)
	{
		status = Max7219_SetOperation(MAX7219_SHUTDOWN);
		if (status == Max7219_SetReg_OK)
		{
			Max7219_SetIntensity(0x0F);
			status = Max7219_SetOperation(MAX7219_NORMALOPERATION);
			if (status == Max7219_SetReg_OK)
			{
				status = Max7219_SetScanLimit(8);
				if (status == Max7219_SetReg_OK)
				{
					tempDecodeStruct = Max7219_SetDecodeMode(MAX7219_DECODE_ALL_DIGITS);
				}
				else
				{
					Max7219_RegConfigStatus = Max7219_WrongConfig;
				}
				if (tempDecodeStruct.status == Max7219_SetReg_OK)
				{
					Max7219_RegConfigStatus = Max7219_SetReg_OK;
				}
				else
				{
					Max7219_RegConfigStatus = Max7219_WrongConfig;
				}
			}
			else
			{
				Max7219_RegConfigStatus = Max7219_WrongConfig;
			}
		}
		else
		{
			Max7219_RegConfigStatus = Max7219_WrongConfig;
		}
	}
	else
	{
		Max7219_RegConfigStatus = Max7219_WrongConfig;
	}
	if (Max7219_RegConfigStatus == Max7219_SetReg_OK)
	{
		Max7219_SetInitialData(tempDecodeStruct.selectedDecodeMode);
	}
}

Max7219_DecodeStruct Max7219_SetDecodeMode(uint8_t Mode)
{
	Max7219_DecodeStruct tempDecodeStruct;
	if ((Mode == MAX7219_NO_DECODE_ALL_DIGITS) ||
		(Mode == MAX7219_DECODE_ALL_DIGITS)    ||
		(Mode == MAX7219_DECODE_ONLY_DIGIT_0)  ||
		(Mode == MAX7219_DECODE_DIGIT_3_TO_0))
	{
		Max7219_SendData(REG_ADR_DECODE_MODE, Mode);
		tempDecodeStruct.status = Max7219_SetReg_OK;
		tempDecodeStruct.selectedDecodeMode = Mode;
	}
	else
	{
		tempDecodeStruct.status = Max7219_WrongConfig;
	}
	return tempDecodeStruct;
}

void Max7219_SetIntensity(uint8_t Intensity)
{
	Max7219_SendData(REG_ADR_INTENSITY, Intensity);
}

Max7219_OpStatus Max7219_SetDisplayTest(uint8_t State)
{
	Max7219_OpStatus status;
	if ((State == MAX7219_DISPLAYMODE_NORMAL)||(State == MAX7219_DISPLAYMODE_TEST))
	{
		Max7219_SendData(REG_ADR_DISPLAY_TEST, State);
		status = Max7219_SetReg_OK;
	}
	else
	{
		status = Max7219_WrongConfig;
	}
	return status;
}

Max7219_OpStatus Max7219_SetScanLimit(uint8_t NumOfDigit)
{
	Max7219_OpStatus status;
	if (NumOfDigit < 9)
	{
		Max7219_SendData(REG_ADR_SCAN_LIMIT, NumOfDigit - 1u);
		status = Max7219_SetReg_OK;
	}
	else
	{
		status = Max7219_WrongConfig;
	}
	return status;
}

Max7219_OpStatus Max7219_SetOperation(uint8_t State)
{
	Max7219_OpStatus status;
	if ((State == MAX7219_SHUTDOWN) || (State == MAX7219_NORMALOPERATION))
	{
		Max7219_SendData(REG_ADR_SHUTDOWN, State);
		status = Max7219_SetReg_OK;
	}
	else
	{
		status = Max7219_WrongConfig;
	}
	return status;
}

void Max7219_SetInitialData(uint8_t DecodeMode){
	 uint8_t Data = 0;
	 if(DecodeMode == MAX7219_DECODE_ALL_DIGITS)
	 {
		Data = 0x0A;
		for(uint8_t i = 0; i < 8 ;i++)
		{
			Max7219_SendData(MAX7219_REG_ARR(i),Data);
		}
	 }
}
