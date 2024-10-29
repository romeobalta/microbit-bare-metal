# Ingredients
TARGET        := firmware

# Architecture
CPU           := cortex-m4
ARCH          := armv7e-m
FPU           := fpv4-sp-d16
FLOAT_ABI     := hard
ARCH_FLAGS    := -mcpu=$(CPU) -march=$(ARCH) -mthumb -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU)

# Paths
SRC_FOLDER    := src
BUILD_FOLDER  := build
OBJ_FOLDER    := $(BUILD_FOLDER)/obj
BIN_FOLDER    := $(BUILD_FOLDER)/bin

TARGET        := $(BIN_FOLDER)/$(TARGET)

# Compiler
INC_FOLDER    := include
LDLIBS        := -lc -lgcc -lnosys

LDSCRIPT      := microbit_ls.ld

# If USE_LIBOPENCM3 is defined, include the libopencm3 Makefile
ifdef USE_LIBOPENCM3
  OPENCM3_DIR   := external/libopencm3
	INC_FOLDER    += $(OPENCM3_DIR)/include
	LDLIBS        += -L$(OPENCM3_DIR)/lib -lopencm3_nrf52
  LDSCRIPT      := microbit_libopencm3_ls.ld
endif

INCLUDES      := $(addprefix -I, $(INC_FOLDER))

WARNINGS      := -Wall -Wextra -Werror
CC            := arm-none-eabi-gcc
CFLAGS        := $(ARCH_FLAGS) -std=gnu11 -O0 -c $(WARNINGS) $(INCLUDES)

LD            := arm-none-eabi-gcc
LDFLAGS       := $(ARCH_FLAGS) -nostartfiles -T $(LDSCRIPT) -Wl,-Map=$(TARGET).map

OBJCOPY       := arm-none-eabi-objcopy

# Sources
SRCS          := \
								 main.c\
								 gpio.c
SRCS           += startup.c

OBJS          := $(SRCS:.c=.o)
SRCS          := $(addprefix $(SRC_FOLDER)/, $(SRCS))
OBJS          := $(addprefix $(OBJ_FOLDER)/, $(OBJS))

# Util
RM            := rm -rf
DIR_CREATE    = mkdir -p $(@D)

# Recipes
all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	$(DIR_CREATE)
	$(OBJCOPY) -O ihex $< $@

$(TARGET).elf: $(OBJS)
	$(DIR_CREATE)
	$(LD) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(DIR_CREATE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(BUILD_FOLDER)

flash: $(TARGET).hex
	cp $< /Volumes/MICROBIT/

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re flash
