#include <stdint.h>
#include "gpio.h"


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){


    GPIO_SetMode(PB7, GPIO_MODE_OUTPUT);

    while(1) {

        GPIO_WritePin(PB7, 1);
        wait_ms(100);
        GPIO_WritePin(PB7, 0);
        wait_ms(100);

    }
}
