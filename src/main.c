#define NRF52

#include "gpio.h"
#include "tick.h"
#include <stdint.h>

// Col1 = GPIO21 | GPIO22 | GPIO15 | GPIO24 | GPIO19
#define PIN_ROW (GPIO21 | GPIO22 | GPIO15 | GPIO24 | GPIO19)
#define PIN_COL (GPIO28 | GPIO11 | GPIO31)

#define BTN_A (GPIO14)
#define BTN_B (GPIO23)

int main(void) {
  // Enable the SysTick timer at 1 MHz
  tick_enable(1000);

  // Calculate addresses of the registers
  gpio_mode_output(PIN_ROW | PIN_COL);
  gpio_mode_input(BTN_A | BTN_B);

  // Start tracking time
  uint32_t start = tick_get_current();

  uint32_t row_pins[] = {GPIO21, GPIO22, GPIO15, GPIO24, GPIO19};
  uint32_t current_pin = 0;

  uint32_t pressed[2] = {0};
  while (1) {
    // Blink the LED every second
    if (tick_get_current() - start >= 1000) {
      // Turn the LED on
      gpio_toggle_pin(row_pins[current_pin]);
      start = tick_get_current();
    }

    if (gpio_read(BTN_A)) {
      if (!pressed[0]) {
        gpio_pin_off(row_pins[current_pin]);
        // delay 3 cycles
        current_pin = (current_pin + 1) % 5;
        gpio_pin_on(row_pins[current_pin]);
        start = tick_get_current();
        pressed[0] = 1;
      }
    } else {
      pressed[0] = 0;
    }

    if (gpio_read(BTN_B)) {
      if (!pressed[1]) {
        gpio_pin_off(row_pins[current_pin]);
        // delay 3 cycles
        current_pin = (current_pin + 4) % 5;
        gpio_pin_on(row_pins[current_pin]);
        start = tick_get_current();
        pressed[1] = 1;
      }
    } else {
      pressed[1] = 0;
    }
  }
}
