#include "isr.h"
#include "main.h"

void Default_handler(void){
    while(1);
}

void EXTI15_10_handler(void){
    tasks.fct();
    EXTI->EXTI_PR |= (1 << tasks.intLine);
}

void NMI_handler            (void)__attribute__((weak, alias("Default_handler")));
void HardFault_handler      (void)__attribute__((weak, alias("Default_handler")));
void MemManage_handler      (void)__attribute__((weak, alias("Default_handler")));
void BusFault_handler       (void)__attribute__((weak, alias("Default_handler")));
void UsuageFault_handler    (void)__attribute__((weak, alias("Default_handler")));
void SVCall_handler         (void)__attribute__((weak, alias("Default_handler")));
void DebugMonitor_handler   (void)__attribute__((weak, alias("Default_handler")));
void PendSV_handler         (void)__attribute__((weak, alias("Default_handler")));
void Systick_handler        (void)__attribute__((weak, alias("Default_handler")));
void WWDG_handler                 (void)__attribute__((weak, alias("Default_handler")));
void EXTI16_PVD__handler         (void)__attribute__((weak, alias("Default_handler")));
void EXTI21_TAMP_STAMP_handler   (void)__attribute__((weak, alias("Default_handler")));
void EXTI22_RTC_WKUP_handler     (void)__attribute__((weak, alias("Default_handler")));
void FLASH_handler                (void)__attribute__((weak, alias("Default_handler")));
void RCC_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI0_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI1_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI2_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI3_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI4_handler                (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream0_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream1_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream2_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream3_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream4_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream5_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream6_handler         (void)__attribute__((weak, alias("Default_handler")));
void ADC_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI9_5__handler             (void)__attribute__((weak, alias("Default_handler")));
void TIM1_BRK_TIM9_handler        (void)__attribute__((weak, alias("Default_handler")));
void TIM1_UP_TIM10_handler        (void)__attribute__((weak, alias("Default_handler")));
void TIM1_TRG_COM_TIM11_handler   (void)__attribute__((weak, alias("Default_handler")));
void TIM1_CC_handler              (void)__attribute__((weak, alias("Default_handler")));
void TIM2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM4_handler                 (void)__attribute__((weak, alias("Default_handler")));
void I2C1_EV_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C1_ER_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C2_EV_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C2_ER_handler              (void)__attribute__((weak, alias("Default_handler")));
void SPI1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void SPI2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void USART1_handler               (void)__attribute__((weak, alias("Default_handler")));
void USART2_handler               (void)__attribute__((weak, alias("Default_handler")));
//void EXTI15_10_handler            (void)__attribute__((weak, alias("Default_handler")));
void EXTI17_RTC_Alarm_handler     (void)__attribute__((weak, alias("Default_handler")));
void EXTI18_OTG_FS_WKUP_handler   (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream7_handler         (void)__attribute__((weak, alias("Default_handler")));
void SDIO_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM5_handler                 (void)__attribute__((weak, alias("Default_handler")));
void SPI3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream0_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream4_handler                 (void)__attribute__((weak, alias("Default_handler")));
void OTG_FS_handler                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream5_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream6_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream7_handler                 (void)__attribute__((weak, alias("Default_handler")));
void USART6_handler                        (void)__attribute__((weak, alias("Default_handler")));
void I2C3_EV_handler                      (void)__attribute__((weak, alias("Default_handler")));
void I2C3_ER_handler                      (void)__attribute__((weak, alias("Default_handler")));
void FPU_handler                          (void)__attribute__((weak, alias("Default_handler")));
void SPI4_handler                         (void)__attribute__((weak, alias("Default_handler")));


