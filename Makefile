# Binaries
CC = arm-none-eabi-gcc

# Directories
SRC_DIR = src
GEN_DIR = gen
INC_DIR = inc
LINKER_DIR = linker
DEB_DIR = debug

# Files 
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(GEN_DIR)/%.o, $(SRC))
LD := $(wildcard $(LINKER_DIR)/*.ld)

# FLAGS
MARCH = cortex-m4
CFLAGS = -g -Wall -mcpu=$(MARCH) -mthumb -mfloat-abi=soft -I$(INC_DIR) -ffreestanding -nostartfiles
LFLAGS = -nostdlib -T $(LD) -Wl,-Map=$(GEN_DIR)/$(DEB_DIR)/main.map

#PATHS
OPENOCD_INTERFACE = /usr/share/openocd/scripts/interface/stlink-v2.cfg
OPENOCD_TARGET = /usr/share/openocd/scripts/target/stm32f4x.cfg

# Targets
TARGET = $(GEN_DIR)/$(DEB_DIR)/main.elf

all: $(OBJ) $(TARGET)

$(GEN_DIR)/%.o : $(SRC_DIR)/%.c | mkobj
	$(CC) $(CFLAGS) -c -o $@ $^

$(TARGET) : $(OBJ) | mkdeb
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

mkobj:
	mkdir -p $(GEN_DIR)

mkdeb:
	mkdir -p $(GEN_DIR)/$(DEB_DIR)

flash: FORCE
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) &
	gdb-multiarch $(TARGET) -x $(LINKER_DIR)/flash.gdb

#debug: FORCE
#	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) &
#	gdb-multiarch $(TARGET) -x $(LINKER_DIR)/debug.gdb
#
#edit: FORCE
#	vim -S Session.vim
#
#doxy: FORCE
#   cd ./docs && doxygen Doxyfile

clean: FORCE
	rm -rf $(GEN_DIR)

FORCE:

.PHONY = mkobj mkdeb clean FORCE flash debug edit doxy

