#include "sensor.h"


uint16_t getADCData(void* sensorSelection)
{
    uint16_t result;
    adcc_channel_t channel;
    
    channel = *((adcc_channel_t *) sensorSelection);
    result = ADCC_GetSingleConversion(channel);
    
    return result;
}
