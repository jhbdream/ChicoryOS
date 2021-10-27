OS_BASE_DIR = /home/yang/ChicoryOS
BUILD_DIR = $(OS_BASE_DIR)/Build
ARCH_DIR = $(OS_BASE_DIR)/Arch
KERNEL_DIR = $(OS_BASE_DIR)/Kernel
ARCH = arm64

CC=clang-12
CFLAGS = -target arm64v8a-unknown-linux-elf -mcpu=cortex-a72  -g
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
		$(BUILD_DIR)/pl011.o \
		$(BUILD_DIR)/generic_timer.o \
		$(BUILD_DIR)/gic400.o \
		$(BUILD_DIR)/init.o

$(BUILD_DIR)/%.o: $(ARCH_DIR)/$(ARCH)/boot/%.S
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/drivers/uart/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/drivers/timer/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/drivers/interrupt/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

kernel.elf: $(OBJS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/* 