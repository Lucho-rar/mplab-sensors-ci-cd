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
        Device            :  PIC16F18424
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
extern uint8_t eusart1PacketFinish;
int stringCompare(const char* str, const char* buf, int byte_count);

sensor_t panel = {
    .sensor_info.codename =DEVICE_CODENAME1,
    .sensor_info.address = DEVICE_ADDRESS1,
    .sensor_config.addressI2C = ADDRESS_PANEL,
    .sensor_config.config = CONFIG_PANEL,
    .sensor_config.calib = CALIB_PANEL,    
    .sensor_data.voltage.min = 0x7FFF,
    .sensor_data.current.min = 0x7FFF,   
};

sensor_t battery = {
    .sensor_info.codename =DEVICE_CODENAME2,
    .sensor_info.address = DEVICE_ADDRESS2,
    .sensor_config.addressI2C = ADDRESS_BATTERY,
    .sensor_config.config = CONFIG_BATTERY,
    .sensor_config.calib = CALIB_BATTERY,    
    .sensor_data.voltage.min = 0x7FFF,
    .sensor_data.current.min = 0x7FFF,   
};

sensor_t cons = {    
    .sensor_info.codename =DEVICE_CODENAME3,
    .sensor_info.address = DEVICE_ADDRESS3,
    .sensor_config.addressI2C = ADDRESS_CONS,
    .sensor_config.config = CONFIG_CONS,
    .sensor_config.calib = CALIB_CONS,
    .sensor_data.voltage.min = 0x7FFF,// 7por signo
    .sensor_data.current.min = 0x7FFF,    
};

status_t status_prev = {
    .curr_tail = CURR_TAIL,                 // Corriente de corte
    .voltage_chrg_on = VOLTAGE_CHRG_ON,    // Voltage de reestablecimiento
    .beacon = 0,                // TRUE beacon on, FALSE beacon off
    .chrg = 1,                  // TRUE battery charging, FALSE don't charge
    .uvp = 0,                   // TRUE battery disconnected, FALSE battery connected
};
        
status_t status = {
    .curr_tail = CURR_TAIL,                 // Corriente de corte
    .voltage_chrg_on = VOLTAGE_CHRG_ON,    // Voltage de reestablecimiento
    .beacon = 0,                // TRUE beacon on, FALSE beacon off
    .chrg = 1,                  // TRUE battery charging, FALSE don't charge
    .uvp = 0,                   // TRUE battery disconnected, FALSE battery connected
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
    TxDeviceDisable();    
    
    PWRCHRG_SetHigh();
    LBSHUTD_SetHigh();
    RW_SetLow();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    /*  Wait until FVR being stabilized  */
    //while(!FVR_IsOutputReady());
    while(1)
    {        
        SLEEP();
        if(eusart1PacketFinish)
        {
            eusart1PacketFinish--;            
            initRxBuffer((char *)&packet.cmd_packet, CMD_PACKET_LENGTH); 
            receiveData((char *)&packet.cmd_packet,CMD_PACKET_LENGTH);
            
            if(stringCompare(packet.cmd_packet_fields.address, panel.sensor_info.address, CMD_ADDRESS_LENGTH) == 0)
            {
                processCommand(packet.cmd_packet_fields.command, &packet.cmd_packet_fields.data[0], &panel);
            }            
            if(stringCompare(packet.cmd_packet_fields.address, battery.sensor_info.address, CMD_ADDRESS_LENGTH) == 0)
			{
                processCommand(packet.cmd_packet_fields.command, &packet.cmd_packet_fields.data[0], &battery);
			}            
            if(stringCompare(packet.cmd_packet_fields.address, cons.sensor_info.address, CMD_ADDRESS_LENGTH) == 0)
			{
                processCommand(packet.cmd_packet_fields.command, &packet.cmd_packet_fields.data[0], &cons);
			}                        
        }
        if(measureTime)
        {     
            getINA220Data(&panel);
            getINA220Data(&battery);
            getINA220Data(&cons);
            getMetrics(&panel);
            getMetrics(&battery);
            getMetrics(&cons);
            measureTime = 0;
        }
        /*------------------------------ CHARGER  --------------------------------*/
        if(status.chrg != status_prev.chrg)
        {
            if(status.chrg) 
            {
                PWRCHRG_SetHigh();
            }else
            {
                PWRCHRG_SetLow();
            }
            status_prev.chrg = status.chrg;
        }
        /*----------------------- UNDER VOLTAGE PROTECCTION ------------------------------*/
        if(status.uvp != status_prev.uvp)
        {
            if(status.uvp) 
            {
                LBSHUTD_SetLow();
            }else
            {
                LBSHUTD_SetHigh();
            }
            status_prev.uvp = status.uvp;
        }
        /*------------------------------ BEACONS --------------------------------*/
        if(status.beacon != status_prev.beacon){
            if(status.beacon)
            {
                TMR4_Start();
                TMR2_Start();
            }else
            {
                TMR4_Stop();
                TMR2_Stop();
                PWR_LED_SetLow();
            }
            status_prev.beacon = status.beacon;
        }
        /*------------------------------ VOLTAGE CHARGER --------------------------------*/
        if(battery.sensor_data.voltage.med > VOLTAGE_CHRG_OFF)
        {
            if(battery.sensor_data.current.hist[battery.sensor_data.current.pWrite] > status.curr_tail)
            {
                status.chrg = 0;
            }
        }            
        else if(battery.sensor_data.voltage.med < status.voltage_chrg_on)
        {
            status.chrg = 1;
        }
        /*----------------------------- UNDER VOLTAGE PROTECTION -----------------------------------*/
        if(battery.sensor_data.voltage.hist[battery.sensor_data.voltage.pWrite] > VOLTAGE_UVP_ON)
        {
            status.uvp=0;
        }
        else if(battery.sensor_data.voltage.hist[battery.sensor_data.voltage.pWrite] < VOLTAGE_UVP_OFF)
        {
            status.uvp=1;
        }
        
    }
}