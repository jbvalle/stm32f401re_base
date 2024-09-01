#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H
#include <stdint.h>

typedef struct CONFIG_BLOCK{
    volatile uint32_t param0;
    volatile uint32_t param1;
    volatile uint32_t param2;
    volatile uint32_t param3;
}CONFIG_BLOCK;

#define config_block ((CONFIG_BLOCK*) 0x20000000)
#endif
