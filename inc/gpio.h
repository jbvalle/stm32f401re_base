#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

/**
 *  @brief Set the GPIO MODE for a given Pin
 * `GPIO_MODE_INPUT  = 0x0`
 * `GPIO_MODE_OUTPUT = 0x1`
 * `GPIO_MODE_ALT    = 0x2`
 * `GPIO_MODE_ANALOG = 0x3`
 */
typedef enum GPIO_Mode{
    GPIO_MODE_INPUT  = 0x0,
    GPIO_MODE_OUTPUT = 0x1,
    GPIO_MODE_ALT    = 0x2,
    GPIO_MODE_ANALOG = 0x3
} GPIO_Mode;

/**
 * @brief Sets GPIO Output type
 * `GPIO_OTYPE_PP = 0x0`  // Push-pull
 * `GPIO_OTYPE_OD = 0x1`  // Open-drain
 */
typedef enum GPIO_OutputType{
    GPIO_OTYPE_PP = 0x0,  // Push-pull
    GPIO_OTYPE_OD = 0x1   // Open-drain
} GPIO_OutputType;

/**
 * @brief Sets GPIO Pullup Type
 * `GPIO_NOPULL = 0x0, `
 * `GPIO_PULLUP = 0x1, `
 * `GPIO_PULLDOWN = 0x2`
 */
typedef enum GPIO_Pull{
    GPIO_NOPULL = 0x0,
    GPIO_PULLUP = 0x1,
    GPIO_PULLDOWN = 0x2
} GPIO_Pull;

/**
 * @brief Portpin PAx, PBx, PCx, PDx, PEx, ...
 * `P<PORT><PIN>`
 */
typedef enum GPIO_PortPin{
    PA0  = 0x00, // Port A, Pin 0
    PA1  = 0x01, // Port A, Pin 1
    PA2  = 0x02, // Port A, Pin 2
    PA3  = 0x03, // Port A, Pin 3
    PA4  = 0x04, // Port A, Pin 4
    PA5  = 0x05, // Port A, Pin 5
    PA6  = 0x06, // Port A, Pin 6
    PA7  = 0x07, // Port A, Pin 7
    PA8  = 0x08, // Port A, Pin 8
    PA9  = 0x09, // Port A, Pin 9
    PA10 = 0x0A, // Port A, Pin 10
    PA11 = 0x0B, // Port A, Pin 11
    PA12 = 0x0C, // Port A, Pin 12
    PA13 = 0x0D, // Port A, Pin 13
    PA14 = 0x0E, // Port A, Pin 14
    PA15 = 0x0F, // Port A, Pin 15

    PB0  = 0x10, // Port B, Pin 0
    PB1  = 0x11, // Port B, Pin 1
    PB2  = 0x12, // Port B, Pin 2
    PB3  = 0x13, // Port B, Pin 3
    PB4  = 0x14, // Port B, Pin 4
    PB5  = 0x15, // Port B, Pin 5
    PB6  = 0x16, // Port B, Pin 6
    PB7  = 0x17, // Port B, Pin 7
    PB8  = 0x18, // Port B, Pin 8
    PB9  = 0x19, // Port B, Pin 9
    PB10 = 0x1A, // Port B, Pin 10
    PB11 = 0x1B, // Port B, Pin 11
    PB12 = 0x1C, // Port B, Pin 12
    PB13 = 0x1D, // Port B, Pin 13
    PB14 = 0x1E, // Port B, Pin 14
    PB15 = 0x1F, // Port B, Pin 15

    PC0  = 0x20, // Port C, Pin 0
    PC1  = 0x21, // Port C, Pin 1
    PC2  = 0x22, // Port C, Pin 2
    PC3  = 0x23, // Port C, Pin 3
    PC4  = 0x24, // Port C, Pin 4
    PC5  = 0x25, // Port C, Pin 5
    PC6  = 0x26, // Port C, Pin 6
    PC7  = 0x27, // Port C, Pin 7
    PC8  = 0x28, // Port C, Pin 8
    PC9  = 0x29, // Port C, Pin 9
    PC10 = 0x2A, // Port C, Pin 10
    PC11 = 0x2B, // Port C, Pin 11
    PC12 = 0x2C, // Port C, Pin 12
    PC13 = 0x2D, // Port C, Pin 13
    PC14 = 0x2E, // Port C, Pin 14
    PC15 = 0x2F, // Port C, Pin 15

    PD0  = 0x30, // Port D, Pin 0
    PD1  = 0x31, // Port D, Pin 1
    PD2  = 0x32, // Port D, Pin 2
    PD3  = 0x33, // Port D, Pin 3
    PD4  = 0x34, // Port D, Pin 4
    PD5  = 0x35, // Port D, Pin 5
    PD6  = 0x36, // Port D, Pin 6
    PD7  = 0x37, // Port D, Pin 7
    PD8  = 0x38, // Port D, Pin 8
    PD9  = 0x39, // Port D, Pin 9
    PD10 = 0x3A, // Port D, Pin 10
    PD11 = 0x3B, // Port D, Pin 11
    PD12 = 0x3C, // Port D, Pin 12
    PD13 = 0x3D, // Port D, Pin 13
    PD14 = 0x3E, // Port D, Pin 14
    PD15 = 0x3F, // Port D, Pin 15

    PE0  = 0x40, // Port E, Pin 0
    PE1  = 0x41, // Port E, Pin 1
    PE2  = 0x42, // Port E, Pin 2
    PE3  = 0x43, // Port E, Pin 3
    PE4  = 0x44, // Port E, Pin 4
    PE5  = 0x45, // Port E, Pin 5
    PE6  = 0x46, // Port E, Pin 6
    PE7  = 0x47, // Port E, Pin 7
    PE8  = 0x48, // Port E, Pin 8
    PE9  = 0x49, // Port E, Pin 9
    PE10 = 0x4A, // Port E, Pin 10
    PE11 = 0x4B, // Port E, Pin 11
    PE12 = 0x4C, // Port E, Pin 12
    PE13 = 0x4D, // Port E, Pin 13
    PE14 = 0x4E, // Port E, Pin 14
    PE15 = 0x4F, // Port E, Pin 15
    // Continue with other ports if needed
} GPIO_PortPin;

