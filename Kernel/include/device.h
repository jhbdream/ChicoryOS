/*
 * Created Date: Monday, August 23rd 2021, 8:46:49 pm
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */
#ifndef __SYNESTIAOS_KERNEL_DEVICE__
#define __SYNESTIAOS_KERNEL_DEVICE__

#include "stddef.h"
#include "dlist.h"
#include "device_tree.h"

typedef int (*EarlyDeviceInitFunc)(void *);
#define __initcall_init(func, level) static EarlyDeviceInitFunc __initcall_init_lv##level##_##func __attribute__((__used__)) __attribute__((section(".initcall_lv" #level ".init"))) = func;
#define early_device_init(func) __initcall_init(func, 0)

typedef void(*DeviceProbeFunc)(struct DeviceDesc *desc, DeviceNode *node);
typedef struct DeviceDesc {
	char *compatible;
	DeviceProbeFunc doProbe;
} DeviceDesc;

typedef struct Device {
	char name[KERNEL_NAME_LEN];
	ListNode node;
} Device;

void register_device(DeviceDesc *desc);

void init_early_devices();

#endif /* __SYNESTIAOS_KERNEL_DEVICE__ */