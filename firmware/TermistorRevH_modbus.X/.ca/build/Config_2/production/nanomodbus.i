# 1 "nanomodbus.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/PIC16F1xxxx_DFP/1.15.191/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "nanomodbus.c" 2
# 27 "nanomodbus.c"
# 1 "./nanomodbus.h" 1
# 50 "./nanomodbus.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdbool.h" 1 3
# 51 "./nanomodbus.h" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 145 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3
# 52 "./nanomodbus.h" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\string.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\features.h" 1 3
# 11 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\string.h" 2 3
# 25 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 411 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 26 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\string.h" 2 3

void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);




char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 53 "./nanomodbus.h" 2
# 62 "./nanomodbus.h"
typedef enum nmbs_error {

    NMBS_ERROR_INVALID_UNIT_ID = -7,
    NMBS_ERROR_INVALID_TCP_MBAP = -6,
    NMBS_ERROR_CRC = -5,
    NMBS_ERROR_TRANSPORT = -4,
    NMBS_ERROR_TIMEOUT = -3,
    NMBS_ERROR_INVALID_RESPONSE = -2,
    NMBS_ERROR_INVALID_ARGUMENT = -1,
    NMBS_ERROR_NONE = 0,


    NMBS_EXCEPTION_ILLEGAL_FUNCTION = 1,
    NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS = 2,
    NMBS_EXCEPTION_ILLEGAL_DATA_VALUE = 3,
    NMBS_EXCEPTION_SERVER_DEVICE_FAILURE = 4,
} nmbs_error;
# 90 "./nanomodbus.h"
typedef uint8_t nmbs_bitfield[1];
# 112 "./nanomodbus.h"
typedef enum nmbs_transport {
    NMBS_TRANSPORT_RTU = 1,
    NMBS_TRANSPORT_TCP = 2,
} nmbs_transport;
# 137 "./nanomodbus.h"
typedef struct nmbs_platform_conf {
    nmbs_transport transport;
    int32_t (*read)(uint8_t* buf, uint16_t count, int32_t byte_timeout_ms,
                    void* arg);
    int32_t (*write)(const uint8_t* buf, uint16_t count, int32_t byte_timeout_ms,
                     void* arg);
    void* arg;
} nmbs_platform_conf;
# 155 "./nanomodbus.h"
typedef struct nmbs_callbacks {


    nmbs_error (*read_coils)(uint16_t address, uint16_t quantity, nmbs_bitfield coils_out, uint8_t unit_id, void* arg);
# 167 "./nanomodbus.h"
    nmbs_error (*read_holding_registers)(uint16_t address, uint16_t quantity, uint16_t* registers_out, uint8_t unit_id,
                                         void* arg);



    nmbs_error (*read_input_registers)(uint16_t address, uint16_t quantity, uint16_t* registers_out, uint8_t unit_id,
                                       void* arg);



    nmbs_error (*write_single_coil)(uint16_t address, _Bool value, uint8_t unit_id, void* arg);



    nmbs_error (*write_single_register)(uint16_t address, uint16_t value, uint8_t unit_id, void* arg);



    nmbs_error (*write_multiple_coils)(uint16_t address, uint16_t quantity, const nmbs_bitfield coils, uint8_t unit_id,
                                       void* arg);



    nmbs_error (*write_multiple_registers)(uint16_t address, uint16_t quantity, const uint16_t* registers,
                                           uint8_t unit_id, void* arg);
# 205 "./nanomodbus.h"
    char _nonempty;
} nmbs_callbacks;





typedef struct nmbs_t {
    struct {
        uint8_t buf[32];
        uint16_t buf_idx;

        uint8_t unit_id;
        uint8_t fc;
        uint16_t transaction_id;
        _Bool broadcast;
        _Bool ignored;
    } msg;

    nmbs_callbacks callbacks;

    int32_t byte_timeout_ms;
    int32_t read_timeout_ms;

    nmbs_platform_conf platform;

    uint8_t address_rtu;
    uint8_t dest_address_rtu;
    uint16_t current_tid;
} nmbs_t;




static const uint8_t NMBS_BROADCAST_ADDRESS = 0;
# 248 "./nanomodbus.h"
void nmbs_set_read_timeout(nmbs_t* nmbs, int32_t timeout_ms);