/**
 * @brief GPIO Peripheral Type with register fields
 */
typedef struct GPIO_TypeDef{
   volatile uint32_t GPIOx_MODER; 
   volatile uint32_t GPIOx_OTYPER; 
   volatile uint32_t GPIOx_OSPEEDR; 
   volatile uint32_t GPIOx_PUPDR; 
   volatile uint32_t GPIOx_IDR; 
   volatile uint32_t GPIOx_ODR; 
   volatile uint32_t GPIOx_BSRR; 
   volatile uint32_t GPIOx_LCKR; 
   volatile uint32_t GPIOx_AFRL; 
   volatile uint32_t GPIOx_AFRH; 
}GPIO_TypeDef;

#define GPIO_A ((GPIO_TypeDef *) 0x40020000)
#define GPIO_B ((GPIO_TypeDef *) 0x40020400)
#define GPIO_C ((GPIO_TypeDef *) 0x40020800)
#define GPIO_D ((GPIO_TypeDef *) 0x40020C00)
#define GPIO_E ((GPIO_TypeDef *) 0x40021000)

/**
 * Struct pointing to a GPIO TypeDef type
 */
typedef struct GPIO_PortInfo{
    GPIO_TypeDef *port;    
}GPIO_PortInfo;

#define GPIO_PORT_COUNT 5

/**
 * Array of GPIO_TypeDef Pointers
 *  `GPIO_A`
 *  `GPIO_B`
 *  `GPIO_C`
 *  `GPIO_D`
 *  `GPIO_E`
 */
static GPIO_PortInfo gpio_ports[GPIO_PORT_COUNT] = {
    {GPIO_A},
    {GPIO_B},
    {GPIO_C},
    {GPIO_D},
    {GPIO_E},
};

// Function prototypes
void GPIO_init(void);
void GPIO_SetMode(GPIO_PortPin portPin, GPIO_Mode mode);
void GPIO_SetOutputType(GPIO_PortPin portPin, GPIO_OutputType type);
void GPIO_SetPull(GPIO_PortPin portPin, GPIO_Pull pull);
void GPIO_WritePin(GPIO_PortPin portPin, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_PortPin portPin);

#endif

