#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H
#include <stdint.h>

typedef struct CONFIG_BLOCK{
    volatile uint32_t param0;
    volatile uint32_t param1;
    volatile uint32_t param2;
    volatile uint32_t param3;
    volatile uint32_t param4;
    volatile uint32_t param5;
    volatile uint32_t param6;
}CONFIG_BLOCK;

#define CONFIG_BLOCK_BASE 0x20000000
#define PARAM_VAL ((CONFIG_BLOCK*) (CONFIG_BLOCK_BASE + 0x08))

#endif
