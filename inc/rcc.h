#ifndef RCC_H
#define RCC_H
#include <stdint.h>

// Function Prototypes
void RCC_init(void);
void RCC_EnableClock(uint32_t peripheral);
void RCC_DisableClock(uint32_t peripheral);
void RCC_ResetPeripheral(uint32_t peripheral);
void RCC_SetSysClk(uint32_t clock_source, uint32_t pll_multiplier);

typedef struct{
    
}RCC_TypeDef;

//Adapt this to your Hardware
#define RCC_BASE_ADDR 0x40023800

//Define pointer to RCC struct
#define RCC ((RCC_TypeDef))

#endif 
