#define NRF52

#include "gpio.h"
#include "tick.h"
#include <stdint.h>

// Col1 = GPIO21 | GPIO22 | GPIO15 | GPIO24 | GPIO19
#define PIN_ROW (GPIO21)
#define PIN_COL (GPIO28)

int main(void) {
  // Enable the SysTick timer at 1 MHz
  tick_enable(1000);

  // Calculate addresses of the registers
  gpio_mode_output(PIN_ROW | PIN_COL);

  // Start tracking time
  uint32_t start = tick_get_current();

  while (1) {
    // Blink the LED every second
    if (tick_get_current() - start >= 1000) {
      // Turn the LED on
      gpio_toggle(PIN_ROW);
      start = tick_get_current();
    }
  }
}
