/* 
 * File:   communication.h
 * Author: Fabio
 *
 * Created on 21 de octubre de 2019, 11:56
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"

/*  Communication parameters  */    
#define MAX_RX_TIMEOUT      0xFF   
#define POLY                0x07
    
void initRxBuffer(char* buf, uint32_t size);
void sendPacket(const char *str, uint32_t byteCount);
uint8_t receiveData(char *data, uint8_t maxdata);
void TxDeviceEnable(void);
void TxDeviceDisable(void);
uint8_t crc8_init(uint8_t poly);
uint8_t crc8(uint8_t* data, uint8_t length);

#ifdef	__cplusplus
}
#endif

#endif	/* COMMUNICATION_H */

