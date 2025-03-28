/* 
 * File:   device.h
 * Author: Fabio
 *
 * Created on 21 de octubre de 2019, 13:24
 */

#ifndef DEVICE_H
#define	DEVICE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "sensor.h"
#include "communication.h"
#include <stdio.h>

#define BCAST_ADDRESS   0     // Broadcast address. All device must response to this address
/****************** Device 1 specific parameters ******************************/    
#define DEVICE_ADDRESS1     "100"    // Device specific address (0-255)
#define DEVICE_CODENAME1	"EP100"//
/****************** Device 2 specific parameters ******************************/    
#define DEVICE_ADDRESS2     "101"    // Device specific address (0-255)
#define DEVICE_CODENAME2	"EB101"// 
/****************** Device 3 specific parameters ******************************/    
#define DEVICE_ADDRESS3     "102"    // Device specific address (0-255)
#define DEVICE_CODENAME3	"EC102"// 
/************************ Command packet parameters *************************/    
//#define CMD_START			"LDS#"
#define CMD_START			"L#"
#define CMD_START_LENGTH	2
#define CMD_ADDRESS_LENGTH	3
#define CMD_COMMAND_LENGTH	1
#define CMD_DATA_LENGTH     5
#define CMD_PACKET_LENGTH 	sizeof(cmd_packet_fields_t)
#define CMD_END             '\n'
/************************ Response packet parameters *************************/    
//#define RESPONSE_START          "LDS>"
#define RESPONSE_START          "L>"
#define RESPONSE_START_LENGTH   2
/* Sensor information packet parameters */    
#define INFO_CODENAME_LENGTH    5 
#define INFO_FREQ_LENGTH        2 
#define INFO_PACKET_LENGTH      sizeof(info_packet_t)
/* Data packet parameters */    
#define DATA_LENGTH     6 
#define DATA_24LENGTH     8
#define DATA_PACKET_LENGTH      sizeof(data_packet_t) 
/**************************** Device commands ********************************/    
#define CMD_GET_INFO    'I' // Device will response with all its information 
#define CMD_SENSE       'S' // Device will take sensor measurement   
#define CMD_GET_DATA    'D' // Device will communicate its last measured data
#define CMD_GET_MAX     'M' // Device will communicate its last maximum data
#define CMD_GET_MIN     'm' // Device will communicate its last minimum data
#define CMD_GET_MED     'P' // Device will communicate its last media data    
#define CMD_GET_HIS     'H' // Device will communicate its historical data
#define CMD_CONFIG_PER  'T' // Device will configurate its period time for measure
#define CMD_CONFIG_CHRG 'C' // Device will set its voltage threshold for measure re-charging
#define CMD_CONFIG_TAIL 'i' // Device will set its voltage threshold for measure re-charging
#define CMD_BEACON      'B' // Device will on or off its beacon
#define CMD_ESTADO      'E' // TRUE battery charging, FALSE don't charge
    
typedef struct {
	char start[CMD_START_LENGTH];
	char address[CMD_ADDRESS_LENGTH];
	char command;
    char data[CMD_DATA_LENGTH];
} cmd_packet_fields_t;

typedef union
{
	char cmd_packet[CMD_PACKET_LENGTH];
	cmd_packet_fields_t cmd_packet_fields;
} cmd_packet_t;

typedef struct
{
    char preamble[RESPONSE_START_LENGTH];
	char codename[CODENAME_LENGTH];
} info_packet_t;

typedef struct
{
    char preamble[RESPONSE_START_LENGTH];
	char value[DATA_LENGTH];
} data_packet_t;

int receiveCommand(char* cmd_buf);
void sendSensorInfo(sensor_info_t* sensor_info);
void sendSensorCoeff(uint8_t idx);
void sendSensorData(int16_t sensor_data);
int stringCompare(const char* str, const char* buf, int byte_count);
uint8_t stringlen(const char* str);
void int16ToString(int16_t value, char *data);
//void floatToString(float n, char *data);
//int8_t itoa(int16_t value,char *data);
uint16_t stringToInt16(char* string, uint8_t strlen);


#ifdef	__cplusplus
}
#endif

#endif	/* DEVICE_H */

