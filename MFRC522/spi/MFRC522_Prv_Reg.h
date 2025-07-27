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
 * List of register
 * */
#define COMMAND_REG    0x01
#define COM_I_EN_REG   0x02
#define DIV_I_EN_REG   0x03
#define COM_IRQ_REG    0x04
#define DIV_IRQ_REG    0x05
#define ERROR_REG      0x06
#define STATUS_ONE_REG 0x07
#define STATUS_TWO_REG 0x08





#endif /* MFRC522_PRV_REG_H_ */
