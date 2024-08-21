ENTRY(reset_handler)

_end_stack_memory = ORIGIN(SRAM) + LENGTH(SRAM);

MEMORY
{
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
    FLASH (rw) : ORIGIN = 0x08000000, LENGTH = 512K
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
