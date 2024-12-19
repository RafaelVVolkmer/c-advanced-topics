// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>

typedef enum msgType
{
    NACK_MSG        = 0u,
    ACK_MSG         = 1u,
    CFG_MSG         = 2u,
    STATS_MSG       = 3u
} type_t;

typedef enum msgError
{
    NO_MEM          = 0u,
    ARG_INVAL       = 1u
} error_t;

typedef enum msgEnabled
{
    UART_DISABLE    = 0u,
    UART_ENABLE     = 1u
} enable_t;

typedef enum uartStopBit
{
    NO_STOP_BIT     = 0u,
    STOP_BIT        = 1u
} stopbit_t;

typedef enum uartStartBit
{
    NO_START_BIT    = 0u,
    START_BIT       = 1u
} startbit_t;

typedef enum uartParity
{
    EVEN_PARITY     = 0u,
    ODD_PARITY      = 1u,
    STICK_PARITY    = 2u
} parity_t;

typedef struct __attribute__((packed)) headerBuffer
{
    uint8_t     magic_number    : 8u;
    uint8_t     crc             : 8u;
    type_t      type            : 2u;
} header_t;

typedef struct __attribute__((packed)) statsBuffer
{
    header_t    header          : 18u;
    
    enable_t    enabled         : 1u;
    error_t     error           : 2u;
    char        data[64];
} stats_t;

typedef struct __attribute__((packed)) cfgBuffer
{
    header_t    header          : 18u;
    
    enable_t    enable          : 1u;
    stopbit_t   stop_bit        : 1u;
    startbit_t  start_bit       : 1u;
    parity_t    parity          : 2u;
    uint32_t    baud_rate       : 32u;
} cfg_t;
