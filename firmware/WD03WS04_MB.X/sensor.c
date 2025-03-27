#include "sensor.h"


uint16_t getADCData(void* sensorSelection)
{
    uint16_t result;
    adcc_channel_t channel;
    
    channel = *((adcc_channel_t *) sensorSelection);
    result = ADCC_GetSingleConversion(channel);
    
    return result;
}

uint16_t getCount(void)
{
    uint16_t result;
    
    /*  Comienzan a contar los timers   */
    TMR5_StartTimer(); 
    TMR0_StartTimer();
    
    /*  Espera a que se cumpla el periodo (2.5 segundos)    */
    while(!TMR0_HasOverflowOccured())
    {}
    
    /*  Deja de contar  */
    TMR5_StopTimer();
    
    result = TMR5_ReadTimer();
    
    /* reinicializacion */
    
    TMR5_Initialize();
    TMR0_Initialize();
    
    return result;    
}
