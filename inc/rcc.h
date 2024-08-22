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
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    //adapt from here    
}RCC_TypeDef;

//Adapt this to your Hardware
#define RCC_BASE_ADDR 0x40023800

//Define pointer to RCC struct
#define RCC ((RCC_TypeDef*) RCC_BASE_ADDR)

#endif 
