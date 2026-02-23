#include <stdint.h>

extern int main(void);

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _stack;

void copy_data(void) {
  uint32_t *p_rom_data = &_sidata;
  uint32_t *p_ram_data = &_sdata;
  while (p_ram_data < &_edata) {
    *p_ram_data++ = *p_rom_data++;
  }
}

void clear_bss(void) {
  uint32_t *p_bss = &_sbss;
  while (p_bss < &_ebss) {
    *p_bss++ = 0;
  }
}

void Reset(void) {
  copy_data();
  clear_bss();
  main();

  while (1)
    ;
}

void HardFault(void) {
  while (1)
    ;
}

#define IVT_ARRAY_SIZE 101
typedef void (*isr_t)(void);

// clang-format off
__attribute((used, section(".vector_table"))) 
static const isr_t ivt[IVT_ARRAY_SIZE] = {
    [0] = (isr_t)&_stack,
    [1] = Reset,
    [3] = HardFault
};
