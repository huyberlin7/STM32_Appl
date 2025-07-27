#ifndef __MAX7219_H
#define __MAX7219_H

#include "stdint.h"
#include "stdbool.h"

/*
 * Max7219_RegisterAddr: Typedef for register address of Max 7219 - 7 segments LED
 * */
typedef enum {
	REG_ADR_NO_OP = 0x00,
	REG_ADR_DIGIT_0 = 0x01,
	REG_ADR_DIGIT_1 = 0x02,
	REG_ADR_DIGIT_2 = 0x03,
	REG_ADR_DIGIT_3 = 0x04,
	REG_ADR_DIGIT_4 = 0x05,
	REG_ADR_DIGIT_5 = 0x06,
	REG_ADR_DIGIT_6 = 0x07,
	REG_ADR_DIGIT_7 = 0x08,
	REG_ADR_DECODE_MODE = 0x09,
	REG_ADR_INTENSITY = 0x0A,
	REG_ADR_SCAN_LIMIT= 0x0B,
	REG_ADR_SHUTDOWN = 0x0C,
	REG_ADR_DISPLAY_TEST = 0x0F
}Max7219_RegisterAddr;

typedef enum {
	Max7219_SetReg_OK = 0x00,
	Max7219_WrongConfig = 0x01
}Max7219_OpStatus;

typedef struct {
	Max7219_OpStatus status;
	uint8_t selectedDecodeMode;
}Max7219_DecodeStruct;
/*
 * Operation mode for MAX7219
 * */
#define MAX7219_SHUTDOWN 0x00
#define MAX7219_NORMALOPERATION 0x01

/*
 * Display test mode for MAX7219
 * */
#define MAX7219_DISPLAYMODE_NORMAL 0x00
#define MAX7219_DISPLAYMODE_TEST 0x01

/*
 * Decode mode for MAX7219
 * */
#define MAX7219_NO_DECODE_ALL_DIGITS    0x00
#define MAX7219_DECODE_ONLY_DIGIT_0     0x01
#define MAX7219_DECODE_DIGIT_3_TO_0     0x0F
#define MAX7219_DECODE_ALL_DIGITS 		0xFF

void Max7219_SendData(uint8_t RegAddr, uint8_t Data);
void Max7219_SetInitialData(uint8_t DecodeMode);
Max7219_OpStatus Max7219_SetOperation(uint8_t State);
Max7219_DecodeStruct Max7219_SetDecodeMode(uint8_t Mode);
void Max7219_SetIntensity(uint8_t Intensity);
Max7219_OpStatus Max7219_SetDisplayTest(uint8_t State);
Max7219_OpStatus Max7219_SetScanLimit(uint8_t NumOfDigit);
void Max7219_Init();



#endif
