/*
 * MFRC522_Prv_Reg.h
 *
 *  Created on: Jul 27, 2025
 *      Author: Nguyen Tan Huy
 */

#ifndef MFRC522_PRV_REG_H_
#define MFRC522_PRV_REG_H_

/*
 * @brief
 * Macro to convert address for reading and writing
 * Please check in the specification for the logic
 * */
#define MFRC522_SPI_ADDR_CONVERT_WRITE(regAddr)  (0x7E & (regAddr << 1))

#define MFRC522_SPI_ADDR_CONVERT_READ(regAddr)  ((0x7E & (regAddr << 1)) | 0x80)

/*
 * List of command and status register
 * */
#define MFRC522_COMMAND_REG         0x01
#define MFRC522_COM_I_EN_REG        0x02
#define MFRC522_DIV_I_EN_REG        0x03
#define MFRC522_COM_IRQ_REG         0x04
#define MFRC522_DIV_IRQ_REG         0x05
#define MFRC522_ERROR_REG           0x06
#define MFRC522_STATUS_ONE_REG      0x07
#define MFRC522_STATUS_TWO_REG      0x08
#define MFRC522_FIFO_DATA_REG       0x09
#define MFRC522_FIFO_LEVEL_REG      0x0A
#define MFRC522_WATER_LEVEL_REG     0x0B
#define MFRC522_CONTROL_REG         0x0C
#define MFRC522_BIT_FRAMMING_REG    0x0D
#define MFRC522_COLL_REG            0x0E

/**
 * @brief 
 * List of connection command register
 */
#define MFRC522_MODE_REG            0x11
#define MFRC522_TX_MODE_REG         0x12
#define MFRC522_RX_MODE_REG         0x13
#define MFRC522_TX_CONTROL_REG      0x14
#define MFRC522_TX_ASK_REG          0x15
#define MFRC522_TX_SEL_REG          0x16
#define MFRC522_RX_SEL_REG          0x17
#define MFRC522_RX_THRESHOLD_REG    0x18
#define MFRC522_DEMOD_REG           0x19
#define MFRC522_MF_TX_REG           0x1C
#define MFRC522_MF_RX_REG           0x1D
#define MFRC522_SERIAL_SPEED_REG    0x1F 

/**
 * @brief 
 * List of configuration register
 */
#define MFRC522_CRC_RESULT_REG_MSB          0x21
#define MFRC522_CRC_RESULT_REG_LSB          0x22
#define MFRC522_MOD_WIDTH_REG               0x24
#define MFRC522_RFC_CFG_REG                 0x26
#define MFRC522_GSN_REG                     0x27
#define MFRC522_CWGS_P_REG                  0x28
#define MFRC522_MOD_GS_P_REG                0x29
#define MFRC522_T_MODE_REG                  0x2A
#define MFRC522_T_PRESCALER_REG             0x2B
#define MFRC522_T_RELOAD_REG_MSB            0x2C
#define MFRC522_T_RELOAD_REG_LSB            0x2D
#define MFRC522_T_COUNTER_VAL_REG_MSB       0x2E
#define MFRC522_T_COUNTER_VAL_REG_LSB       0x2F

/**
 * @brief 
 * List of test register 
 */
#define MFRC522_TEST_SEL_ONE_REG            0x31
#define MFRC522_TEST_SEL_TWO_REG            0x32
#define MFRC522_TEST_PIN_EN_REG             0x33
#define MFRC522_TEST_PIN_VALUE_REG          0x34
#define MFRC522_TEST_BUS_REG                0x35
#define MFRC522_AUTO_TEST_REG               0x36
#define MFRC522_VERSION_REG                 0x37
#define MFRC522_ANALOG_TEST_REG             0x38
#define MFRC522_TEST_DAC_ONE_REG            0x39
#define MFRC522_TEST_DAC_TWO_REG            0x3A
#define MFRC522_TEST_ADC_REG                0x3B


#endif /* MFRC522_PRV_REG_H_ */
