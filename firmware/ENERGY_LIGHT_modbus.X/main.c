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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
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
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "modbus_imp.h"

extern uint8_t eusart1PacketFinish;
//extern holding_register actual_regs;
holding_register actual_regs;

void is_a_new_value(mod_bus_registers* registers,\
        holding_register* actual_regs,nmbs_t* nmbs );

int stringCompare(const char* str, const char* buf, int byte_count);

void CMP1_Interrupt_ISR();

sensor_t panel = {
    .sensor_info.codename =DEVICE_CODENAME1,
    .sensor_info.address = DEVICE_ADDRESS1,
    .sensor_config.addressI2C = ADDRESS_PANEL,
    .sensor_config.config = CONFIG_PANEL,
    .sensor_config.calib = CALIB_PANEL,     
};

sensor_t battery = {
    .sensor_info.codename =DEVICE_CODENAME2,
    .sensor_info.address = DEVICE_ADDRESS2,
    .sensor_config.addressI2C = ADDRESS_BATTERY,
    .sensor_config.config = CONFIG_BATTERY,
    .sensor_config.calib = CALIB_BATTERY,    
};

sensor_t cons = {    
    .sensor_info.codename =DEVICE_CODENAME3,
    .sensor_info.address = DEVICE_ADDRESS3,
    .sensor_config.addressI2C = ADDRESS_CONS,
    .sensor_config.config = CONFIG_CONS,
    .sensor_config.calib = CALIB_CONS,
};

int16_t prev_chgr = 1;
        
status_t status = {
    .curr_tail = CURR_TAIL,          // Corriente de corte (250mA * 10 = 2500)
    .voltage_chrg_on = VOLTAGE_CHRG_ON,    // Voltage de reestablecimiento (12.7 V * 250 = 3175)
    .beacon = 0,                // TRUE beacon on, FALSE beacon off
    .chrg = 1,                  // TRUE battery charging, FALSE don't charge
};


/*
                         Main application
 */
