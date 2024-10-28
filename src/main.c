#define NRF52

#include "gpio.h"
#include <stdint.h>

int main(void) {
  uint32_t pin_row = GPIO21;
  uint32_t pin_col = GPIO28;

  // Calculate addresses of the registers
  set_pin_as_output(pin_row);
  set_pin_as_output(pin_col);

  while (1) {
    // Turn the LED on
    toggle_pin(pin_row);

    // Delay
    for (volatile uint32_t i = 0; i < 1000000; i++)
      ;
  }
}
