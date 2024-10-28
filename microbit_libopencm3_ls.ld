ENTRY(Reset_Handler)

MEMORY
{
  rom (xr)   : ORIGIN = 0x00000000, LENGTH = 512K
  ram  (rxw)  : ORIGIN = 0x20000000, LENGTH = 128K
}

INCLUDE cortex-m-generic.ld
