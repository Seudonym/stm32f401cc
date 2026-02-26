#include "stm32f401cc.h"
#include <stdint.h>

int main(void) {
  RCC_AHB1ENR |= (1 << 2);   // set bit 2
  GPIOC_MODER &= ~(3 << 26); // clear bits 26 and 27
  GPIOC_MODER |= (1 << 26);  // set pins 26 and 27 to 01
  GPIOC_ODR &= ~(1 << 13);   // clear pin 13 only (active low)
  return 0;
}
