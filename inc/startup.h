#ifndef STARTUP_H
#define STARTUP_H
#include <stdint.h>

extern uint32_t _end_stack_memory;
extern uint32_t _start_data_section_init;
extern uint32_t _start_data_section_rt;
extern uint32_t _end_data_section_rt;
extern uint32_t _start_bss_section;
extern uint32_t _end_bss_section;

extern int main(void);

#endif
