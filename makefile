OS_BASE_DIR = /Users/neroyang/project/SynestiaOS/SynestiaOS_Breezy
BUILD_DIR = $(OS_BASE_DIR)/Build
ARCH_DIR = $(OS_BASE_DIR)/Arch
KERNEL_DIR = $(OS_BASE_DIR)/Kernel
ARCH = arm64

CC=clang
CFLAGS = -target arm64v8a-unknown-none-eabi -mcpu=cortex-a53 -mfpu=none -mfloat-abi=soft
CFLAGS += -I
CFLAGS += -nostartfiles -nostdlib --no-standard-libraries
CFLAGS += -v
LDFLAGS = -use-ld=lld -T ${ARCH_DIR}/$(ARCH)/kernel.lds

OBJS = $(BUILD_DIR)/boot.o \
		$(BUILD_DIR)/exception_el3.o \
		$(BUILD_DIR)/exception_el2.o \
		$(BUILD_DIR)/exception_el1.o \
		$(BUILD_DIR)/init.o  

$(BUILD_DIR)/%.o: $(ARCH_DIR)/$(ARCH)/boot/%.S 
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/%.c 
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

kernel.elf:  $(OBJS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/*