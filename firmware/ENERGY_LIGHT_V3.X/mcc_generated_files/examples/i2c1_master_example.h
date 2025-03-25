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

/*------------INA220------------*/

#define ADDRESS_PANEL 0x40
#define ADDRESS_BATTERY 0x41
#define ADDRESS_CONS 0x42

#define CONFIG_PANEL 0x3C43     //32V, GAIN 8, 1SAMPLE 12BIT, SHUNT AND BUS TRIGGERED
#define CONFIG_BATTERY 0x1C43   //16V, GAIN 8, 1SAMPLE 12BIT, SHUNT AND BUS TRIGGERED
#define CONFIG_CONS 0x1C43     //16V, GAIN 8, 1SAMPLE 12BIT, SHUNT AND BUS TRIGGERED

#define CALIB_PANEL     0x1A36  //2A EXPECTED CURRENT, RSHUNT 0.1 OHM, 61.169 uV/BIT
#define CALIB_BATTERY   0x1A36  //2A EXPECTED CURRENT, RSHUNT 0.1 OHM, 61.169 uV/BIT
#define CALIB_CONS      0x1A36  //2A EXPECTED CURRENT, RSHUNT 0.1 OHM, 61.169 uV/BIT

#define CONFIG_ADDRESS 0x00
#define SHUNT_VOLTAGE_ADDRESS 0x01
#define BUS_VOLTAGE_ADDRESS 0x02
#define POWER_ADDRESS 0x03
#define CURRENT_ADDRESS 0x04
#define CALIBRATION_ADDRESS 0x05

#define RSHUNT  100
#define MAXIMUM_EXPECTED_CURRENT 2
#define CURRENTE_LSB = MAXIMUM_EXPECTED_CURRENT/32768
#define CAL = 0.04096/(CURRENTE_LSB*RSHUNT)



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