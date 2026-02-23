MEMORY 
{
  rom (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  ram (rwx): ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS 
{
  .text : ALIGN(4)
  {
    KEEP(*(.vector_table))
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
  } > rom

  _sidata = LOADADDR(.data);
  .data : ALIGN(4)
  {
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > ram AT > rom

  .bss : ALIGN(4)
  {
    _sbss = .;
    *(.bss*)
    . = ALIGN(4);
    _ebss = .;
  } > ram
}

_stack = ORIGIN(ram) + LENGTH(ram);
