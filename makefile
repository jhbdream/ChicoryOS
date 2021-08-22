OS_BASE_DIR = /Users/neroyang/project/SynestiaOS/SynestiaOS_Breezy
BUILD_DIR = $(OS_BASE_DIR)/Build
ARCH_DIR = $(OS_BASE_DIR)/Arch
KERNEL_DIR = $(OS_BASE_DIR)/Kernel
ARCH = arm64

CC=clang
CFLAGS=-target armv8a-unknown-none-eabi -mcpu=cortex-a76 -mfpu=none -mfloat-abi=soft -I
CFLAGS += 
LDFLAGS=-T ${ARCH_DIR}/$(ARCH)/kernel.lds -use-ld=lld

$(BUILD_DIR)/boot.o:
	$(CC) -c -o $@ $(ARCH_DIR)/$(ARCH)/boot/boot.S 

$(BUILD_DIR)/%.o: $(KERNEL_DIR)/%.c 
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

kernel: $(BUILD_DIR)/*.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/*