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
    volatile uint32_t RCC_AHB3RSTR;
    volatile uint32_t res1;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t res2[2];
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    volatile uint32_t RCC_AHB3ENR;
    volatile uint32_t res3;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t res4[2];
}RCC_TypeDef;

//Adapt this to your Hardware
#define RCC_BASE_ADDR 0x40023800

//Define pointer to RCC struct
#define RCC ((RCC_TypeDef*) RCC_BASE_ADDR)

#endif 
