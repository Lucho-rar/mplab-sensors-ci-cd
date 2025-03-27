/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18425
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "device.h"
#include "modbus_imp.h"

extern uint8_t eusart1PacketFinish;

void is_a_new_value(mod_bus_registers* registers,\
        holding_register* actual_regs,nmbs_t* nmbs );

//int stringCompare(const char* str, const char* buf, int byte_count);

sensor_t sensor1 = {
        {   
        .codename = DEVICE_CODENAME1,
        .address = DEVICE_ADDRESS1,
        .ADCChannel = A5,
       },
	.sense = getADCData,
};
sensor_t sensor2 = {
        {   
        .codename = DEVICE_CODENAME2, 
        .address = DEVICE_ADDRESS2, 
        .ADCChannel = A5,
       },
	.sense = getADCData,
};
sensor_t sensor3 = {
       {
       .codename = DEVICE_CODENAME3,
       .address = DEVICE_ADDRESS3, 
       },
};
sensor_t sensor4 = {
       {
       .codename = DEVICE_CODENAME4,
       .address = DEVICE_ADDRESS4, 
       },
};

/*
                         Main application
 */
void main(void)
{
    cmd_packet_t packet;
    
    /*  Initialize the device   */
    SYSTEM_Initialize();
    TxDeviceDisable();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    InitBMP280();
    /*  Wait until FVR being stabilized  */
    while(!FVR_IsOutputReady());
    
    mod_bus_registers registers;
    default_values_register(&registers);
   
    uint8_t is_in_memory = DATAEE_ReadByte(IS_IN_MEMORY_EPP_ADDR);

    if (is_in_memory == IS_IN_MEMORY_VALUE)
    {
        registers.server_holding_register.addr_slave    = DATAEE_ReadWord(SLAVE_EPP_ADDR);
        registers.server_holding_register.baudrate     = DATAEE_ReadWord(BAUDRATE_EPP_ADDR);
    }
    else
    {
        DATAEE_WriteWord(SLAVE_EPP_ADDR,registers.server_holding_register.addr_slave);
        DATAEE_WriteWord(BAUDRATE_EPP_ADDR,registers.server_holding_register.baudrate);
    }
    setBaudRateEUSART1(registers.server_holding_register.baudrate);
//     Create the modbus server
    nmbs_t nmbs;
    
    nmbs_platform_conf platform_conf;
    platform_conf.transport = NMBS_TRANSPORT_RTU;
    platform_conf.read = read_serial;
    platform_conf.write = write_serial;
    platform_conf.arg = &(registers);

    nmbs_callbacks callbacks;
    callbacks.read_holding_registers    = handler_read_holding_registers;
    callbacks.read_input_registers      = handler_read_input_registers;
    
    callbacks.write_single_coil      = handle_write_single_coil;
    callbacks.write_single_register  = handle_write_single_register;

    nmbs_error err = nmbs_server_create(&nmbs, registers.server_holding_register.addr_slave, &platform_conf, &callbacks);
    if (err != NMBS_ERROR_NONE) {
      while(1){};
      printf("Error en la creacion de la instancia\n");
    }
    // No need to destroy the nmbs instance, terminate the program
    holding_register actual_regs;
   
    while(1)
    {
        actual_regs= registers.server_holding_register; 
        if(eusart1PacketFinish)
        {
            eusart1PacketFinish--;
            
            err = nmbs_server_poll(&nmbs);
    //       This will probably never happen, since we don't return < 0 in our platform funcs
            check_error_modbus(err);
            UART_ClearBuffer();
            is_a_new_value(&registers,&actual_regs,&nmbs);
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 1))
        {
            registers.server_input_register.sensor1_value = sensor1.sense(&sensor1.sensor_info.ADCChannel);
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 2))
        {
            registers.server_input_register.sensor2_value = getSHTC3Data();
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 3))
        {
            registers.server_input_register.sensor3_valueL =  (uint16_t)(getBMP280Data(PRES) & 0xFFFF);;
            registers.server_input_register.sensor3_valueH = (uint16_t)((getBMP280Data(PRES) >> 16) & 0xFF);

        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 4))
        {
            registers.server_input_register.sensor4_valueL =  (uint16_t)(getBMP280Data(TEMP) & 0xFFFF);;
            registers.server_input_register.sensor4_valueH = (uint16_t)((getBMP280Data(TEMP) >> 16) & 0xFF);
        }
        m_memset(registers.server_coils.coils, 0, sizeof(registers.server_coils.coils));
    }
}

void is_a_new_value(mod_bus_registers* registers,holding_register* actual_regs,nmbs_t* nmbs )
{
    if(registers->server_holding_register.addr_slave != actual_regs->addr_slave)
    {
        if(registers->server_holding_register.addr_slave <=MAX_SLAVE_VALUE  
                & registers->server_holding_register.addr_slave > MIN_SLAVE_VALUE-1)
        {
            nmbs->address_rtu = registers->server_holding_register.addr_slave;
            DATAEE_WriteWord(SLAVE_EPP_ADDR,registers->server_holding_register.addr_slave);
            DATAEE_WriteByte(IS_IN_MEMORY_EPP_ADDR, IS_IN_MEMORY_VALUE);
        }
        else
        {
            registers->server_holding_register.addr_slave = actual_regs->addr_slave;
        }  
    }
    else if(registers->server_holding_register.baudrate != actual_regs->baudrate)
    {
        if(setBaudRateEUSART1(registers->server_holding_register.baudrate))
        {
            registers->server_holding_register.baudrate = actual_regs->baudrate;
        }
        else
        {
            DATAEE_WriteWord(BAUDRATE_EPP_ADDR,registers->server_holding_register.baudrate);
            DATAEE_WriteByte(IS_IN_MEMORY_EPP_ADDR, IS_IN_MEMORY_VALUE);
        }
    }
}