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
        .codename = DEVICE_CODENAME1,
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
void sendSensorData(int16_t sensor_data)
{
    data_packet_t packet = {.preamble = RESPONSE_START};
    int16ToString(sensor_data, packet.value);
    
    sendPacket((char*)&packet, (RESPONSE_START_LENGTH+stringlen(packet.value)));
    //RW_SetLow();
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
void int16ToString(int16_t value, char *data)
{
    uint16_t divisor = 10000; // Max divider
    int16_t dividend = value;
    int16_t result;
    bool flag_0 = 0;
    if((value == 0)||(value == 0xFFFF))
    {
        *data = '0';
    }
    else
    {   
        if(value < 0)
        {
            *data = '-';
            dividend =~ value;               
            data++;
        }    
        for(int i=0; i<5; i++)
        {
            result = dividend / divisor;
            if((result > 0) || (flag_0 == 1))
            {
                *data = '0'+result;
                data++;
                flag_0 = 1;
            }
            dividend = dividend % divisor;
            divisor /= 10;
        }
    }    
}

/**
 * 
 * @param value
 * @param data
 */
/*
void floatToString(float n, char *data)
{
    uint16_t ipart = 0; // Max divider
    float fpart = 0;
    uint16_t i;
    //uint8_t flag_0 = 0;
    
    
    
    // Extract integer part
    ipart = (uint16_t)n;
  
    // Extract floating part
    fpart = n - (float)ipart;
  
    // convert integer part to string
    int16ToString(ipart, data);
    i = stringlen(data);
  
    data[i] = '.'; // add dot
  
    // Get the value of fraction part upto given no.
    // of points after dot. The third parameter 
    // is needed to handle cases like 233.007
    fpart = fpart * 100;// 2 decimales
    int16ToString((uint16_t)fpart,data+i+1);
}

int8_t itoa(int16_t value,char *data)
     {
        int16_t count=0,temp;

        if(value==0)
        {   
            *data='0';
            return 1;
        }

        if(value<0)
        {
            value*=(-1);    
            *data++='-';
            count++;
        }
        for(temp=value;temp>0;temp/=10,data++);
        *data='\0';
        for(temp=value;temp>0;temp/=10)
        {
            *--data=temp%10+'0';
            count++;
        }
        return count;
     }
*/
/**
 * 
 * @param string
 * @param strlen
 * @return 
 */
/*
uint16_t stringToInt16(char* string, uint8_t strlen)
{
    uint16_t result = 0;
    uint16_t multiple = 1;
    
    for(int i=strlen; i>-1; --i)
    {
        result += (*(string+i) - '0') * multiple;
        multiple *= 10;
    }
    return result;
}*/

int16_t stringToInt16(char* string, uint8_t strlen)
{
    int16_t result = 0;
    int16_t multiple = 1;
    int8_t sign = 1;
    // Verificar si el primer carácter es un signo negativo
    if (*string == '-')
    {
        sign = -1;
    }
    string = string+strlen; // puntero al final
    while(strlen)
    {
        string--;
        strlen--;
        if(*string >= '0' && *string <= '9')
        {
            result += (*string - '0') * multiple;
            multiple *= 10;
        }
    }
    result = result * sign;
    return result;
}