void nmbs_set_byte_timeout(nmbs_t* nmbs, int32_t timeout_ms);





void nmbs_set_platform_arg(nmbs_t* nmbs, void* arg);
# 271 "./nanomodbus.h"
nmbs_error nmbs_server_create(nmbs_t* nmbs, uint8_t address_rtu, const nmbs_platform_conf* platform_conf,
                              const nmbs_callbacks* callbacks);
# 281 "./nanomodbus.h"
nmbs_error nmbs_server_poll(nmbs_t* nmbs);
# 441 "./nanomodbus.h"
uint16_t nmbs_crc_calc(const uint8_t* data, uint32_t length);
# 28 "nanomodbus.c" 2
# 40 "nanomodbus.c"
static uint8_t get_1(nmbs_t* nmbs) {
    uint8_t result = nmbs->msg.buf[nmbs->msg.buf_idx];
    nmbs->msg.buf_idx++;
    return result;
}


static void put_1(nmbs_t* nmbs, uint8_t data) {
    nmbs->msg.buf[nmbs->msg.buf_idx] = data;
    nmbs->msg.buf_idx++;
}


static void discard_1(nmbs_t* nmbs) {
    nmbs->msg.buf_idx++;
}


static void discard_n(nmbs_t* nmbs, uint16_t n) {
    nmbs->msg.buf_idx += n;
}


static uint16_t get_2(nmbs_t* nmbs) {
    uint16_t result =
            ((uint16_t) nmbs->msg.buf[nmbs->msg.buf_idx]) << 8 | (uint16_t) nmbs->msg.buf[nmbs->msg.buf_idx + 1];
    nmbs->msg.buf_idx += 2;
    return result;
}


static void put_2(nmbs_t* nmbs, uint16_t data) {
    nmbs->msg.buf[nmbs->msg.buf_idx] = (uint8_t) ((data >> 8) & 0xFFU);
    nmbs->msg.buf[nmbs->msg.buf_idx + 1] = (uint8_t) data;
    nmbs->msg.buf_idx += 2;
}


static uint8_t* get_n(nmbs_t* nmbs, uint16_t n) {
    uint8_t* msg_buf_ptr = nmbs->msg.buf + nmbs->msg.buf_idx;
    nmbs->msg.buf_idx += n;
    return msg_buf_ptr;
}


static uint16_t* get_regs(nmbs_t* nmbs, uint16_t n) {
    uint16_t* msg_buf_ptr = (uint16_t*) (nmbs->msg.buf + nmbs->msg.buf_idx);
    nmbs->msg.buf_idx += n * 2;
    while (n--) {
        msg_buf_ptr[n] = (msg_buf_ptr[n] << 8) | ((msg_buf_ptr[n] >> 8) & 0xFF);
    }
    return msg_buf_ptr;
}


static void put_regs(nmbs_t* nmbs, const uint16_t* data, uint16_t n) {
    uint16_t* msg_buf_ptr = (uint16_t*) (nmbs->msg.buf + nmbs->msg.buf_idx);
    nmbs->msg.buf_idx += n * 2;
    while (n--) {
        msg_buf_ptr[n] = (data[n] << 8) | ((data[n] >> 8) & 0xFF);
    }
}


static void swap_regs(uint16_t* data, uint16_t n) {
    while (n--) {
        data[n] = (data[n] << 8) | ((data[n] >> 8) & 0xFF);
    }
}


static void msg_buf_reset(nmbs_t* nmbs) {
    nmbs->msg.buf_idx = 0;
}


