#include <stdint.h>
#include "gpio.h"


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){


    GPIO_SetMode(PA5, GPIO_MODE_OUTPUT);

    while(1) {

        GPIO_WritePin(PA5, 1);
        wait_ms(100);
        GPIO_WritePin(PA5, 0);
        wait_ms(100);

    }
}
