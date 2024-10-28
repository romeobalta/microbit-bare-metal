#define NRF52

#include <libopencm3/nrf/52/gpio.h>
#include <stdint.h>

int main(void) {
  uint32_t pin_row = 22;
  uint32_t pin_col = 28;
  volatile uint32_t *pin_row_cnf;
  volatile uint32_t *pin_col_cnf;
  volatile uint32_t *out;

  // Base address for GPIO Port 0
  uint32_t gpio_base = 0x50000000UL;

  // Calculate addresses of the registers
  pin_row_cnf = (volatile uint32_t *)(gpio_base + 0x700 + (pin_row * 4));
  pin_col_cnf = (volatile uint32_t *)(gpio_base + 0x700 + (pin_col * 4));
  out = (volatile uint32_t *)(gpio_base + 0x504);

  // Configure the pin as an output
  *pin_row_cnf = 1;
  *pin_col_cnf = 1;

  // Set the pin as output
  uint8_t is_on = 0;

  while (1) {
    // Turn the LED on
    *out = (is_on << pin_row);
    // Delay
    for (volatile uint32_t i = 0; i < 1000000; i++)
      ;
    // Turn the LED off
    is_on = !is_on;
  }
}