void main(void)
{
    cmd_packet_t packet= {
        .cmd_packet_fields.data = {'0','0','0','0','0'},
    };
    
    /*  Initialize the device   */
    SYSTEM_Initialize();
    // deshabilita el driver RS485
    TxDeviceDisable();    
    // activa la carga de bateria
    PWRCHRG_SetHigh();
    // pone alta impedancia para no afectar el corte por bajo
    LBSHUTD_SetDigitalInput();//
    //LBSHUTD_SetHigh();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    /*  Wait until FVR being stabilized  */
    //while(!FVR_IsOutputReady());
    
    mod_bus_registers registers;
    default_values_register(&registers);
    
    sensor_data_t   panel_data;  
    sensor_data_t   battery_data;
    sensor_data_t   cons_data;
    
    m_memset(&panel_data, 0, sizeof(sensor_data_t));
    m_memset(&battery_data, 0, sizeof(sensor_data_t));
    m_memset(&cons_data, 0, sizeof(sensor_data_t));
    
    registers.server_input_register.panel_data      = &panel_data;
    registers.server_input_register.battery_data    = &battery_data;
    registers.server_input_register.cons_data       = &cons_data;
    registers.server_input_register.chrg = 1;
    
    uint8_t is_in_memory = DATAEE_ReadByte(IS_IN_MEMORY_EPP_ADDR);
    /*
    for(uint8_t i=0; i<100; i++)
    {
        EUSART1_Write(DATAEE_ReadWord(0x7000+i));
        while(!EUSART1_is_tx_done());
        RW_SetLow();
    }
    */
    if (is_in_memory == IS_IN_MEMORY_VALUE)
    {
        registers.server_holding_register.addr_slave        = DATAEE_ReadWord(SLAVE_EPP_ADDR);
        registers.server_holding_register.baudrate          = DATAEE_ReadWord(BAUDRATE_EPP_ADDR);
        
        registers.server_holding_register.periode           = DATAEE_ReadWord(PERIODE_EPP_ADDR);
        registers.server_holding_register.curr_tail         = DATAEE_ReadWord(CURR_TAIL_EPP_ADDR);
        //registers.server_holding_register.curr_tail         = CURR_TAIL;
        registers.server_holding_register.voltage_chrg_on   = DATAEE_ReadWord(VOLTAGE_CHRG_ON_EPP_ADDR);
        //registers.server_holding_register.voltage_chrg_on   = VOLTAGE_CHRG_ON;
        registers.server_holding_register.beacon            = DATAEE_ReadWord(BEACON_EPP_ADDR);
    }
    else
    {
        DATAEE_WriteWord(SLAVE_EPP_ADDR,registers.server_holding_register.addr_slave);
        DATAEE_WriteWord(BAUDRATE_EPP_ADDR,registers.server_holding_register.baudrate);
        DATAEE_WriteWord(PERIODE_EPP_ADDR,registers.server_holding_register.periode);
        DATAEE_WriteWord(CURR_TAIL_EPP_ADDR,registers.server_holding_register.curr_tail);
        DATAEE_WriteWord(VOLTAGE_CHRG_ON_EPP_ADDR,registers.server_holding_register.voltage_chrg_on);
        DATAEE_WriteWord(BEACON_EPP_ADDR,registers.server_holding_register.beacon);
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
      /*    "Error en la creacion de la instancia"  */
    }
    // No need to destroy the nmbs instance, terminate the program
    //extern holding_register actual_regs;

    setCMP1InterruptHandler(CMP1_Interrupt_ISR);
    
    
    while(1)
    {   
       
        SLEEP();
        // ----------------- MODBUS ---------------------------
        if(eusart1PacketFinish)
        {
            eusart1PacketFinish--;            
              
            err = nmbs_server_poll(&nmbs);
    //       This will probably never happen, since we don't return < 0 in our platform funcs
            check_error_modbus(err);
            UART_ClearBuffer();
            is_a_new_value(&registers,&actual_regs,&nmbs);                                 
        }
        if(registers.server_holding_register.beacon != actual_regs.beacon){
            if(actual_regs.beacon)
            {
                TMR4_Start();
                TMR2_Start();
            }else
            {
                TMR4_Stop();
                TMR2_Stop();
                PWR_LED_SetLow();
            }
            registers.server_holding_register.beacon = actual_regs.beacon;
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 1))
        {
            getINA220Data(&panel, registers.server_input_register.panel_data);   
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 2))
        {
            getINA220Data(&battery, registers.server_input_register.battery_data);
        }
        if(nmbs_bitfield_read(registers.server_coils.coils, 0) || nmbs_bitfield_read(registers.server_coils.coils, 3))
        {
            getINA220Data(&cons, registers.server_input_register.cons_data);
        }
        m_memset(registers.server_coils.coils, 0, sizeof(registers.server_coils.coils));
        
        
        //-----------------------------------------------------
        if(measureTime)
        {     
            getINA220Data(&panel, registers.server_input_register.panel_data);   
            getINA220Data(&battery, registers.server_input_register.battery_data);
            getINA220Data(&cons, registers.server_input_register.cons_data);
            getMetrics(registers.server_input_register.panel_data);
            getMetrics(registers.server_input_register.battery_data);
            getMetrics(registers.server_input_register.cons_data);
            measureTime = 0;
        }
        if(registers.server_input_register.chrg != prev_chgr)
        {
            if(registers.server_input_register.chrg) 
            {
                PWRCHRG_SetHigh(); 
            }else
            {
                PWRCHRG_SetLow();
            }
            prev_chgr = registers.server_input_register.chrg;
        }
        /* se alcanzo la tension de carga y la corriente de carga */
        if(registers.server_input_register.battery_data->voltage.med > VOLTAGE_CHRG_OFF)
        {
            uint16_t* bat_registers = (uint16_t *)((((mod_bus_registers*) platform_conf.arg)->server_input_register.battery_data));
            int16_t historico_ptr= bat_registers[0];
            if(historico_ptr> CURR_TAIL){
                registers.server_input_register.chrg = 0;
            }
        } 
        else if( registers.server_input_register.battery_data->voltage.med < VOLTAGE_CHRG_ON )  
        {
            registers.server_input_register.chrg = 1;
        }
        
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
    else if(registers->server_holding_register.periode != actual_regs->periode)
    {
        timer0ReloadVal16bit = registers->server_holding_register.periode;
        TMR0_Reload();
        
        DATAEE_WriteWord(PERIODE_EPP_ADDR,registers->server_holding_register.periode);
        DATAEE_WriteByte(IS_IN_MEMORY_EPP_ADDR, IS_IN_MEMORY_VALUE);
    }
}

void CMP1_Interrupt_ISR()
{
    if(CMP1_GetOutputStatus())
    {
        //status.beacon = 1;
        actual_regs.beacon = 1;
    }else
    {
        //status.beacon = 0;
        actual_regs.beacon = 0;
    }
}