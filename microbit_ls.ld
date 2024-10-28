ENTRY(Reset_Handler)

MEMORY
{
  FLASH (xr)   : ORIGIN = 0x00000000, LENGTH = 512K
  SRAM  (rxw)  : ORIGIN = 0x20000000, LENGTH = 128K
}

_sstack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
  .text :
  {
    *(.isr_vector)
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
    _etext = .;
  } > FLASH

  .data :
  {
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > SRAM AT > FLASH

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > SRAM
}
