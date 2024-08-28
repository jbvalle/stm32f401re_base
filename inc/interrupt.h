#ifndef INTERRUPT_H
#define INTERRUPT_H
#include <stdint.h>
#include "gpio.h"

#define tasksNum 4

typedef struct TASK_TypeDef{
   uint32_t intLine;
   void (*fct)(void);
}TASK_TypeDef;

extern TASK_TypeDef tasks;



typedef struct NVIC_TypeDef{
    volatile uint32_t NVIC_ISER[8];
    volatile uint32_t NVIC_ICER[8];
    volatile uint32_t NVIC_ISPR[8];
    volatile uint32_t NVIC_ICPR[8];
    volatile uint32_t NVIC_IABR[8];
    volatile uint32_t NVIC_IPR[8];
    volatile uint32_t NVIC_STIR;
}NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef*) 0xE000E100)

void NVIC_globalEnableIRQ(void);
void NVIC_globalDisableIRQ(void);

/**
 * @brief IRQ Numbers from stm32f401re reference manual
 */
typedef enum IRQn_STM32F401re{
    WWDG_handler_IRQn = 0,          // Window Watchdog interrupt
    EXTI16_PVD_handler_IRQn = 1,    // PVD through EXTI Line detection interrupt
    EXTI21_TAMP_STAMP_handler_IRQn = 2, // Tamper and TimeStamp interrupts
    EXTI22_RTC_WKUP_handler_IRQn = 3,   // RTC Wakeup interrupt through EXTI Line
    FLASH_handler_IRQn = 4,         // Flash global interrupt
    RCC_handler_IRQn = 5,           // RCC global interrupt
    EXTI0_handler_IRQn = 6,         // EXTI Line0 interrupt
    EXTI1_handler_IRQn = 7,         // EXTI Line1 interrupt
    EXTI2_handler_IRQn = 8,         // EXTI Line2 interrupt
    EXTI3_handler_IRQn = 9,         // EXTI Line3 interrupt
    EXTI4_handler_IRQn = 10,        // EXTI Line4 interrupt
    DMA1_Stream0_handler_IRQn = 11, // DMA1 Stream 0 global interrupt
    DMA1_Stream1_handler_IRQn = 12, // DMA1 Stream 1 global interrupt
    DMA1_Stream2_handler_IRQn = 13, // DMA1 Stream 2 global interrupt
    DMA1_Stream3_handler_IRQn = 14, // DMA1 Stream 3 global interrupt
    DMA1_Stream4_handler_IRQn = 15, // DMA1 Stream 4 global interrupt
    DMA1_Stream5_handler_IRQn = 16, // DMA1 Stream 5 global interrupt
    DMA1_Stream6_handler_IRQn = 17, // DMA1 Stream 6 global interrupt
    ADC_handler_IRQn = 18,          // ADC1 global interrupt
    EXTI9_5_handler_IRQn = 23,      // External lines [9:5] interrupt
    TIM1_BRK_TIM9_handler_IRQn = 24,// TIM1 Break and TIM9 interrupts
    TIM1_UP_TIM10_handler_IRQn = 25,// TIM1 Update and TIM10 interrupts
    TIM1_TRG_COM_TIM11_handler_IRQn = 26, // TIM1 Trigger and TIM11 interrupts
    TIM1_CC_handler_IRQn = 27,      // TIM1 Capture Compare interrupt
    TIM2_handler_IRQn = 28,         // TIM2 global interrupt
    TIM3_handler_IRQn = 29,         // TIM3 global interrupt
    TIM4_handler_IRQn = 30,         // TIM4 global interrupt
    I2C1_EV_handler_IRQn = 31,      // I2C1 event interrupt
    I2C1_ER_handler_IRQn = 32,      // I2C1 error interrupt
    I2C2_EV_handler_IRQn = 33,      // I2C2 event interrupt
    I2C2_ER_handler_IRQn = 34,      // I2C2 error interrupt
    SPI1_handler_IRQn = 35,         // SPI1 global interrupt
    SPI2_handler_IRQn = 36,         // SPI2 global interrupt
    USART1_handler_IRQn = 37,       // USART1 global interrupt
    USART2_handler_IRQn = 38,       // USART2 global interrupt
    EXTI15_10_handler_IRQn = 40,    // External lines [15:10] interrupt
    EXTI17_RTC_Alarm_handler_IRQn = 41, // RTC Alarm through EXTI Line interrupt
    EXTI18_OTG_FS_WKUP_handler_IRQn = 42, // USB OTG FS Wakeup through EXTI Line
    DMA1_Stream7_handler_IRQn = 47, // DMA1 Stream 7 global interrupt
    SDIO_handler_IRQn = 49,         // SDIO global interrupt
    TIM5_handler_IRQn = 50,         // TIM5 global interrupt
    SPI3_handler_IRQn = 51,         // SPI3 global interrupt
    DMA2_Stream0_handler_IRQn = 56, // DMA2 Stream 0 global interrupt
    DMA2_Stream1_handler_IRQn = 57, // DMA2 Stream 1 global interrupt
    DMA2_Stream2_handler_IRQn = 58, // DMA2 Stream 2 global interrupt
    DMA2_Stream3_handler_IRQn = 59, // DMA2 Stream 3 global interrupt
    DMA2_Stream4_handler_IRQn = 60, // DMA2 Stream 4 global interrupt
    OTG_FS_handler_IRQn = 67,       // USB OTG FS global interrupt
    DMA2_Stream5_handler_IRQn = 68, // DMA2 Stream 5 global interrupt
    DMA2_Stream6_handler_IRQn = 69, // DMA2 Stream 6 global interrupt
    DMA2_Stream7_handler_IRQn = 70, // DMA2 Stream 7 global interrupt
    USART6_handler_IRQn = 71,       // USART6 global interrupt
    I2C3_EV_handler_IRQn = 72,      // I2C3 event interrupt
    I2C3_ER_handler_IRQn = 73,      // I2C3 error interrupt
    FPU_handler_IRQn = 81,          // Floating point unit interrupt
    SPI4_handler_IRQn = 84,         // SPI4 global interrupt
} IRQn_STM32F401re;

