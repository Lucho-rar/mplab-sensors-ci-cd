/* 
 * File:   sensor.h
 * Author: Fabio
 *
 * Created on 21 de octubre de 2019, 13:03
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "communication.h"

#define CODENAME_LENGTH  5      // Number of characters for sensor codename

typedef uint16_t sensor_data_t;

typedef struct
{
	char codename[CODENAME_LENGTH];
	char address[3];
	uint16_t frequency;
    uint8_t ADCChannel;
}sensor_info_t;

typedef struct {
	sensor_info_t sensor_info;
	uint16_t (*sense)(void* sensor_conf);
}sensor_t;

uint16_t getADCData(void* sensorSelection);


extern sensor_t sensor1;
extern sensor_t sensor2;

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