static void msg_state_reset(nmbs_t* nmbs) {
    msg_buf_reset(nmbs);
    nmbs->msg.unit_id = 0;
    nmbs->msg.fc = 0;
    nmbs->msg.transaction_id = 0;
    nmbs->msg.broadcast = 0;
    nmbs->msg.ignored = 0;
}
# 143 "nanomodbus.c"
nmbs_error nmbs_create(nmbs_t* nmbs, const nmbs_platform_conf* platform_conf) {
    if (!nmbs)
        return NMBS_ERROR_INVALID_ARGUMENT;

    memset(nmbs, 0, sizeof(nmbs_t));

    nmbs->byte_timeout_ms = -1;
    nmbs->read_timeout_ms = -1;

    if (!platform_conf)
        return NMBS_ERROR_INVALID_ARGUMENT;

    if (platform_conf->transport != NMBS_TRANSPORT_RTU && platform_conf->transport != NMBS_TRANSPORT_TCP)
        return NMBS_ERROR_INVALID_ARGUMENT;

    if (!platform_conf->read || !platform_conf->write)
        return NMBS_ERROR_INVALID_ARGUMENT;

    nmbs->platform = *platform_conf;

    return NMBS_ERROR_NONE;
}


void nmbs_set_read_timeout(nmbs_t* nmbs, int32_t timeout_ms) {
    nmbs->read_timeout_ms = timeout_ms;
}


void nmbs_set_byte_timeout(nmbs_t* nmbs, int32_t timeout_ms) {
    nmbs->byte_timeout_ms = timeout_ms;
}


void nmbs_set_destination_rtu_address(nmbs_t* nmbs, uint8_t address) {
    nmbs->dest_address_rtu = address;
}


void nmbs_set_platform_arg(nmbs_t* nmbs, void* arg) {
    nmbs->platform.arg = arg;
}


uint16_t nmbs_crc_calc(const uint8_t* data, uint32_t length) {
    uint16_t crc = 0xFFFF;
    for (uint32_t i = 0; i < length; i++) {
        crc ^= (uint16_t) data[i];
        for (int j = 8; j != 0; j--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
                crc >>= 1;
        }
    }

    return (uint16_t) (crc << 8) | (uint16_t) (crc >> 8);
}


static nmbs_error recv(nmbs_t* nmbs, uint16_t count) {
    int32_t ret =
            nmbs->platform.read(nmbs->msg.buf + nmbs->msg.buf_idx, count, nmbs->byte_timeout_ms, nmbs->platform.arg);

    if (ret == count)
        return NMBS_ERROR_NONE;

    if (ret < count) {
        if (ret < 0)
            return NMBS_ERROR_TRANSPORT;

        return NMBS_ERROR_TIMEOUT;
    }

    return NMBS_ERROR_TRANSPORT;
}


static nmbs_error send(nmbs_t* nmbs, uint16_t count) {
    int32_t ret = nmbs->platform.write(nmbs->msg.buf, count, nmbs->byte_timeout_ms, nmbs->platform.arg);

    if (ret == count)
        return NMBS_ERROR_NONE;

    if (ret < count) {
        if (ret < 0)
            return NMBS_ERROR_TRANSPORT;

        return NMBS_ERROR_TIMEOUT;
    }

    return NMBS_ERROR_TRANSPORT;
}


static nmbs_error recv_msg_footer(nmbs_t* nmbs) {
    (void) (0);

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU) {
        uint16_t crc = nmbs_crc_calc(nmbs->msg.buf, nmbs->msg.buf_idx);

        nmbs_error err = recv(nmbs, 2);
        if (err != NMBS_ERROR_NONE)
            return err;

        uint16_t recv_crc = get_2(nmbs);

        if (recv_crc != crc)
            return NMBS_ERROR_CRC;
    }

    return NMBS_ERROR_NONE;
}


static nmbs_error recv_msg_header(nmbs_t* nmbs, _Bool* first_byte_received) {

    int32_t old_byte_timeout = nmbs->byte_timeout_ms;
    nmbs->byte_timeout_ms = nmbs->read_timeout_ms;

    msg_state_reset(nmbs);

    *first_byte_received = 0;

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU) {
        nmbs_error err = recv(nmbs, 1);

        nmbs->byte_timeout_ms = old_byte_timeout;

        if (err != NMBS_ERROR_NONE)
            return err;

        *first_byte_received = 1;

        nmbs->msg.unit_id = get_1(nmbs);

        err = recv(nmbs, 1);
        if (err != NMBS_ERROR_NONE)
            return err;

        nmbs->msg.fc = get_1(nmbs);
    }
    else if (nmbs->platform.transport == NMBS_TRANSPORT_TCP) {
        nmbs_error err = recv(nmbs, 1);

        nmbs->byte_timeout_ms = old_byte_timeout;

        if (err != NMBS_ERROR_NONE)
            return err;

        *first_byte_received = 1;


        discard_1(nmbs);

        err = recv(nmbs, 7);
        if (err != NMBS_ERROR_NONE)
            return err;


        msg_buf_reset(nmbs);

        nmbs->msg.transaction_id = get_2(nmbs);
        uint16_t protocol_id = get_2(nmbs);
        uint16_t length = get_2(nmbs);
        nmbs->msg.unit_id = get_1(nmbs);
        nmbs->msg.fc = get_1(nmbs);

        if (protocol_id != 0)
            return NMBS_ERROR_INVALID_TCP_MBAP;

        if (length > 255)
            return NMBS_ERROR_INVALID_TCP_MBAP;
    }

    return NMBS_ERROR_NONE;
}


