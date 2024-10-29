#include "tick.h"

void tick_enable(uint32_t frequency) {
  uint32_t ratio = AHB_FREQUENCY / frequency;
  // Set the reload value
  (*(volatile uint32_t *)SYST_RVR) = ratio - 1;
  // Clear the current value
  (*(volatile uint32_t *)SYST_CVR) = 0x0;
  // Set the clock source and enable counter and enable SysTick IRQ
  (*(volatile uint32_t *)SYST_CSR) |= 0b111;
}

// using uint64_t will make any operation on the counter will
// be assembled to more than one instruction
static volatile uint64_t ticks = 0;

void sys_tick_handler(void) {
  ticks++;
}

uint64_t tick_get_current(void) {
  return ticks;
}
