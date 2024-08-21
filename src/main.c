#include <stdint.h>

volatile uint32_t g_var = 1000;

int main(void){

    volatile int a = 100;
    volatile int b = 100;
    volatile int c = a + b;

    for(;;){}
}
