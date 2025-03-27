#include "device.h"

void getDeviceAddress(sensor_info_t* sensor_info)
{
    sensor_info->address[0] = DEVICE_ADDRESS[0];
	sensor_info->address[1] = DEVICE_ADDRESS[1];
    sensor_info->address[2] = DEVICE_ADDRESS[2];
}


/**
 * Send infomation about this device.
 * 
 * @param sensor_info
 */
//void sendSensorInfo(sensor_info_t* sensor_info)
//{
//    uint16_t freq = (*sensor_info).frequency;
//   
//    info_packet_t packet = {
//        .preamble = RESPONSE_START, 
//        .codename = DEVICE_CODENAME,
//        .end = CMD_END,
//    };
//    
//    for(int idx = 0; idx < INFO_FREQ_LENGTH; idx++)
//        packet.frequency[idx] = (char) (freq >> (8*idx));
//    
//	sendPacket((char*)&packet, sizeof(info_packet_t));
//}

/**
 * Send data through UART interface, LSB-first
 * 
 * @param sensor_data. Data to be sent
 */
//void sendSensorData(uint16_t sensor_data)
//{
//    data_packet_t packet = {.preamble = RESPONSE_START};
//    
//    int16ToString(sensor_data, packet.value);
//    
//    packet.crc8 = crc8(&packet.value,DATA_LENGTH);
//    
//    packet.end = CMD_END;
//            
//    sendPacket((char*)&packet, DATA_PACKET_LENGTH);
//}

/**
 * 
 * @param str
 * @param buf
 * @param byte_count
 * @return 
 */
//int stringCompare(const char* str, const char* buf, int byte_count)
//{
//	int idx = 0;
//
//	for(idx = 0; idx < byte_count; idx++)
//	{
//		if(*str != *buf)
//			return -1;
//		else
//		{
//			str++;
//			buf++;
//		}
//	}
//	return 0;
//}

/**
 * 
 * @param value
 * @param data
 */
//void int16ToString(uint16_t value, char *data)
//{
//    uint16_t divisor = 10000; // Max divider
//    uint16_t dividend = value;
//    uint16_t result;
//    bool flag_0 = 0;
//    
//    for(int i=0; i<5; i++)
//    {
//        result = dividend / divisor;
//        if (!((result == 0)&&(flag_0 == 0)))
//        {
//            *data = '0'+result;
//            data++;
//            flag_0 = 1;
//        }        
//        dividend = dividend % divisor;
//        divisor /= 10;
//    }
//    if(value == 0)
//    {
//        *data = '0';
//    }
//}

/**
 * 
 * @param string
 * @param strlen
 * @return 
 */
//uint16_t stringToInt16(char* string, uint16_t strlen)
//{
//    uint16_t result = 0;
//    uint16_t multiple = 1;
//    
//    for(int i=strlen; i>0; --i)
//    {
//        result = (*(string+i) - '0') * multiple;
//        multiple *= 10;
//    }
//    return result;
//}

