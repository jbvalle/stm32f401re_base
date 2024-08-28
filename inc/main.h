#ifndef MAIN_H
#define MAIN_H
#include "stdint.h"
typedef struct TASK_TypeDef{
   uint32_t intLine;
   void (*fct)(void);
}TASK_TypeDef;

extern TASK_TypeDef tasks;

typedef struct EXTI_TypeDef{
    volatile uint32_t EXTI_IMR;
    volatile uint32_t EXTI_EMR;
    volatile uint32_t EXTI_RTSR;
    volatile uint32_t EXTI_FTSR;
    volatile uint32_t EXTI_SWIER;
    volatile uint32_t EXTI_PR;
}EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef*) 0x40013C00)
#endif 
