#include "gpio.h"
#include <stdint.h>

void set_pin_as_output(uint32_t pin) {
  uint8_t pinNo = 0;

  while (pin) {
    if (pin & 1) {
      volatile uint32_t *pin_cnf = (volatile uint32_t *)(GPIO_BASE + 0x700 + (pinNo * 4));
      *pin_cnf = 1;
    }
    ++pinNo;
    pin >>= 1;
  }
}

void turn_on_pin(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_BASE + 0x504);
  *out = pins;
}

void turn_off_pin(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_BASE + 0x504);
  *out = !pins;
}

void toggle_pin(uint32_t pins) {
  volatile uint32_t *out = (volatile uint32_t *)(GPIO_BASE + 0x504);
  *out ^= pins;
}
