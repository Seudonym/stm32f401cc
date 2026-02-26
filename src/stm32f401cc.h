#define RCC_BASE 0x40023800
#define GPIOC_BASE 0x40020800

#define RCC_AHB1ENR *(volatile uint32_t *)(RCC_BASE + 0x30)
#define GPIOC_MODER *(volatile uint32_t *)(GPIOC_BASE + 0x00)
#define GPIOC_ODR *(volatile uint32_t *)(GPIOC_BASE + 0x14)
