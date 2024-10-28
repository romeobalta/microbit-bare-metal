#include <stdint.h>

extern uint32_t _sstack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void NMI_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void HardFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void Test_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void MemManage_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void Bus_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void Usage_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SVCall_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void DebugMonitor_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void PendSV_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SysTick_Handler(void);

__attribute__((weak, alias("Default_Handler"))) void POWER_CLOCK_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RADIO_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void UARTE0_UART0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void NFCT_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void GPIOTE_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SAADC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIMER0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIMER1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIMER2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RTC0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TEMP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RNG_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void ECB_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void CCM_AAR_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void WDT_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RTC1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void QDEC_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void COMP_LPCOMP_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI0_EGU0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI1_EGU1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI2_EGU2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI3_EGU3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI4_EGU4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SWI5_EGU5_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIMER3_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void TIMER4_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void PWM0_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void PDM_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void MWU_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void PWM1_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void PWM2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void SPIM2_SPIS2_SPI2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void RTC2_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void I2S_IRQHandler(void);
__attribute__((weak, alias("Default_Handler"))) void FPU_IRQHandler(void);
// __attribute__((weak, alias("Default_Handler"))) void UARTE1_IRQHandler(void);

__attribute__((section(".isr_vector"))) uint32_t vectors[] = {
    (uint32_t)&_sstack,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&Bus_Handler,
    (uint32_t)&Usage_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,

    // External Interrupts
    (uint32_t)&POWER_CLOCK_IRQHandler,
    (uint32_t)&RADIO_IRQHandler,
    (uint32_t)&UARTE0_UART0_IRQHandler,
    (uint32_t)&SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQHandler,
    (uint32_t)&SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQHandler,
    (uint32_t)&NFCT_IRQHandler,
    (uint32_t)&GPIOTE_IRQHandler,
    (uint32_t)&SAADC_IRQHandler,
    (uint32_t)&TIMER0_IRQHandler,
    (uint32_t)&TIMER1_IRQHandler,
    (uint32_t)&TIMER2_IRQHandler,
    (uint32_t)&RTC0_IRQHandler,
    (uint32_t)&TEMP_IRQHandler,
    (uint32_t)&RNG_IRQHandler,
    (uint32_t)&ECB_IRQHandler,
    (uint32_t)&CCM_AAR_IRQHandler,
    (uint32_t)&WDT_IRQHandler,
    (uint32_t)&RTC1_IRQHandler,
    (uint32_t)&QDEC_IRQHandler,
    (uint32_t)&COMP_LPCOMP_IRQHandler,
    (uint32_t)&SWI0_EGU0_IRQHandler,
    (uint32_t)&SWI1_EGU1_IRQHandler,
    (uint32_t)&SWI2_EGU2_IRQHandler,
    (uint32_t)&SWI3_EGU3_IRQHandler,
    (uint32_t)&SWI4_EGU4_IRQHandler,
    (uint32_t)&SWI5_EGU5_IRQHandler,
    (uint32_t)&TIMER3_IRQHandler,
    (uint32_t)&TIMER4_IRQHandler,
    (uint32_t)&PWM0_IRQHandler,
    (uint32_t)&PDM_IRQHandler,
    0,
    0,
    (uint32_t)&MWU_IRQHandler,
    (uint32_t)&PWM1_IRQHandler,
    (uint32_t)&PWM2_IRQHandler,
    (uint32_t)&SPIM2_SPIS2_SPI2_IRQHandler,
    (uint32_t)&RTC2_IRQHandler,
    (uint32_t)&I2S_IRQHandler,
    (uint32_t)&FPU_IRQHandler,
    0,
    // (uint32_t)&UARTE1_IRQHandler,

};

void Reset_Handler(void) {
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

void Default_Handler(void) {
  while (1)
    ;
}
