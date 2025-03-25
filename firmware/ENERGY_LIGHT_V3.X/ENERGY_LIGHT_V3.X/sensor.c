#include "sensor.h"
#include "device.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "mcc_generated_files/tmr0.h"

extern status_t status;
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



void getINA220Data(sensor_t *device)
{
    int16_t buff;
    
    PWR_MSRE_SetHigh(); // power-on INA devices
    __delay_ms(10);
    //write mode for start single-shot conversion
    writeINA220(CONFIG_ADDRESS, device->sensor_config.config , device->sensor_config.addressI2C);
    writeINA220(CALIBRATION_ADDRESS,device->sensor_config.calib, device->sensor_config.addressI2C);
  
    buff = readINA220(BUS_VOLTAGE_ADDRESS, device->sensor_config.addressI2C);
    buff = buff >> 3;
    buff &= 0x1FFF;
    
    device->sensor_data.voltage.pWrite++;
    
    if(device->sensor_data.voltage.pWrite == CANT_MEAS)
    {
        device->sensor_data.voltage.pWrite = 0;
        device->sensor_data.voltage.max = 0x8000;//0x7FFF;
        device->sensor_data.voltage.min = 0x7FFF;        
    }
    
    device->sensor_data.voltage.hist[device->sensor_data.voltage.pWrite] = buff;    
    
    buff = readINA220(SHUNT_VOLTAGE_ADDRESS, device->sensor_config.addressI2C);
    
    device->sensor_data.current.pWrite++;
    
    if(device->sensor_data.current.pWrite == CANT_MEAS)
    {
        device->sensor_data.current.pWrite = 0;
        device->sensor_data.current.max = 0x8000;//0x7FFF;
        device->sensor_data.current.min = 0x7FFF;        
    }
    
    device->sensor_data.current.hist[device->sensor_data.current.pWrite] = buff;
    
    PWR_MSRE_SetLow(); // power-off INA devices
    
}

void getMetrics(sensor_t *device)
{
    getMax(&device->sensor_data.current);    
    getMin(&device->sensor_data.current);    
    getMed(&device->sensor_data.current);
    getMax(&device->sensor_data.voltage);    
    getMin(&device->sensor_data.voltage);    
    getMed(&device->sensor_data.voltage);
}

void getMax(measure_data_t *data)
{
    uint8_t aux;   
    aux = data->pWrite;
    //data->max = data->hist[aux];
    for(uint8_t i=0; i<CANT_MEAS; i++)
    {
        if(data->max < data->hist[aux])
        {
            data->max = data->hist[aux];
        }
        if(aux == 0)
        {
            aux = CANT_MEAS;     
        }
        aux--;    
    }
    //sendSensorData(data->max);    
}

void getMin(measure_data_t *data)
{    
    uint8_t aux;   
    aux = data->pWrite;
    //data->min = data->hist[aux];
    for(uint8_t i=0; i<CANT_MEAS; i++)        
    {
        if(data->min > data->hist[aux])
        {
            data->min = data->hist[aux];
        }
        if(aux == 0)
        {
            aux = CANT_MEAS;     
        }
        aux--;    
    }   
    //sendSensorData(data->min);
}

void getMed(measure_data_t *data)
{
    int32_t buff = 0;
    uint8_t aux;   
    aux = data->pWrite;
    for(uint8_t i=0; i<CANT_MEAS; i++)
    {
        buff += data->hist[aux];
        if(aux == 0)
        {
            aux = CANT_MEAS;     
        }
        aux--;    
    } 
    data->med = buff/CANT_MEAS;    
}

void getHis(measure_data_t *data)
{
    uint8_t aux;   
    aux = data->pWrite;
    for(uint8_t i=0; i<CANT_MEAS; i++)
    {        
        sendSensorData(data->hist[aux]);
        if(aux == 0)
        {
            aux = CANT_MEAS;     
        }
        aux--;    
    }    
}

void processCommand(char command, char* data, sensor_t *sensor)
{
switch(command)
    {
    case CMD_GET_INFO:
        sendSensorInfo(&sensor->sensor_info);
        break;
    case CMD_SENSE:
        getINA220Data(sensor);
        break;
    case CMD_GET_DATA:
        sendSensorData(sensor->sensor_data.voltage.hist[sensor->sensor_data.voltage.pWrite]);                    
        sendSensorData(sensor->sensor_data.current.hist[sensor->sensor_data.current.pWrite]);
        break;
    case CMD_GET_MAX:
        getMax(&sensor->sensor_data.voltage);
        getMax(&sensor->sensor_data.current);
        sendSensorData(sensor->sensor_data.voltage.max);
        sendSensorData(sensor->sensor_data.current.max);
        break;
    case CMD_GET_MIN:
        getMin(&sensor->sensor_data.voltage);
        getMin(&sensor->sensor_data.current);
        sendSensorData(sensor->sensor_data.voltage.min);
        sendSensorData(sensor->sensor_data.current.min);                       
        break;
    case CMD_GET_MED:
        getMed(&sensor->sensor_data.voltage);
        getMed(&sensor->sensor_data.current);
        sendSensorData(sensor->sensor_data.voltage.med);                    
        sendSensorData(sensor->sensor_data.current.med);
        break;
    case CMD_GET_HIS:
        getHis(&sensor->sensor_data.voltage);
        getHis(&sensor->sensor_data.current);
        break;
    case CMD_CONFIG_PER:
        timer0ReloadVal16bit = stringToInt16(data,stringlen(data));
        TMR0_Reload();
        break;
    case CMD_BEACON:
    switch(data[0])
    {
        case '0':
            status.beacon = 0;
            break;
        case '1':
            status.beacon = 1;
            break;
        default:
            break;
    }                   
    break;
    case CMD_CONFIG_CHRG:
        status.voltage_chrg_on = stringToInt16(data,stringlen(data));
        break;
    case CMD_CONFIG_TAIL:
        status.curr_tail = stringToInt16(data,stringlen(data));
        break;
    case CMD_ESTADO:
        sendSensorData(status.voltage_chrg_on);
        sendSensorData(status.curr_tail);
        sendSensorData(status.beacon);
        sendSensorData(status.chrg);
        break;
    default:
        break;
    }
}