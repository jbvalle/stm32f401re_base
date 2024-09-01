#include <stdint.h>
#include "gpio.h"
#include "interrupt.h"
#include "config_data.h"


TASK_TypeDef tasks;

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}

void toggleLED(void){

    GPIO_WritePin(PA5, 1);
    wait_ms(300);
    GPIO_WritePin(PA5, 0);
    wait_ms(300);
    GPIO_WritePin(PA5, 1);
    wait_ms(300);
    GPIO_WritePin(PA5, 0);
    wait_ms(300);
    GPIO_WritePin(PA5, 1);
    wait_ms(300);
    GPIO_WritePin(PA5, 0);
    wait_ms(300);
}

uint32_t g_some_var_stuff = 1000;

int main(void){

    volatile uint32_t param0 = *((uint32_t*)PARAM_VAL);

    GPIO_SetMode(PA5, GPIO_MODE_OUTPUT);

    enableGpioInt(PC13, FALLING_EDGE, toggleLED);

    while(1);
}
