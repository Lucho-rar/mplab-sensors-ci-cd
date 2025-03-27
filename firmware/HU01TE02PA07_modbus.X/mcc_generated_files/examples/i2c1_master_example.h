/**
  I2C1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c1_master_example.h

  @Summary
    This is the generated header file for the I2C1 driver example using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for I2C1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18424
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.30
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef I2C1_MASTER_EXAMPLE_H
#define I2C1_MASTER_EXAMPLE_H
/*------------SHTC3------------*/
#define WEAKUP_CMD  0x3517
#define SLEEP_CMD   0xB098
#define MEAS_CMD    0x5C24 // Normal Mode, Clock Stretching Enable, Read RH First
#define ADDRESS_SHTC3 0x70
/*------------BMP280------------*/

#define ADDRESS_BMP280 0x76
#define STATUS_ADDRESS_ 0xF3
#define CTRL_MEAS_ADDRESS 0xF4
#define CONFIG_ADDRESS 0xF5
#define PRESS_MSB_ADDRESS 0xF7
#define PRESS_LSB_ADDRESS 0xF8
#define PRESS_XLSB_ADDRESS 0xF9
#define TEMP_MSB_ADDRESS 0xFA
#define TEMP_LSB_ADDRESS 0xFB
#define TEMP_XLSB_ADDRESS 0xFC

#define CALIB00_ADDRESS 0x88
#define CALIB01_ADDRESS 0x89
#define CALIB02_ADDRESS 0x8A
#define CALIB03_ADDRESS 0x8B
#define CALIB04_ADDRESS 0x8C
#define CALIB05_ADDRESS 0x8D
#define CALIB06_ADDRESS 0x8E
#define CALIB07_ADDRESS 0x8F
#define CALIB08_ADDRESS 0x90
#define CALIB09_ADDRESS 0x91
#define CALIB10_ADDRESS 0x92
#define CALIB11_ADDRESS 0x93
#define CALIB12_ADDRESS 0x94
#define CALIB13_ADDRESS 0x95
#define CALIB14_ADDRESS 0x96
#define CALIB15_ADDRESS 0x97
#define CALIB16_ADDRESS 0x98
#define CALIB17_ADDRESS 0x99
#define CALIB18_ADDRESS 0x9A
#define CALIB19_ADDRESS 0x9B
#define CALIB20_ADDRESS 0x9C
#define CALIB21_ADDRESS 0x9D
#define CALIB22_ADDRESS 0x9E
#define CALIB23_ADDRESS 0x9F
#define CALIB24_ADDRESS 0xA0
#define CALIB25_ADDRESS 0xA1


/*------------DPS422------------*/
#define ADDRESS_DPS422 0x76
#define MEAS_CFG_PRESTEMP 0x03 
#define PSR_B2_ADDRESS 0x00
#define PSR_B1_ADDRESS 0x01
#define PSR_B0_ADDRESS 0x02
#define TMP_B2_ADDRESS 0x03
#define TMP_B1_ADDRESS 0x04
#define TMP_B0_ADDRESS 0x05
#define PSR_CFG_ADDRESS 0x06
#define TEMP_CFG_ADDRESS 0x07
#define MEAS_CFG_ADDRESS 0x08

#define COEFF_REG_1_ADDRESS 0x26
#define COEFF_REG_2_ADDRESS 0x27
#define COEFF_REG_3_ADDRESS 0x28
#define COEFF_REG_4_ADDRESS 0x29
#define COEFF_REG_5_ADDRESS 0x2A
#define COEFF_REG_6_ADDRESS 0x2B
#define COEFF_REG_7_ADDRESS 0x2C
#define COEFF_REG_8_ADDRESS 0x2D
#define COEFF_REG_9_ADDRESS 0x2E
#define COEFF_REG_10_ADDRESS 0x2F
#define COEFF_REG_11_ADDRESS 0x30
#define COEFF_REG_12_ADDRESS 0x31
#define COEFF_REG_13_ADDRESS 0x32
#define COEFF_REG_14_ADDRESS 0x33
#define COEFF_REG_15_ADDRESS 0x34
#define COEFF_REG_16_ADDRESS 0x35
#define COEFF_REG_17_ADDRESS 0x36
#define COEFF_REG_18_ADDRESS 0x37
#define COEFF_REG_19_ADDRESS 0x38
#define COEFF_REG_20_ADDRESS 0x39


#include <stdint.h>
#include <stdio.h>
#include "../i2c1_master.h"

uint8_t BuffReg[8];

uint8_t  I2C1_Read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t I2C1_Read2ByteRegister(i2c1_address_t address, uint8_t reg);
void I2C1_Write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void I2C1_Write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);
void I2C1_WriteNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadDataBlock(i2c1_address_t address, uint8_t reg, uint8_t *data, size_t len);

#endif /* I2C1_MASTER_EXAMPLE_H */