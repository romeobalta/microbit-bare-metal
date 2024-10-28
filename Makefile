# Ingredients

TARGET        := microbit.elf

CPU           := cortex-m4
ARCH          := armv7e-m


OPENCM3_DIR   := external/libopencm3

INC_FOLDER    := include\
									$(OPENCM3_DIR)/include\

SRC_FOLDER    := src
BUILD_FOLDER  := build
OBJ_FOLDER    := $(BUILD_FOLDER)/obj
BIN_FOLDER    := $(BUILD_FOLDER)/bin

TARGET        := $(BIN_FOLDER)/$(TARGET)
HEX_TARGET    := $(TARGET:.elf=.hex)

CC            := arm-none-eabi-gcc
CFLAGS        := -march=$(ARCH) -mcpu=$(CPU) -mthumb -std=gnu11 -O0 -c -Wall -Wextra -Werror $(addprefix -I, $(INC_FOLDER))
LDFLAGS       := -nostdlib -T microbit_ls.ld -Wl,-Map=$(TARGET:.elf=.map) $(addprefix -I, $(INC_FOLDER))


LIBNAME       = opencm3_nrf52
LDLIBS        += -l$(LIBNAME)
LDFLAGS       += -L$(OPENCM3_DIR)/lib


SRCS          := \
								 main.c\
								 startup.c
OBJS          := $(SRCS:.c=.o)
SRCS          := $(addprefix $(SRC_FOLDER)/, $(SRCS))
OBJS          := $(addprefix $(OBJ_FOLDER)/, $(OBJS))

# Util

RM            := rm -rf
DIR_CREATE    = mkdir -p $(@D)

# Recipe

all: $(HEX_TARGET)

$(HEX_TARGET): $(TARGET)
	arm-none-eabi-objcopy -O ihex $< $@

$(TARGET): $(OBJS)
	$(DIR_CREATE)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(DIR_CREATE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(BUILD_FOLDER)

flash: $(HEX_TARGET)
	cp $< /Volumes/MICROBIT/

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re flash
