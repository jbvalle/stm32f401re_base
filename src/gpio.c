#include "gpio.h"
#include "rcc.h"
#include <stdint.h>

// Function prototypes
void GPIO_SetOutputType(GPIO_PortPin portPin, GPIO_OutputType type);
void GPIO_SetPull(GPIO_PortPin portPin, GPIO_Pull pull);
void GPIO_WritePin(GPIO_PortPin portPin, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_PortPin portPin);
void GPIO_init(void);



/**
 * @brief Sets the GPIO mode for a given pin.
 * 
 * This function configures the specified GPIO pin with the desired mode
 * (e.g., input, output, alternate function, or analog).
 * 
 * @param portPin Specifies the GPIO port and pin, encoded as `P<PORT><PIN>`
 *                (e.g., PA0, PB3, etc.).
 * 
 * @param mode    The mode to set for the pin, which can be one of the following:
 *                - `GPIO_MODE_INPUT`  : Input mode
 *                - `GPIO_MODE_OUTPUT` : Output mode
 *                - `GPIO_MODE_ALT`    : Alternate function mode
 *                - `GPIO_MODE_ANALOG` : Analog mode
 *
 * @note Ensure that the selected pin is valid and that the mode matches the
 *       desired configuration.
 */
void GPIO_SetMode(GPIO_PortPin portPin, GPIO_Mode mode){

    uint8_t pinIndex = portPin & 0x0F;
    uint8_t portIndex = (portPin >> 4) & 0x0F;

    // Enable Clock to GPIO<portIndex>
    RCC->RCC_AHB1ENR |= (1 << portIndex);

    if(portIndex < GPIO_PORT_COUNT){
        GPIO_TypeDef *port = gpio_ports[portIndex].port;
        port->GPIOx_MODER &= ~(3 << (pinIndex * 2));
        port->GPIOx_MODER |=  (mode << (pinIndex * 2));
    }

}


/**
 * @brief Write 1 or 0 to a GPIO Pin
 * 
 * @param portPin Specifies the GPIO port and pin, encoded as `P<PORT><PIN>`
 *                (e.g., PA0, PB3, etc.).
 * 
 * @param value   Value to be set to GPIO Pin
 *                `1` -> HIGH
 *                `0` -> LOW 
 * @note
 *     
 */
void GPIO_WritePin(GPIO_PortPin portPin, uint8_t value){

    uint8_t pinIndex = portPin & 0x0F;
    uint8_t portIndex = (portPin >> 4) & 0x0F;
    
    if(portIndex < GPIO_PORT_COUNT){
        GPIO_TypeDef *port = gpio_ports[portIndex].port;

        (value == 1) ?
        (port->GPIOx_ODR &= ~(1 << pinIndex)) : (port->GPIOx_ODR |= (1 << pinIndex));
    }
    
}

