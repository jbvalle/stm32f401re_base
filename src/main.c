#include <stdint.h>
#include "gpio.h"


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}



int main(void){

    while(1){

    }
}