static void put_msg_header(nmbs_t* nmbs, uint16_t data_length) {
    msg_buf_reset(nmbs);

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU) {
        put_1(nmbs, nmbs->msg.unit_id);
    }
    else if (nmbs->platform.transport == NMBS_TRANSPORT_TCP) {
        put_2(nmbs, nmbs->msg.transaction_id);
        put_2(nmbs, 0);
        put_2(nmbs, (uint16_t) (1 + 1 + data_length));
        put_1(nmbs, nmbs->msg.unit_id);
    }

    put_1(nmbs, nmbs->msg.fc);
}


static nmbs_error send_msg(nmbs_t* nmbs) {
    (void) (0);

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU) {
        uint16_t crc = nmbs_crc_calc(nmbs->msg.buf, nmbs->msg.buf_idx);
        put_2(nmbs, crc);
    }

    nmbs_error err = send(nmbs, nmbs->msg.buf_idx);

    return err;
}



static nmbs_error recv_req_header(nmbs_t* nmbs, _Bool* first_byte_received) {
    nmbs_error err = recv_msg_header(nmbs, first_byte_received);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU) {

        if (nmbs->msg.unit_id == NMBS_BROADCAST_ADDRESS)
            nmbs->msg.broadcast = 1;
        else if (nmbs->msg.unit_id != nmbs->address_rtu)
            nmbs->msg.ignored = 1;
        else
            nmbs->msg.ignored = 0;
    }

    return NMBS_ERROR_NONE;
}


static void put_res_header(nmbs_t* nmbs, uint16_t data_length) {
    put_msg_header(nmbs, data_length);
    (void) (0);
}


static nmbs_error send_exception_msg(nmbs_t* nmbs, uint8_t exception) {
    nmbs->msg.fc += 0x80;
    put_msg_header(nmbs, 1);
    put_1(nmbs, exception);

    (void) (0);

    return send_msg(nmbs);
}



static nmbs_error recv_res_header(nmbs_t* nmbs) {
    uint16_t req_transaction_id = nmbs->msg.transaction_id;
    uint8_t req_unit_id = nmbs->msg.unit_id;
    uint8_t req_fc = nmbs->msg.fc;

    _Bool first_byte_received;
    nmbs_error err = recv_msg_header(nmbs, &first_byte_received);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (nmbs->platform.transport == NMBS_TRANSPORT_TCP) {
        if (nmbs->msg.transaction_id != req_transaction_id)
            return NMBS_ERROR_INVALID_TCP_MBAP;
    }

    if (nmbs->platform.transport == NMBS_TRANSPORT_RTU && nmbs->msg.unit_id != req_unit_id)
        return NMBS_ERROR_INVALID_UNIT_ID;

    if (nmbs->msg.fc != req_fc) {
        if (nmbs->msg.fc - 0x80 == req_fc) {
            err = recv(nmbs, 1);
            if (err != NMBS_ERROR_NONE)
                return err;

            uint8_t exception = get_1(nmbs);
            err = recv_msg_footer(nmbs);
            if (err != NMBS_ERROR_NONE)
                return err;

            if (exception < 1 || exception > 4)
                return NMBS_ERROR_INVALID_RESPONSE;

            (void) (0);

            return (nmbs_error) exception;
        }

        return NMBS_ERROR_INVALID_RESPONSE;
    }

    (void) (0);

    return NMBS_ERROR_NONE;
}
# 458 "nanomodbus.c"
static nmbs_error recv_read_discrete_res(nmbs_t* nmbs, nmbs_bitfield values) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 1);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t coils_bytes = get_1(nmbs);
    (void) (0);

    err = recv(nmbs, coils_bytes);
    if (err != NMBS_ERROR_NONE)
        return err;

    (void) (0);
    for (int i = 0; i < coils_bytes; i++) {
        uint8_t coil = get_1(nmbs);
        if (values)
            values[i] = coil;
        (void) (0);
    }

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    return NMBS_ERROR_NONE;
}


