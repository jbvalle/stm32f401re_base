#include "interrupt.h"
#include <stdint.h>
#include "gpio.h"
#include "rcc.h"


/**
 *  @brief Enable all interrupts
 */
void NVIC_globalEnableIRQ(void){
    __asm volatile("CPSIE i":::"memory");
}

/**
 *  @brief Disable all interrupts
 */
void NVIC_globalDisableIRQ(void){
    __asm volatile("CPSID i":::"memory");
}

void enableGpioInt(GPIO_PortPin portPin, GPIO_EdgeDetection edgeDetection, void (*GPIO_IntCallbackFunc)(void)){

    NVIC_globalDisableIRQ();

    uint8_t pinIndex = portPin & 0x0F;
    uint8_t portIndex = (portPin >> 4) & 0x0F;

    tasks.fct = GPIO_IntCallbackFunc;
    tasks.intLine = pinIndex;
    //Set Pin to INPUT
    GPIO_SetMode(portPin, GPIO_MODE_INPUT);

    // enable Clk SYSCFG for EXTI Multiplexer
    RCC->RCC_APB2ENR |= (1 << 14);

    //Reset EXTIx Multiplexer
    SYSCFG->SYSCFG_EXTICRx[pinIndex >> 2] &= ~(0xF << ((pinIndex % 4) * 4));
    //Set EXTIx Multiplexer to portIndex
    SYSCFG->SYSCFG_EXTICRx[pinIndex >> 2] |=  (portIndex << ((pinIndex % 4) * 4));
    
    //Set Edge Trigger detection
    (edgeDetection == FALLING_EDGE) ? 
        (EXTI->EXTI_FTSR |= (1 << pinIndex)) : (EXTI->EXTI_RTSR |= (1 << pinIndex));

    //Enable INT to EXTI Line
    EXTI->EXTI_IMR |= (1 << pinIndex);

    switch (pinIndex) {
        case 0:
            NVIC->NVIC_ISER[0] = EXTI0_handler_IRQn % 32;
            break;
        case 1:
            NVIC->NVIC_ISER[0] = EXTI1_handler_IRQn % 32;
            break;
        case 2:
            NVIC->NVIC_ISER[0] = EXTI2_handler_IRQn % 32;
            break;
        case 3:
            NVIC->NVIC_ISER[0] = EXTI3_handler_IRQn % 32;
            break;
        case 4:
            NVIC->NVIC_ISER[0] = EXTI4_handler_IRQn % 32;
            break;
        case 5 ... 9:
            NVIC->NVIC_ISER[0] = EXTI9_5_handler_IRQn % 32;
            break;
        case 10 ... 15:
            NVIC->NVIC_ISER[1] |= (1 << EXTI15_10_handler_IRQn % 32);
            break;
    }

    NVIC_globalEnableIRQ();
}
