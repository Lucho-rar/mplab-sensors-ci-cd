#include "communication.h"

/**
 * @brief Initializes full buffer to null character.
 * @param buf
 * @param size
 */
void initRxBuffer(char* buf, uint32_t size)
{
    for(int i=0; i<size; i++)
    {
        buf[i]='\0';
    }
}

/**
 * @brief Send a null-terminated string
 * @param str
 */
void sendPacket(const char *str, uint32_t byteCount)
{
    TxDeviceEnable();

    for(int i=0; i<byteCount; i++)
    {
        if(EUSART1_is_tx_ready())
        {
            EUSART1_Write(*str);
            while(!EUSART1_is_tx_done());
            str++;
        }
    }
    if(EUSART1_is_tx_ready())
        {
            EUSART1_Write('\n');
            while(!EUSART1_is_tx_done());
        }
    TxDeviceDisable();
}

/**
 * 
 * @param data
 * @param timeout
 */
uint8_t receiveData(char *data, uint8_t maxdata)
{
    uint8_t charCount = 0;
    uint8_t c;
    do
    {
        c = EUSART1_Read();
        if(charCount < maxdata) //Cambiado. antes estaba <=
        {
            data[charCount++] = c; //Estaba pisando memoria que no debe. Resuelto con el cambio de arriba
        }
    }while(c != 0x0A);
    //charCount
    //data[charCount] = 0; //Esta pisando memoria que no debe. ¿No deberia ser data[maxdata]?
    return charCount;
}

void TxDeviceEnable(void)
{
    LATCbits.LATC3 = 1;   
}

void TxDeviceDisable(void)
{
    LATCbits.LATC3 = 0;
}
        

