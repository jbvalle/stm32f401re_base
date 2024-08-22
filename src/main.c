#include <stdint.h>
#include "rcc.h"
#include "gpio.h"

void GPIO_init(){

    //Enable GPIOA
    RCC->RCC_AHB1ENR |= 1;
}

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){

    GPIO_init();

    GPIO_SetMode(PA5, GPIO_MODE_OUTPUT);

    while(1) {

        GPIO_WritePin(PA5, 1);
        wait_ms(100);
        GPIO_WritePin(PA5, 0);
        wait_ms(100);

    }
}
