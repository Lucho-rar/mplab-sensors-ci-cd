
#ifndef MODBUS_IMP_H
#define	MODBUS_IMP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "nanomodbus.h"
    
#define COILS_ADDR_MAX          5
#define REGS_INPUT_ADDR_MAX     69
#define REGS_HOLDING_ADDR_MAX   6

// Our RTU address
#define RTU_SERVER_ADDRESS_DEFAULT  4
#define RTU_BAUDRATE_DEFAULT        9600

#define RTU_SERIAL_NUMBER_DEFAULT   1
#define RTU_SENSOR_TYPE_DEFAULT     100

    
#define MAX_SLAVE_VALUE              255    
#define MIN_SLAVE_VALUE              1    

#define IS_IN_MEMORY_VALUE          0x00    
#define IS_IN_MEMORY_EPP_ADDR       0x7001    
#define SLAVE_EPP_ADDR              0x7002
#define BAUDRATE_EPP_ADDR           0x7004
#define PERIODE_EPP_ADDR            0x7006
#define CURR_TAIL_EPP_ADDR          0x7008
#define VOLTAGE_CHRG_ON_EPP_ADDR    0x700A
#define BEACON_EPP_ADDR             0x700C
    
typedef struct
{
    // 0 t0 255
    uint16_t addr_slave;
    uint16_t baudrate;
    
    uint16_t periode;
    uint16_t voltage_chrg_on;
    uint16_t curr_tail;
    uint16_t beacon;
}holding_register;


#define HIST_SIZE   8
#define MIN_SIZE    1
#define MAX_SIZE    1
#define MED_SIZE    1


#define SENSOR_TYPE_ADDR        0
#define SERIAL_NUMBER_ADDR      1

#define CHARGE_ADDR             2

#define PANEL_HIST_VOLT_ADDR    3
#define PANEL_MAX_VOLT_ADDR     PANEL_HIST_VOLT_ADDR+HIST_SIZE 
#define PANEL_MIN_VOLT_ADDR     PANEL_MAX_VOLT_ADDR+MAX_SIZE
#define PANEL_MED_VOLT_ADDR     PANEL_MIN_VOLT_ADDR+MIN_SIZE

#define PANEL_HIST_CURR_ADDR    14   
#define PANEL_MAX_CURR_ADDR     PANEL_HIST_CURR_ADDR+HIST_SIZE
#define PANEL_MIN_CURR_ADDR     PANEL_MAX_CURR_ADDR+MAX_SIZE
#define PANEL_MED_CURR_ADDR     PANEL_MIN_CURR_ADDR+MIN_SIZE


#define BAT_HIST_VOLT_ADDR      25  
#define BAT_MAX_VOLT_ADDR       BAT_HIST_VOLT_ADDR+HIST_SIZE
#define BAT_MIN_VOLT_ADDR       BAT_MAX_VOLT_ADDR+MAX_SIZE
#define BAT_MED_VOLT_ADDR       BAT_MIN_VOLT_ADDR+MIN_SIZE

#define BAT_HIST_CURR_ADDR      36    
#define BAT_MAX_CURR_ADDR       BAT_HIST_CURR_ADDR+HIST_SIZE
#define BAT_MIN_CURR_ADDR       BAT_MAX_CURR_ADDR+MAX_SIZE
#define BAT_MED_CURR_ADDR       BAT_MIN_CURR_ADDR+MIN_SIZE


#define CONS_HIST_VOLT_ADDR      47   
#define CONS_MAX_VOLT_ADDR       CONS_HIST_VOLT_ADDR+HIST_SIZE
#define CONS_MIN_VOLT_ADDR       CONS_MAX_VOLT_ADDR+MAX_SIZE
#define CONS_MED_VOLT_ADDR       CONS_MIN_VOLT_ADDR+MIN_SIZE

#define CONS_HIST_CURR_ADDR      58 
#define CONS_MAX_CURR_ADDR       CONS_HIST_CURR_ADDR+HIST_SIZE
#define CONS_MIN_CURR_ADDR       CONS_MAX_CURR_ADDR+MAX_SIZE
#define CONS_MED_CURR_ADDR       CONS_MIN_CURR_ADDR+MIN_SIZE

typedef struct
{
    int16_t hist[HIST_SIZE];
	int16_t max;
    int16_t min;
    int16_t med;
}measure_data_t;

typedef struct
{
	measure_data_t voltage;
    measure_data_t current;
}sensor_data_t;


typedef struct
{
    uint16_t        sensor_type;
    uint16_t        serial_number;
    
    uint16_t        chrg;
       
    sensor_data_t   *panel_data;  
    sensor_data_t   *battery_data;
    sensor_data_t   *cons_data;
}input_register;

typedef struct
{
// A single nmbs_bitfield variable can keep 2000 coils
    nmbs_bitfield coils;
}coils;

typedef struct
{
    coils server_coils;
    input_register server_input_register;
    holding_register server_holding_register;
}mod_bus_registers;


void default_values_register(mod_bus_registers* registers);
void check_error_modbus(nmbs_error err);

int32_t read_serial(uint8_t* buf, uint16_t count, int32_t byte_timeout_ms, void* arg);
int32_t write_serial(const uint8_t* buf, uint16_t count, int32_t byte_timeout_ms, void* arg);
nmbs_error handle_read_coils(uint16_t address, uint16_t quantity, nmbs_bitfield coils_out, uint8_t unit_id, void *arg);
nmbs_error handle_write_single_coil(uint16_t address, bool coils, uint8_t unit_id, void *arg);
nmbs_error handler_read_input_registers(uint16_t address, uint16_t quantity, uint16_t* registers_out, uint8_t unit_id, void *arg);
nmbs_error handler_read_holding_registers(uint16_t address, uint16_t quantity, uint16_t* registers_out, uint8_t unit_id, void *arg);
nmbs_error handle_write_single_register(uint16_t address, const uint16_t* registers, uint8_t unit_id, void *arg);
void check_error_modbus(nmbs_error err);





#ifdef	__cplusplus
}
#endif

#endif	/* MODBUS_IMP_H */

