/*
 * Created Date: Monday, August 23rd 2021, 8:46:49 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#ifndef __CHICORYOS_KERNEL_DEVICE__
#define __CHICORYOS_KERNEL_DEVICE__

#include "device_tree.h"
#include "dlist.h"
#include "stddef.h"

typedef int (*DeviceInitFunc)(void *);
#define __initcall_init(func, level)                            \
  static DeviceInitFunc __initcall_init_lv##level##_##func \
      __attribute__((__used__))                                 \
          __attribute__((section(".initcall_lv" #level ".init"))) = func;

#define early_device_init(func) __initcall_init(func, 0)
#define key_device_init(func) __initcall_init(func, 1)

struct DeviceDesc;
typedef void (*DeviceProbeFunc)(struct DeviceDesc *desc, DeviceNode *node);
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
void init_key_devices();

#endif /* __CHICORYOS_KERNEL_DEVICE__ */