static nmbs_error recv_read_registers_res(nmbs_t* nmbs, uint16_t quantity, uint16_t* registers) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 1);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t registers_bytes = get_1(nmbs);
    (void) (0);

    err = recv(nmbs, registers_bytes);
    if (err != NMBS_ERROR_NONE)
        return err;

    (void) (0);
    for (int i = 0; i < registers_bytes / 2; i++) {
        uint16_t reg = get_2(nmbs);
        if (registers)
            registers[i] = reg;
        (void) (0);
    }

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (registers_bytes != quantity * 2)
        return NMBS_ERROR_INVALID_RESPONSE;

    return NMBS_ERROR_NONE;
}


nmbs_error recv_write_single_coil_res(nmbs_t* nmbs, uint16_t address, uint16_t value_req) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address_res = get_2(nmbs);
    uint16_t value_res = get_2(nmbs);

    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (address_res != address)
        return NMBS_ERROR_INVALID_RESPONSE;

    if (value_res != value_req)
        return NMBS_ERROR_INVALID_RESPONSE;

    return NMBS_ERROR_NONE;
}


nmbs_error recv_write_single_register_res(nmbs_t* nmbs, uint16_t address, uint16_t value_req) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address_res = get_2(nmbs);
    uint16_t value_res = get_2(nmbs);
    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (address_res != address)
        return NMBS_ERROR_INVALID_RESPONSE;

    if (value_res != value_req)
        return NMBS_ERROR_INVALID_RESPONSE;

    return NMBS_ERROR_NONE;
}


nmbs_error recv_write_multiple_coils_res(nmbs_t* nmbs, uint16_t address, uint16_t quantity) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address_res = get_2(nmbs);
    uint16_t quantity_res = get_2(nmbs);
    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (address_res != address)
        return NMBS_ERROR_INVALID_RESPONSE;

    if (quantity_res != quantity)
        return NMBS_ERROR_INVALID_RESPONSE;

    return NMBS_ERROR_NONE;
}


nmbs_error recv_write_multiple_registers_res(nmbs_t* nmbs, uint16_t address, uint16_t quantity) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address_res = get_2(nmbs);
    uint16_t quantity_res = get_2(nmbs);
    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (address_res != address)
        return NMBS_ERROR_INVALID_RESPONSE;

    if (quantity_res != quantity)
        return NMBS_ERROR_INVALID_RESPONSE;

    return NMBS_ERROR_NONE;
}


nmbs_error recv_read_file_record_res(nmbs_t* nmbs, uint16_t* registers, uint16_t count) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 1);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t response_size = get_1(nmbs);

    err = recv(nmbs, response_size);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t subreq_data_size = get_1(nmbs) - 1;
    uint8_t subreq_reference_type = get_1(nmbs);
    uint16_t* subreq_record_data = (uint16_t*) get_n(nmbs, subreq_data_size);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (registers) {
        if (subreq_reference_type != 6)
            return NMBS_ERROR_INVALID_RESPONSE;

        if (count != (subreq_data_size / 2))
            return NMBS_ERROR_INVALID_RESPONSE;

        swap_regs(subreq_record_data, subreq_data_size / 2);
        memcpy(registers, subreq_record_data, subreq_data_size);
    }

    return NMBS_ERROR_NONE;
}


