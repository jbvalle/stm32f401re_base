#include <stdint.h>
#include "gpio.h"


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}

typedef enum int_state{
    none  = 0x0,
    exti1 = 0x1,
    exti2 = 0x2,
    exti3 = 0x3,
    exti4 = 0x4,
}int_state;


/**
 * @brief SYSCFG Peripheral Type with register fields
 */
typedef struct{
   volatile uint32_t SYSCFG_MEMRMP; 
   volatile uint32_t SYSCFG_PMC; 
   volatile uint32_t SYSCFG_EXTICRx[4];
   volatile uint32_t res1[2]; 
   volatile uint32_t SYSCFG_CMPCR; 
}SYSCFG_TypeDef;

int main(void){


    volatile uint8_t var = 1000;
    volatile int_state state = none;

    switch (var) {
        case 0 ... 3:
            state = exti1; break;
        case 4 ... 7:
            state = exti2; break;
        case 8 ... 11:
            state = exti3; break;
        case 12 ... 15:
            state = exti4; break;
        default:
            state = none; break;
    }

    GPIO_SetMode(PA5, GPIO_MODE_OUTPUT);

    while(1) {

        GPIO_WritePin(PA5, 1);
        wait_ms(100);
        GPIO_WritePin(PA5, 0);
        wait_ms(100);

    }
}
