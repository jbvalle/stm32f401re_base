# Integration hints

1. linker
- [ ] linker.ld : adapt memory sections sram, flash to new uC    
- [ ] linker.ld : adapt flash and rt location of data sections
```
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
```
2. rcc
- [ ] adapt RCC_TypeDef struct to uC