nmbs_error recv_write_file_record_res(nmbs_t* nmbs, uint16_t file_number, uint16_t record_number,
                                      const uint16_t* registers, uint16_t count) {
    nmbs_error err = recv_res_header(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    err = recv(nmbs, 1);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t response_size = get_1(nmbs);

    err = recv(nmbs, response_size);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint8_t subreq_reference_type = get_1(nmbs);
    uint16_t subreq_file_number = get_2(nmbs);
    uint16_t subreq_record_number = get_2(nmbs);
    uint16_t subreq_record_length = get_2(nmbs);
    (void) (0);

    uint16_t subreq_data_size = subreq_record_length * 2;
    uint16_t* subreq_record_data = (uint16_t*) get_n(nmbs, subreq_data_size);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (registers) {
        if (subreq_reference_type != 6)
            return NMBS_ERROR_INVALID_RESPONSE;

        if (subreq_file_number != file_number)
            return NMBS_ERROR_INVALID_RESPONSE;

        if (subreq_record_number != record_number)
            return NMBS_ERROR_INVALID_RESPONSE;

        if (subreq_record_length != count)
            return NMBS_ERROR_INVALID_RESPONSE;

        swap_regs(subreq_record_data, subreq_record_length);
        if (memcmp(registers, subreq_record_data, subreq_data_size) != 0)
            return NMBS_ERROR_INVALID_RESPONSE;
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_read_discrete(nmbs_t* nmbs,
                                       nmbs_error (*callback)(uint16_t, uint16_t, nmbs_bitfield, uint8_t, void*)) {
    nmbs_error err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t quantity = get_2(nmbs);

    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (quantity < 1 || quantity > 2000)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((uint32_t) address + (uint32_t) quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if (callback) {
            nmbs_bitfield bitfield = {0};
            err = callback(address, quantity, bitfield, nmbs->msg.unit_id, nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                uint8_t discrete_bytes = (quantity + 7) / 8;
                put_res_header(nmbs, 1 + discrete_bytes);

                put_1(nmbs, discrete_bytes);

                (void) (0);

                (void) (0);
                for (int i = 0; i < discrete_bytes; i++) {
                    put_1(nmbs, bitfield[i]);
                    (void) (0);
                }

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_read_discrete_res(nmbs, ((void*)0));
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_read_registers(nmbs_t* nmbs,
                                        nmbs_error (*callback)(uint16_t, uint16_t, uint16_t*, uint8_t, void*)) {
    nmbs_error err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t quantity = get_2(nmbs);

    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (quantity < 1 || quantity > 125)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((uint32_t) address + (uint32_t) quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if (callback) {
            uint16_t regs[32] = {0};
            err = callback(address, quantity, regs, nmbs->msg.unit_id, nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                uint8_t regs_bytes = quantity * 2;
                put_res_header(nmbs, 1 + regs_bytes);

                put_1(nmbs, regs_bytes);

                (void) (0);

                (void) (0);
                for (int i = 0; i < quantity; i++) {
                    put_2(nmbs, regs[i]);
                    (void) (0);
                }

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_read_registers_res(nmbs, quantity, ((void*)0));
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_read_coils(nmbs_t* nmbs) {
    return handle_read_discrete(nmbs, nmbs->callbacks.read_coils);
}
# 869 "nanomodbus.c"
static nmbs_error handle_read_holding_registers(nmbs_t* nmbs) {
    return handle_read_registers(nmbs, nmbs->callbacks.read_holding_registers);
}




static nmbs_error handle_read_input_registers(nmbs_t* nmbs) {
    return handle_read_registers(nmbs, nmbs->callbacks.read_input_registers);
}




static nmbs_error handle_write_single_coil(nmbs_t* nmbs) {
    nmbs_error err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t value = get_2(nmbs);

    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (nmbs->callbacks.write_single_coil) {
            if (value != 0 && value != 0xFF00)
                return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

            err = nmbs->callbacks.write_single_coil(address, value == 0 ? 0 : 1, nmbs->msg.unit_id,
                                                    nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                put_res_header(nmbs, 4);

                put_2(nmbs, address);
                put_2(nmbs, value);
                (void) (0);

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_write_single_coil_res(nmbs, address, value);
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_write_single_register(nmbs_t* nmbs) {
    nmbs_error err = recv(nmbs, 4);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t value = get_2(nmbs);

    (void) (0);

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (nmbs->callbacks.write_single_register) {
            err = nmbs->callbacks.write_single_register(address, value, nmbs->msg.unit_id, nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                put_res_header(nmbs, 4);

                put_2(nmbs, address);
                put_2(nmbs, value);
                (void) (0);

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_write_single_register_res(nmbs, address, value);
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_write_multiple_coils(nmbs_t* nmbs) {
    nmbs_error err = recv(nmbs, 5);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t quantity = get_2(nmbs);
    uint8_t coils_bytes = get_1(nmbs);

    (void) (0);

    err = recv(nmbs, coils_bytes);
    if (err != NMBS_ERROR_NONE)
        return err;

    nmbs_bitfield coils = {0};
    for (int i = 0; i < coils_bytes; i++) {
        coils[i] = get_1(nmbs);
        (void) (0);
    }

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (quantity < 1 || quantity > 0x07B0)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((uint32_t) address + (uint32_t) quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if (coils_bytes == 0)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((quantity + 7) / 8 != coils_bytes)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if (nmbs->callbacks.write_multiple_coils) {
            err = nmbs->callbacks.write_multiple_coils(address, quantity, coils, nmbs->msg.unit_id, nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                put_res_header(nmbs, 4);

                put_2(nmbs, address);
                put_2(nmbs, quantity);
                (void) (0);

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_write_multiple_coils_res(nmbs, address, quantity);
    }

    return NMBS_ERROR_NONE;
}




static nmbs_error handle_write_multiple_registers(nmbs_t* nmbs) {
    nmbs_error err = recv(nmbs, 5);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t address = get_2(nmbs);
    uint16_t quantity = get_2(nmbs);
    uint8_t registers_bytes = get_1(nmbs);

    (void) (0);

    err = recv(nmbs, registers_bytes);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t registers[32];
    for (int i = 0; i < registers_bytes / 2; i++) {
        registers[i] = get_2(nmbs);
        (void) (0);
    }

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (quantity < 1 || quantity > 0x007B)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((uint32_t) address + (uint32_t) quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if (registers_bytes == 0)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if (registers_bytes != quantity * 2)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if (nmbs->callbacks.write_multiple_registers) {
            err = nmbs->callbacks.write_multiple_registers(address, quantity, registers, nmbs->msg.unit_id,
                                                           nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            if (!nmbs->msg.broadcast) {
                put_res_header(nmbs, 4);

                put_2(nmbs, address);
                put_2(nmbs, quantity);
                (void) (0);

                err = send_msg(nmbs);
                if (err != NMBS_ERROR_NONE)
                    return err;
            }
        }
        else {
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);
        }
    }
    else {
        return recv_write_multiple_registers_res(nmbs, address, quantity);
    }

    return NMBS_ERROR_NONE;
}
# 1346 "nanomodbus.c"
static nmbs_error handle_read_write_registers(nmbs_t* nmbs) {
    nmbs_error err = recv(nmbs, 9);
    if (err != NMBS_ERROR_NONE)
        return err;

    uint16_t read_address = get_2(nmbs);
    uint16_t read_quantity = get_2(nmbs);
    uint16_t write_address = get_2(nmbs);
    uint16_t write_quantity = get_2(nmbs);

    uint8_t byte_count_write = get_1(nmbs);

    (void) (0);


    err = recv(nmbs, byte_count_write);
    if (err != NMBS_ERROR_NONE)
        return err;


    uint16_t registers[32];



    for (int i = 0; i < byte_count_write / 2; i++) {
        registers[i] = get_2(nmbs);
        (void) (0);
    }

    err = recv_msg_footer(nmbs);
    if (err != NMBS_ERROR_NONE)
        return err;

    if (!nmbs->msg.ignored) {
        if (read_quantity < 1 || read_quantity > 0x007D)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if (write_quantity < 1 || write_quantity > 0x007B)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if (byte_count_write != write_quantity * 2)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_VALUE);

        if ((uint32_t) read_address + (uint32_t) read_quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if ((uint32_t) write_address + (uint32_t) write_quantity > ((uint32_t) 0xFFFF) + 1)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_DATA_ADDRESS);

        if (!nmbs->callbacks.write_multiple_registers || !nmbs->callbacks.read_holding_registers)
            return send_exception_msg(nmbs, NMBS_EXCEPTION_ILLEGAL_FUNCTION);

        err = nmbs->callbacks.write_multiple_registers(write_address, write_quantity, registers, nmbs->msg.unit_id,
                                                       nmbs->platform.arg);
        if (err != NMBS_ERROR_NONE) {
            if (((err) > 0 && (err) < 5))
                return send_exception_msg(nmbs, err);

            return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
        }

        if (!nmbs->msg.broadcast) {

            uint16_t regs[32];



            err = nmbs->callbacks.read_holding_registers(read_address, read_quantity, regs, nmbs->msg.unit_id,
                                                         nmbs->platform.arg);
            if (err != NMBS_ERROR_NONE) {
                if (((err) > 0 && (err) < 5))
                    return send_exception_msg(nmbs, err);

                return send_exception_msg(nmbs, NMBS_EXCEPTION_SERVER_DEVICE_FAILURE);
            }

            uint8_t regs_bytes = read_quantity * 2;
            put_res_header(nmbs, 1 + regs_bytes);

            put_1(nmbs, regs_bytes);

            (void) (0);

            (void) (0);
            for (int i = 0; i < read_quantity; i++) {
                put_2(nmbs, regs[i]);
                (void) (0);
            }

            err = send_msg(nmbs);
            if (err != NMBS_ERROR_NONE)
                return err;
        }
    }
    else {
        return recv_write_multiple_registers_res(nmbs, write_address, write_quantity);
    }

    return NMBS_ERROR_NONE;
}



static nmbs_error handle_req_fc(nmbs_t* nmbs) {
    (void) (0);

    nmbs_error err;
    switch (nmbs->msg.fc) {

        case 1:
            err = handle_read_coils(nmbs);
            break;
# 1467 "nanomodbus.c"
        case 3:
            err = handle_read_holding_registers(nmbs);
            break;



        case 4:
            err = handle_read_input_registers(nmbs);
            break;



        case 5:
            err = handle_write_single_coil(nmbs);
            break;



        case 6:
            err = handle_write_single_register(nmbs);
            break;



        case 15:
            err = handle_write_multiple_coils(nmbs);
            break;



        case 16:
            err = handle_write_multiple_registers(nmbs);
            break;
# 1515 "nanomodbus.c"
        case 23:
            err = handle_read_write_registers(nmbs);
            break;

        default:
            err = NMBS_EXCEPTION_ILLEGAL_FUNCTION;
    }

    return err;
}


nmbs_error nmbs_server_create(nmbs_t* nmbs, uint8_t address_rtu, const nmbs_platform_conf* platform_conf,
                              const nmbs_callbacks* callbacks) {
    if (platform_conf->transport == NMBS_TRANSPORT_RTU && address_rtu == 0)
        return NMBS_ERROR_INVALID_ARGUMENT;

    nmbs_error ret = nmbs_create(nmbs, platform_conf);
    if (ret != NMBS_ERROR_NONE)
        return ret;

    nmbs->address_rtu = address_rtu;
    nmbs->callbacks = *callbacks;

    return NMBS_ERROR_NONE;
}


nmbs_error nmbs_server_poll(nmbs_t* nmbs) {
    msg_state_reset(nmbs);

    _Bool first_byte_received = 0;
    nmbs_error err = recv_req_header(nmbs, &first_byte_received);
    if (err != NMBS_ERROR_NONE) {
        if (!first_byte_received && err == NMBS_ERROR_TIMEOUT)
            return NMBS_ERROR_NONE;

        return err;
    }
# 1566 "nanomodbus.c"
    err = handle_req_fc(nmbs);
    if (err != NMBS_ERROR_NONE && !((err) > 0 && (err) < 5)) {
        if (nmbs->platform.transport == NMBS_TRANSPORT_RTU && err != NMBS_ERROR_TIMEOUT && nmbs->msg.ignored) {

            nmbs->platform.read(nmbs->msg.buf, sizeof(nmbs->msg.buf), 0, nmbs->platform.arg);
        }

        return err;
    }

    return NMBS_ERROR_NONE;
}
