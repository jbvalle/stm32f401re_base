#include <stdint.h>
#include "gpio.h"
#include "rcc.h"

void GPIO_init(void){

    RCC->RCC_AHB1ENR |= 1;

    GPIO_B->GPIOx_MODER &= ~(3 << (2 * 14));
    GPIO_B->GPIOx_MODER |=  (1 << (2 * 14));

    GPIO_B->GPIOx_ODR |= (1 << 14);
}


int main(void){

    GPIO_init();

    GPIO_SetMode(PB14, GPIO_MODE_OUTPUT);

    GPIO_WritePin(PB14, 1);

    while(1){
    }
}
