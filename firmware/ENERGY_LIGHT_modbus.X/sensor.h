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
#include "modbus_imp.h"

#define CODENAME_LENGTH 5      // Number of characters for sensor codename
#define CANT_MEAS       8      // Number of samples
#define VOLTAGE_CHRG_OFF    3375   // Voltage de corte (13.5 V * 250 = 3375)
#define VOLTAGE_CHRG_ON     3125   // Voltage de reestablecimiento (12.5 V * 250 = 3125)
#define CURR_TAIL           1000  // Corriente de corte (250mA * 10 = 2500)
    
typedef struct
{
	char codename[CODENAME_LENGTH];
	char address[3];
	//uint16_t frequency;
    //uint8_t ADCChannel;
}sensor_info_t;

typedef struct
{
	uint8_t addressI2C;
    uint16_t config;
    uint16_t calib;
}sensor_config_t;

typedef struct {
	sensor_info_t sensor_info;
	sensor_config_t sensor_config;
    //sensor_data_t sensor_data;    
}sensor_t;

typedef struct {          
    uint16_t voltage_chrg_on;       
    uint16_t curr_tail;
    bool beacon;
    bool chrg;
}status_t;

uint16_t getADCData(void* sensorSelection);

uint16_t readINA220(uint8_t regadd, uint8_t address);
void writeINA220(uint8_t regadd, uint16_t regdata, uint8_t address);
void InitINA220(sensor_config_t device);
void getINA220Data(sensor_t *device, sensor_data_t *hist);
void getMetrics(sensor_data_t *device);
void getMax(measure_data_t *data);
void getMin(measure_data_t *data);
void getMed(measure_data_t *data);
void getHis(measure_data_t *data);
extern sensor_t panel;
extern sensor_t battery;
extern sensor_t cons;

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

