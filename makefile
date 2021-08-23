OS_BASE_DIR = /Users/neroyang/project/SynestiaOS/SynestiaOS_Breezy
BUILD_DIR = $(OS_BASE_DIR)/Build
ARCH_DIR = $(OS_BASE_DIR)/Arch
KERNEL_DIR = $(OS_BASE_DIR)/Kernel
ARCH = arm64

CC=clang
CFLAGS = -target arm64v8a-unknown-linux-elf -mcpu=cortex-a53 
CFLAGS += -nostdlib --no-standard-libraries
LDFLAGS = -fuse-ld=lld -T $(ARCH_DIR)/$(ARCH)/kernel.lds 
LDFLAGS += -mfpu=none -mfloat-abi=soft -nostartfiles -v 


OBJS = $(BUILD_DIR)/boot.o \
		$(BUILD_DIR)/exception_el3.o \
		$(BUILD_DIR)/exception_el2.o \
		$(BUILD_DIR)/exception_el1.o \
		$(BUILD_DIR)/device_tree.o \
		$(BUILD_DIR)/device.o \
		$(BUILD_DIR)/console.o \
		$(BUILD_DIR)/init.o

$(BUILD_DIR)/%.o: $(ARCH_DIR)/$(ARCH)/boot/%.S
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/drivers/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

kernel.elf: $(OBJS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/*