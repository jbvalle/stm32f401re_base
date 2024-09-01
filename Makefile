# Binaries
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy 

PIC_SCRIPT = assert_v0_2.py

# Directories
SRC_DIR = src
GEN_DIR = gen
INC_DIR = inc
LINKER_DIR = linker
DEB_DIR = debug
TOOLS_DIR = tools
PIC_DIR = peripheral_integrity_check
LOG_DIR = log
CONFIG_DIR = config

# Files 
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(GEN_DIR)/%.o, $(SRC))
LD := $(wildcard $(LINKER_DIR)/*.ld)

CONFIG_HEX = $(GEN_DIR)/$(CONFIG_DIR)/config_data.hex
CONFIG_OBJ = $(GEN_DIR)/config_data.o

# FLAGS
MARCH = cortex-m4
CFLAGS = -g -Wall -mcpu=$(MARCH) -mthumb -mfloat-abi=soft -I$(INC_DIR) -ffreestanding -nostartfiles -O0
LFLAGS = -nostdlib -T $(LD) -Wl,-Map=$(GEN_DIR)/$(DEB_DIR)/main.map

#PATHS
OPENOCD_INTERFACE = /usr/share/openocd/scripts/interface/stlink-v2.cfg
OPENOCD_TARGET = /usr/share/openocd/scripts/target/stm32f4x.cfg

# Targets
TARGET = $(GEN_DIR)/$(DEB_DIR)/main.elf

all:  $(OBJ) $(TARGET)

$(GEN_DIR)/%.o : $(SRC_DIR)/%.c | mkobj
	$(CC) $(CFLAGS) -c -o $@ $^

$(CONFIG_OBJ) : $(CONFIG_HEX) | mkobj
	$(OBJCOPY)  -I binary -O elf32-littlearm --rename-section .data=.config_data $^ $@ 

$(TARGET) : $(OBJ) $(CONFIG_OBJ) | mkdeb
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^


$(TOOLS_DIR)/$(PIC_DIR)/%.txt : 

mkobj:
	mkdir -p $(GEN_DIR)
	mkdir -p $(GEN_DIR)/$(CONFIG_DIR)

mkdeb:
	mkdir -p $(GEN_DIR)/$(DEB_DIR)

mktools:
	mkdir -p $(TOOLS_DIR)/$(PIC_DIR)

flash: FORCE
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) &
	gdb-multiarch $(TARGET) -x $(LINKER_DIR)/flash.gdb

peripheral_integrity_check: FORCE | mktools
	mkdir -p $(GEN_DIR)/$(LOG_DIR)
	python3 $(TOOLS_DIR)/$(PIC_DIR)/$(PIC_SCRIPT) $(SRC_DIR)/*.c $(INC_DIR)/*.h -o $(GEN_DIR)/$(LOG_DIR)/peripheral_integrity_check_log.txt

generate_config_hex: FORCE | mkobj
	@echo "/***************************************/"
	@echo "/******** GENERATING CONFIG HEX ********/"
	@echo "/***************************************/"
	python3 $(TOOLS_DIR)/generate_config_hex.py

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
	rm -rf $(GEN_DIR) .cache compile_commands.json .gdb_history

display: FORCE
	echo $(PIC)

FORCE:

.PHONY = mkobj mkdeb clean FORCE flash debug edit doxy

