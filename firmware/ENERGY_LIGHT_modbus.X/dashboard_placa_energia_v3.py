import minimalmodbus
import time
import os


# Configuración del dispositivo Modbus RTU
instrument = minimalmodbus.Instrument('COM13', 4)  # Ajusta el puerto y la dirección del dispositivo según tu configuración
instrument.serial.baudrate = 9600  # Ajusta la velocidad de baudios según tu configuración
instrument.serial.bytesize = 8
instrument.serial.parity = minimalmodbus.serial.PARITY_NONE
instrument.serial.stopbits = 1
instrument.serial.timeout = 1  # Ajusta el tiempo de espera según tu configuración

# Función para leer y mostrar valores
def read_values(start_register, num_registers, label):
    try:
        # Leer los valores de los registros
        values = instrument.read_registers(start_register, num_registers, functioncode=4)
        return values
        
    except Exception as e:
        #print(f"Error al leer los valores de {label}: {e}")
        values = [4444] * 11
        return values

def print_energy_data(base):
    print(f"\tTensión\t\t\t\t\t\t\t\t\tCorriente")
    print(f"\tHistórico: {[v if v <= 32767 else v - 65536 for v in reg_values[base:base+8]]}\t\t"
          f"Histórico: {[v if v <= 32767 else v - 65536 for v in reg_values[base+11:base+19]]}\n")
    
    print(f"\tMáximo: {reg_values[base+8] if reg_values[base+8] <= 32767 else reg_values[base+8] - 65536}\t"
          f"Mínimo: {reg_values[base+9] if reg_values[base+9] <= 32767 else reg_values[base+9] - 65536}\t"
          f"Promedio: {reg_values[base+10] if reg_values[base+10] <= 32767 else reg_values[base+10] - 65536}\t\t\t\t"
          f"Máximo: {reg_values[base+19] if reg_values[base+19] <= 32767 else reg_values[base+19] - 65536}\t"
          f"Mínimo: {reg_values[base+20] if reg_values[base+20] <= 32767 else reg_values[base+20] - 65536}\t"
          f"Promedio: {reg_values[base+21] if reg_values[base+21] <= 32767 else reg_values[base+21] - 65536}\n")

# Definir la estructura de los registros
panel_tension_start_register = 3
panel_corriente_start_register = panel_tension_start_register + 11  # (8 valores de tensión + 3 valores max/min/avg)
bateria_tension_start_register = panel_corriente_start_register + 11
bateria_corriente_start_register = bateria_tension_start_register + 11  # (8 valores de tensión + 3 valores max/min/avg)
consumo_tension_start_register = bateria_corriente_start_register + 11
consumo_corriente_start_register = consumo_tension_start_register + 11  # (8 valores de tensión + 3 valores max/min/avg)

time_sleep=0.3
sistema_operativo = os.name


while(1):
    reg_values = []
    # Leer y mostrar los valores
    reg_values.extend(read_values(panel_tension_start_register, 11, "Tensión de panel"))
    time.sleep(time_sleep)
    reg_values.extend(read_values(panel_corriente_start_register, 11, "Corriente de panel"))
    time.sleep(time_sleep)
    reg_values.extend(read_values(bateria_tension_start_register, 11, "Tensión de bateria"))
    time.sleep(time_sleep)
    reg_values.extend(read_values(bateria_corriente_start_register, 11, "Corriente de bateria"))
    time.sleep(time_sleep)
    reg_values.extend(read_values(consumo_tension_start_register, 11, "Tensión de consumo"))
    time.sleep(time_sleep)
    reg_values.extend(read_values(consumo_corriente_start_register, 11, "Corriente de consumo"))
    time.sleep(time_sleep)

    if sistema_operativo == 'posix':
        os.system('clear')  # Comando para sistemas Unix (Linux, macOS)
    elif sistema_operativo == 'nt':
        os.system('cls')    # Comando para sistemas Windows
    base = 0
    print(f"\rPanel")
    print_energy_data(base)

    base = 22
    print(f"\rBateria")
    print_energy_data(base)

    base = 44
    print(f"\rConsumo")
    print_energy_data(base)