/****************************************/
/***** GPIO Specific interrupt stuff ****/
/****************************************/

/**
 * @brief The system configuration controller is mainly used to remap the memory accessible in the code area and manage the external interrupt line connection to the GPIOs.
 */
typedef struct SYSCFG_TypeDef{
   volatile uint32_t SYSCFG_MEMRMP; 
   volatile uint32_t SYSCFG_PMC; 
   volatile uint32_t SYSCFG_EXTICRx[4];
   volatile uint32_t res1[2]; 
   volatile uint32_t SYSCFG_CMPCR; 
}SYSCFG_TypeDef;

#define SYSCFG ((SYSCFG_TypeDef *) 0x40013800) 

typedef struct EXTI_TypeDef{
    volatile uint32_t EXTI_IMR;
    volatile uint32_t EXTI_EMR;
    volatile uint32_t EXTI_RTSR;
    volatile uint32_t EXTI_FTSR;
    volatile uint32_t EXTI_SWIER;
    volatile uint32_t EXTI_PR;
}EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef*) 0x40013C00)

/**
 *  @brief Set the Edge Detection for GPIO Interrupt
 *  FALLING_EDGE = 0x0,
 *  RISING_EDGE = 0x1,
 */
typedef enum GPIO_EdgeDetection{
    FALLING_EDGE = 0x0,
    RISING_EDGE = 0x1,
}GPIO_EdgeDetection;

void enableGpioInt(GPIO_PortPin portPin, GPIO_EdgeDetection edgeDetection, void (*GPIO_IntCallbackFunc)(void));

#endif
