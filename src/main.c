#include <stdint.h>
#include "gpio.h"
#include "rcc.h"

void GPIO_init(void){

    RCC->RCC_AHB1ENR |= 1;
}

int main(void){

    GPIO_init();

    GPIO_SetMode(PB7, GPIO_MODE_OUTPUT);

    for(;;){}
}
