#ifndef TICK_H
#define TICK_H
#include <stdint.h>

#define SYST_BASE (0xE000E000)

#define SYST_CSR (SYST_BASE + 0x10)
#define SYST_RVR (SYST_BASE + 0x14)
#define SYST_CVR (SYST_BASE + 0x18)
#define SYST_CALIB (SYST_BASE + 0x1C)

#define AHB_FREQUENCY (64000000)

void tick_enable(uint32_t frequency);
uint64_t tick_get_current(void);

#endif
