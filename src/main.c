#include <stdint.h>
#include "rcc.h"
#include "gpio.h"

void GPIO_init(void){

    RCC->RCC_AHB1ENR |= (1 << 1);
}

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){

    GPIO_init();

    GPIO_SetMode(PB7, GPIO_MODE_OUTPUT);

    while(1) {

        GPIO_WritePin(PB7, 1);
        wait_ms(100);
        GPIO_WritePin(PB7, 0);
        wait_ms(100);

    }
}
