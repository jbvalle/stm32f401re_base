#include <stdint.h>
#include "startup.h"
#include "isr.h"

__attribute__ ((section(".isr_vector")))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_end_stack_memory),
    reset_handler,
    NMI_handler,
    HardFault_handler,
    MemManage_handler,
    BusFault_handler,
    UsuageFault_handler,
    0,
    0,
    0,
    0,
    SVCall_handler,
    DebugMonitor_handler,
    0,
    PendSV_handler,
    Systick_handler,
    WWDG_handler,
    EXTI16_PVD__handler,
    EXTI21_TAMP_STAMP_handler,
    EXTI22_RTC_WKUP_handler,
    FLASH_handler,
    RCC_handler,
    EXTI0_handler,
    EXTI1_handler,
    EXTI2_handler,
    EXTI3_handler,
    EXTI4_handler,
    DMA1_Stream0_handler,
    DMA1_Stream1_handler,
    DMA1_Stream2_handler,
    DMA1_Stream3_handler,
    DMA1_Stream4_handler,
    DMA1_Stream5_handler,
    DMA1_Stream6_handler,
    ADC_handler,
    0,
    0,
    0,
    0,
    EXTI9_5__handler,
    TIM1_BRK_TIM9_handler,
    TIM1_UP_TIM10_handler,
    TIM1_TRG_COM_TIM11_handler,
    TIM1_CC_handler,
    TIM2_handler,
    TIM3_handler,
    TIM4_handler,
    I2C1_EV_handler,
    I2C1_ER_handler,
    I2C2_EV_handler,
    I2C2_ER_handler,
    SPI1_handler,
    SPI2_handler,
    USART1_handler,
    USART2_handler,
    0,
    EXTI15_10_handler,
    EXTI17_RTC_Alarm_handler,
    EXTI18_OTG_FS_WKUP_handler,
    0,
    0,
    0,
    0,
    DMA1_Stream7_handler,
    0,
    SDIO_handler,
    TIM5_handler,
    SPI3_handler,
    0,
    0,
    0,
    0,
    DMA2_Stream0_handler,
    DMA2_Stream1_handler,
    DMA2_Stream2_handler,
    DMA2_Stream3_handler,
    DMA2_Stream4_handler,
    0,
    0,
    0,
    0,
    0,
    0,
    OTG_FS_handler,
    DMA2_Stream5_handler,
    DMA2_Stream6_handler,
    DMA2_Stream7_handler,
    USART6_handler,
    I2C3_EV_handler,
    I2C3_ER_handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    FPU_handler,
    0,
    0,
    SPI4_handler,
};

void reset_handler(void){
    // Copy config data from flash to SRAM
    //uint32_t *config_data_src_addr = (uint32_t *)&_start_config_data_section_init;
    //uint32_t *config_data_dst_addr = (uint32_t *)&_start_config_data_section_rt;

    //for(uint32_t *ptr = (uint32_t*)config_data_dst_addr; ptr < &_end_config_data_section_rt;){

    //    *ptr++ = *config_data_src_addr++;
    //}

    // Copy data value to stack memory
    uint32_t *data_src_addr = (uint32_t *)&_start_data_section_init;
    uint32_t *data_dst_addr = (uint32_t *)&_start_data_section_rt;

    for(uint32_t *ptr = (uint32_t *)data_dst_addr; ptr < &_end_data_section_rt;){
        
        *ptr++ = *data_src_addr++;
    }

    for(uint32_t *ptr = (uint32_t *)&_start_bss_section; ptr < &_end_bss_section;){
        *ptr++ = 0;
    }

    main();
}




