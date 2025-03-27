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

/****************** Device specific parameters ******************************/    
//#define BCAST_ADDRESS   0     // Broadcast address. All device must response to this address
#define DEVICE_ADDRESS      "001"    // Device specific address (0-255)
#define DEVICE_CODENAME	  "TC001"//
#define DEVICE_FREQUENCY	120	// In seconds    
///************************ Command packet parameters *************************/ 
//#define CMD_START			"L#"
//#define CMD_START_LENGTH	2
//#define CMD_ADDRESS_LENGTH	3
//#define CMD_COMMAND_LENGTH	1
//#define CMD_PACKET_LENGTH 	sizeof(cmd_packet_fields_t)
//#define CMD_END             '\n'
///************************ Response packet parameters *************************/  
//#define RESPONSE_START          "L>"
//#define RESPONSE_START_LENGTH   2
///* Sensor information packet parameters */    
//#define INFO_CODENAME_LENGTH    5 
//#define INFO_FREQ_LENGTH        2 
//#define INFO_PACKET_LENGTH      sizeof(info_packet_t)
///* Data packet parameters */    
//#define DATA_LENGTH     5 
//#define DATA_PACKET_LENGTH      sizeof(data_packet_t) 
///**************************** Device commands ********************************/    
//#define CMD_GET_INFO    'I' // Device will response with all its information 
//#define CMD_SENSE       'S' // Device will take sensor measurement   
//#define CMD_GET_DATA    'D' // Device will communicate its last measured data
 
//typedef struct {
//	char start[CMD_START_LENGTH];
//	char address[CMD_ADDRESS_LENGTH];
//	char command;
//} cmd_packet_fields_t;
//
//typedef union
//{
//	char cmd_packet[CMD_PACKET_LENGTH];
//	cmd_packet_fields_t cmd_packet_fields;
//} cmd_packet_t;
//
//typedef struct
//{
//    char preamble[RESPONSE_START_LENGTH];
//	char codename[CODENAME_LENGTH];
//	char frequency[sizeof(uint16_t)];
//    char end;
//} info_packet_t;
//
//typedef struct
//{
//    char preamble[RESPONSE_START_LENGTH];
//	char value[DATA_LENGTH];
//    char crc8;
//    char end;
//} data_packet_t;     

void getDeviceAddress(sensor_info_t* sensor_info);
//uint8_t getDeviceAddress2(void);
//int receiveCommand(char* cmd_buf);
//void sendSensorInfo(sensor_info_t* sensor_info);
//void sendSensorData(uint16_t sensor_data);
//int stringCompare(const char* str, const char* buf, int byte_count);
//void int16ToString(uint16_t value, char *data);
/* Auxiliary functions. Only for DEBUGGING purposes */
//void int16ToString(uint16_t value, char *data);
//uint16_t stringToInt16(char* string, uint16_t strlen);

#ifdef	__cplusplus
}
#endif

#endif	/* DEVICE_H */

