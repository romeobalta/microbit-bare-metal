#include "gpio.h"
#include <stdint.h>

void gpio_mode_output(uint32_t pins) {
  uint8_t pin_no = 0;

  while (pins) {
    if (pins & 1) {
      volatile uint32_t *pin_cnf = (volatile uint32_t *)(GPIO_CNF + (pin_no * 4));
      *pin_cnf = 1;
    }
    ++pin_no;
    pins >>= 1;
  }
}

void gpio_mode_input(uint32_t pins) {
  uint8_t pin_no = 0;

  while (pins) {
    if (pins & 1) {
      volatile uint32_t *pin_cnf = (volatile uint32_t *)(GPIO_CNF + (pin_no * 4));
      // 11 - pull up , 0 - connected input buffer, 0 - input mode
      *pin_cnf = 0b1100;
    }
    ++pin_no;
    pins >>= 1;
  }
}

void gpio_pin_on(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_OUT);
  *out |= pins;
}

void gpio_pin_off(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_OUT);
  *out &= ~pins;
}

void gpio_toggle_pin(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_OUT);
  *out ^= pins;
}

uint32_t gpio_read(uint32_t pins) {
  volatile uint32_t *in = (volatile uint32_t *)(GPIO_IN);
  return ~(*in) & pins;
}
