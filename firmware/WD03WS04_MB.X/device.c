#include "device.h"

/**
 * Send infomation about this device.
 * 
 * @param sensor_info
 */
void sendSensorInfo(sensor_info_t* sensor_info)
{
    info_packet_t packet = {
        .preamble = RESPONSE_START, 
        .codename = DEVICE_CODENAME2,
    };    
    for(int idx = 0; idx < INFO_CODENAME_LENGTH; idx++)
        packet.codename[idx] = sensor_info->codename[idx];
            
	sendPacket((char*)&packet, INFO_PACKET_LENGTH);
}

/**
 * Send data through UART interface, LSB-first
 * 
 * @param sensor_data. Data to be sent
 */
void sendSensorData(uint16_t sensor_data)
{
    data_packet_t packet = {.preamble = RESPONSE_START};

    uint24ToString(sensor_data, packet.value);
            
    sendPacket((char*)&packet, (RESPONSE_START_LENGTH+stringlen(packet.value)));
}

/**
 * 
 * @param str
 * @param buf
 * @param byte_count
 * @return 
 */


int stringCompare(const char* str, const char* buf, int byte_count)
{
	int idx = 0;

	for(idx = 0; idx < byte_count; idx++)
	{
		if(*str != *buf)
			return -1;
		else
		{
			str++;
			buf++;
		}
	}
	return 0;
}

/**
 * 
 * @param str
 * @return 
 */
uint8_t stringlen(const char* str)
{
	uint8_t idx = 0;

	for(idx = 0; idx < 255; idx++)
	{
		if(*str == 0)
			return idx;
        str++;
	}
	return -1;
}

/**
 * 
 * @param value
 * @param data
 */
void uint24ToString(uint24_t value, char *data)
{
    uint24_t divisor = 10000000; // Max divider
    uint24_t dividend = value;
    uint24_t result;
    bool flag_0 = 0;
    
    for(int i=0; i<8; i++)
    {
        result = dividend / divisor;
        if (!((result == 0)&&(flag_0 == 0)))
        {
            *data = '0'+result;
            data++;
            flag_0 = 1;
        }        
        dividend = dividend % divisor;
        divisor /= 10;
    }
    if(value == 0)
    {
        *data = '0';
    }
}
