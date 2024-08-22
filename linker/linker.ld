ENTRY(reset_handler)

_end_stack_memory = ORIGIN(SRAM1) + LENGTH(SRAM1) + LENGTH(SRAM2) + LENGTH(SRAM3);

MEMORY
{
    SRAM1 (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
    SRAM2 (rwx) : ORIGIN = 0x2001C000, LENGTH = 16K
    SRAM3 (rwx) : ORIGIN = 0x20020000, LENGTH = 64K
    FLASH (rw) : ORIGIN = 0x08000000, LENGTH = 2M
}

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
    }> FLASH

    _start_data_section_init = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _start_data_section_rt = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _end_data_section_rt = .;
    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _start_bss_section = .;
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        _end_bss_section = .;
    }> SRAM 
}
