#define NRF52

#include "gpio.h"
#include <stdint.h>

int main(void) {
  uint32_t pin_row = GPIO21 | GPIO22 | GPIO15 | GPIO24 | GPIO19;
  uint32_t pin_col = GPIO28;

  // Calculate addresses of the registers
  gpio_mode_output(pin_row | pin_col);

  while (1) {
    // Turn the LED on
    gpio_toggle(pin_row);

    // Delay
    for (volatile uint32_t i = 0; i < 1000000; i++)
      ;
  }
}
