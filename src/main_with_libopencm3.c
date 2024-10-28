#define NRF52

#include <libopencm3/nrf/52/gpio.h>
#include <stdint.h>

static void delay_cycles(uint32_t cycles) {
  for (uint32_t i = 0; i < cycles; i++) {
    __asm__("NOP");
  }
}

int main(void) {
  gpio_mode_setup(GPIO_BASE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO21 | GPIO28);

  while (1) {
    gpio_toggle(GPIO, GPIO21);

    // Delay for 1 second
    delay_cycles(1000000);
  }

  return 0;
}
