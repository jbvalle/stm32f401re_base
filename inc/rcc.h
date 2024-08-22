#ifndef RCC_H
#define RCC_H
#include <stdint.h>


/**
 * @brief RCC Typedef struct that holds the rcc fields
 */
typedef struct{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    volatile uint32_t res1[2];
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t res2[2];
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    //Adapt according to hardware
}RCC_TypeDef;

typedef enum{
    AHB1 = 0x0,
    AHB2 = 0x1,
    APB1 = 0x2,
    APB2 = 0x3
}RCC_Bridge;

//Adapt this to your Hardware
#define RCC_BASE_ADDR 0x40023800

//Define pointer to RCC struct
#define RCC ((RCC_TypeDef *) RCC_BASE_ADDR) 

// Function Prototypes
void RCC_init(void);
void RCC_EnableClock(RCC_Bridge bridge, uint32_t peripheral);
//void RCC_DisableClock(RCC_Bridge bridge, uint32_t peripheral);
//void RCC_ResetPeripheral(RCC_Bridge bridge, uint32_t peripheral);
//void RCC_SetSysClk(uint32_t clock_source, uint32_t pll_multiplier);

#endif 
