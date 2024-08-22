#include "gpio.h"
#include <stdint.h>

// Function prototypes
void GPIO_SetOutputType(GPIO_PortPin portPin, GPIO_OutputType type);
void GPIO_SetPull(GPIO_PortPin portPin, GPIO_Pull pull);
void GPIO_WritePin(GPIO_PortPin portPin, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_PortPin portPin);


void GPIO_SetMode(GPIO_PortPin portPin, GPIO_Mode mode){

    uint8_t pinIndex = portPin & 0x0F;
    uint8_t portIndex = (portPin >> 4) & 0x0F;

    if(portIndex < GPIO_PORT_COUNT){
        GPIO_TypeDef *port = gpio_ports[portIndex].port;
        port->GPIOx_MODER &= ~(3 << (pinIndex * 2));
        port->GPIOx_MODER |=  (mode << (pinIndex * 2));
    }

}

void GPIO_WritePin(GPIO_PortPin portPin, uint8_t value){

    uint8_t pinIndex = portPin & 0x0F;
    uint8_t portIndex = (portPin >> 4) & 0x0F;
    
    if(portIndex < GPIO_PORT_COUNT){
        GPIO_TypeDef *port = gpio_ports[portIndex].port;

        (value == 1) ?
        (port->GPIOx_ODR &= ~(1 << pinIndex)) : (port->GPIOx_ODR |= (1 << pinIndex));
    }
    
}
