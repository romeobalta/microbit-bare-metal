#include <stdint.h>

extern uint32_t _sstack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void reset_handler(void);
__attribute__((weak, alias("default_handler"))) void nmi_handler(void);
__attribute__((weak, alias("default_handler"))) void hard_fault_handler(void);
__attribute__((weak, alias("default_handler"))) void mem_manage_handler(void);
__attribute__((weak, alias("default_handler"))) void bus_handler(void);
__attribute__((weak, alias("default_handler"))) void usage_handler(void);
__attribute__((weak, alias("default_handler"))) void sv_call_handler(void);
__attribute__((weak, alias("default_handler"))) void debug_monitor_handler(void);
__attribute__((weak, alias("default_handler"))) void pend_sv_handler(void);
__attribute__((weak, alias("default_handler"))) void sys_tick_handler(void);

__attribute__((weak, alias("default_handler"))) void power_clock_handler(void);
__attribute__((weak, alias("default_handler"))) void radio_handler(void);
__attribute__((weak, alias("default_handler"))) void uarte0_uart0_handler(void);
__attribute__((weak, alias("default_handler"))) void spim0_spis0_twim0_twis0_spi0_twi0_handler(void);
__attribute__((weak, alias("default_handler"))) void spim1_spis1_twim1_twis1_spi1_twi1_handler(void);
__attribute__((weak, alias("default_handler"))) void nfct_handler(void);
__attribute__((weak, alias("default_handler"))) void gpiote_handler(void);
__attribute__((weak, alias("default_handler"))) void saadc_handler(void);
__attribute__((weak, alias("default_handler"))) void timer0_handler(void);
__attribute__((weak, alias("default_handler"))) void timer1_handler(void);
__attribute__((weak, alias("default_handler"))) void timer2_handler(void);
__attribute__((weak, alias("default_handler"))) void rtc0_handler(void);
__attribute__((weak, alias("default_handler"))) void temp_handler(void);
__attribute__((weak, alias("default_handler"))) void rng_handler(void);
__attribute__((weak, alias("default_handler"))) void ecb_handler(void);
__attribute__((weak, alias("default_handler"))) void ccm_aar_handler(void);
__attribute__((weak, alias("default_handler"))) void wdt_handler(void);
__attribute__((weak, alias("default_handler"))) void rtc1_handler(void);
__attribute__((weak, alias("default_handler"))) void qdec_handler(void);
__attribute__((weak, alias("default_handler"))) void comp_lpcomp_handler(void);
__attribute__((weak, alias("default_handler"))) void swi0_egu0_handler(void);
__attribute__((weak, alias("default_handler"))) void swi1_egu1_handler(void);
__attribute__((weak, alias("default_handler"))) void swi2_egu2_handler(void);
__attribute__((weak, alias("default_handler"))) void swi3_egu3_handler(void);
__attribute__((weak, alias("default_handler"))) void swi4_egu4_handler(void);
__attribute__((weak, alias("default_handler"))) void swi5_egu5_handler(void);
__attribute__((weak, alias("default_handler"))) void timer3_handler(void);
__attribute__((weak, alias("default_handler"))) void timer4_handler(void);
__attribute__((weak, alias("default_handler"))) void pwm0_handler(void);
__attribute__((weak, alias("default_handler"))) void pdm_handler(void);
__attribute__((weak, alias("default_handler"))) void mwu_handler(void);
__attribute__((weak, alias("default_handler"))) void pwm1_handler(void);
__attribute__((weak, alias("default_handler"))) void pwm2_handler(void);
__attribute__((weak, alias("default_handler"))) void spim2_spis2_spi2_handler(void);
__attribute__((weak, alias("default_handler"))) void rtc2_handler(void);
__attribute__((weak, alias("default_handler"))) void i2s_handler(void);
__attribute__((weak, alias("default_handler"))) void fpu_handler(void);
// __attribute__((weak, alias("default_handler"))) void uarte1_handler(void);

__attribute__((section(".isr_vector"))) uint32_t vectors[] = {
    (uint32_t)&_sstack,
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hard_fault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_handler,
    (uint32_t)&usage_handler,
    0,
    0,
    0,
    0,
    (uint32_t)&sv_call_handler,
    (uint32_t)&debug_monitor_handler,
    0,
    (uint32_t)&pend_sv_handler,
    (uint32_t)&sys_tick_handler,

    // External Interrupts
    (uint32_t)&power_clock_handler,
    (uint32_t)&radio_handler,
    (uint32_t)&uarte0_uart0_handler,
    (uint32_t)&spim0_spis0_twim0_twis0_spi0_twi0_handler,
    (uint32_t)&spim1_spis1_twim1_twis1_spi1_twi1_handler,
    (uint32_t)&nfct_handler,
    (uint32_t)&gpiote_handler,
    (uint32_t)&saadc_handler,
    (uint32_t)&timer0_handler,
    (uint32_t)&timer1_handler,
    (uint32_t)&timer2_handler,
    (uint32_t)&rtc0_handler,
    (uint32_t)&temp_handler,
    (uint32_t)&rng_handler,
    (uint32_t)&ecb_handler,
    (uint32_t)&ccm_aar_handler,
    (uint32_t)&wdt_handler,
    (uint32_t)&rtc1_handler,
    (uint32_t)&qdec_handler,
    (uint32_t)&comp_lpcomp_handler,
    (uint32_t)&swi0_egu0_handler,
    (uint32_t)&swi1_egu1_handler,
    (uint32_t)&swi2_egu2_handler,
    (uint32_t)&swi3_egu3_handler,
    (uint32_t)&swi4_egu4_handler,
    (uint32_t)&swi5_egu5_handler,
    (uint32_t)&timer3_handler,
    (uint32_t)&timer4_handler,
    (uint32_t)&pwm0_handler,
    (uint32_t)&pdm_handler,
    0,
    0,
    (uint32_t)&mwu_handler,
    (uint32_t)&pwm1_handler,
    (uint32_t)&pwm2_handler,
    (uint32_t)&spim2_spis2_spi2_handler,
    (uint32_t)&rtc2_handler,
    (uint32_t)&i2s_handler,
    (uint32_t)&fpu_handler,
    0,
    // (uint32_t)&uarte1_handler,

};

void reset_handler(void) {
  // Copy .data to SRAM
  uint32_t size = &_edata - &_sdata;

  uint8_t *pDst = (uint8_t *)&_sdata; // SRAM
  uint8_t *pSrc = (uint8_t *)&_etext; // Flash

  for (uint32_t i = 0; i < size; i++) {
    *pDst++ = *pSrc++;
  }

  // Init the .bss section to zero in SRAM
  size = (uint32_t)&_ebss - (uint32_t)&_sbss;

  pDst = (uint8_t *)&_sbss;
  for (uint32_t i = 0; i < size; i++) {
    *pDst++ = 0;
  }

  // Call main()
  main();

  while (1)
    ;
}

void default_handler(void) {
  while (1)
    ;
}
