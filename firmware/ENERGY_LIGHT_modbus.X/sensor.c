#include "sensor.h"
#include "device.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "mcc_generated_files/tmr0.h"

extern volatile mod_bus_registers registers;
/*
uint16_t getADCData(void* sensorSelection)
{
    uint16_t result;
    adcc_channel_t channel;
    
    channel = *((adcc_channel_t *) sensorSelection);
    result = ADCC_GetSingleConversion(channel);
    
    return result;
}*/

uint16_t readINA220(uint8_t regadd, uint8_t address)
{
    uint8_t buff[2];
    uint16_t ret;
    uint8_t* pRxbuffer;
    uint8_t* pTxbuffer;
    pRxbuffer = &buff[0];
    pTxbuffer = &regadd;
    I2C1_WriteNBytes(address,pTxbuffer,1);
    I2C1_ReadNBytes(address,pRxbuffer,2);
    ret = buff[0];
    ret = ret << 8;
    ret = ret + buff[1];
    return ret;
}

void writeINA220(uint8_t regadd, uint16_t regdata, uint8_t address)
{
    uint8_t Txbuffer[3];
    uint8_t* pTxbuffer;
    
    Txbuffer[0] = regadd;
    Txbuffer[1] = regdata & 0x00FF;
    Txbuffer[2] = (regdata & 0xFF00) >> 8;
    pTxbuffer = &Txbuffer[0];
    I2C1_WriteNBytes(address,pTxbuffer,3);   
}

void InitINA220(sensor_config_t device)
{
    PWR_MSRE_SetHigh(); // power-on INA devices
    __delay_ms(10);
    writeINA220(CONFIG_ADDRESS, device.config , device.addressI2C);
    writeINA220(CALIBRATION_ADDRESS,device.calib, device.addressI2C);
    PWR_MSRE_SetLow(); // power-off INA devices
}


/*
 *  Fede Perez le enoja que haga esto con la memoria, Fede Perez le gustaria 
 *  que se utilice punteros. 
 *  Fran Ciordia (Osea yo) en cambio considera que usar punteros complejiza
 *  el manejo de los datos en la instacia de modbus y las soluciones que se
 *  barajaron llevan a que los bloques modbus y sensores se vuelvan muy
 *  dependientes para presentar la informacion de manera correcta.
 * 
 *  Estimado programador, sea usted quien decida el futuro de esta historia.
*/
static void pushArray(uint16_t array[], uint16_t value, uint8_t size_array)
{
  for(uint8_t i=size_array-1; i > 0; i--)
    array[i] = array[i - 1];

  array[0] = value;
}

void getINA220Data(sensor_t *device, sensor_data_t *sens)
{
    uint16_t buff;
    
    PWR_MSRE_SetHigh(); // power-on INA devices
    __delay_ms(10);
    //write mode for start single-shot conversion
    writeINA220(CONFIG_ADDRESS, device->sensor_config.config , device->sensor_config.addressI2C);
    writeINA220(CALIBRATION_ADDRESS,device->sensor_config.calib, device->sensor_config.addressI2C);
  
    buff = readINA220(BUS_VOLTAGE_ADDRESS, device->sensor_config.addressI2C);
    buff = buff >> 3;
    buff &= 0x1FFF;
    
    pushArray(sens->voltage.hist, buff, CANT_MEAS);    
    
    buff = readINA220(SHUNT_VOLTAGE_ADDRESS, device->sensor_config.addressI2C);
    
    pushArray(sens->current.hist, buff, CANT_MEAS); 
    
    PWR_MSRE_SetLow(); // power-off INA devices
    
}

void getMetrics(sensor_data_t *device)
{
    getMax(&device->current);    
    getMin(&device->current);    
    getMed(&device->current);
    getMax(&device->voltage);    
    getMin(&device->voltage);    
    getMed(&device->voltage);
}

void getMax(measure_data_t *data)
{
    int16_t aux = INT16_MIN; 
    for(uint8_t i=0; i<CANT_MEAS; i++)        
        if(aux < data->hist[i])
            aux = data->hist[i];
    
    data->max = aux;   
}

void getMin(measure_data_t *data)
{    
    int16_t aux = INT16_MAX; 
    for(uint8_t i=0; i<CANT_MEAS; i++)        
        if(aux > data->hist[i])
            aux = data->hist[i];
    
    data->min = aux;
}

void getMed(measure_data_t *data)
{
    int32_t buff = 0;

    for(uint8_t i=0; i<CANT_MEAS; i++)
        buff += data->hist[i];
    
    data->med = buff/CANT_MEAS;    
}