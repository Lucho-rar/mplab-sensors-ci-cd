#include "communication.h"

/**
 * @brief Initializes full buffer to null character.
 * @param buf
 * @param size
 */
//void initRxBuffer(char* buf, uint32_t size)
//{
//    for(int i=0; i<size; i++)
//    {
//        buf[i]='\0';
//    }
//}

/**
 * @brief Send a null-terminated string
 * @param str
 */
//void sendPacket(const char *str, uint32_t byteCount)
//{
//    
//    TxDeviceEnable();
//
//    for(int i=0; i<byteCount; i++)
//    {
//        if(EUSART1_is_tx_ready())
//        {
//            EUSART1_Write(*str);
//            while(!EUSART1_is_tx_done());
//            str++;
//        }
//    }
//    TxDeviceDisable();
//}

/**
 * 
 * @param data
 * @param timeout
 */
//uint8_t receiveData(char *data, uint8_t maxdata)
//{
//    uint8_t charCount = 0;
//    uint8_t c;
//    
//    do
//    {
//        c = EUSART1_Read();
//        if(charCount <= maxdata)
//        {
//            data[charCount++] = c;
//        }
//    }while(c != 0x0A);
//    
//    data[charCount] = 0;
//    return charCount;
//}

void TxDeviceEnable(void)
{
    LATCbits.LATC3 = 1;   
}

void TxDeviceDisable(void)
{
    LATCbits.LATC3 = 0;
}

//uint8_t Crc8LutL[16];
//uint8_t Crc8LutH[16];
//
//uint8_t crc8_init(uint8_t poly) {
//    for (uint8_t i = 0; i < 16; i++) {
//        uint8_t crc = (uint8_t)i;
//
//        for (uint8_t j = 1; j <= 8; j++) {
//            if (crc & 0x80) {
//                crc = (uint8_t)((crc << 1) ^ poly);
//            } else {
//                crc <<= 1;
//            }
//        }
//
//        Crc8LutL[i] = crc;
//    }
//
//    for (uint8_t i = 0; i < 16; i++) {
//        uint8_t crc = (uint8_t)i << 4;
//
//        for (uint8_t j = 1; j <= 8; j++) {
//            if (crc & 0x80) {
//                crc = (uint8_t)((crc << 1) ^ poly);
//            } else {
//                crc <<= 1;
//            }
//        }
//
//        Crc8LutH[i] = crc;
//    }
//}
//
//uint8_t crc8(uint8_t* data, uint8_t length) {
//    uint8_t crc = 0;
//    while (length--) {
//        crc ^= *data++;
//        crc = Crc8LutL[crc & 0x0F] ^ Crc8LutH[crc >> 4];
//    }
//    return crc;
//}