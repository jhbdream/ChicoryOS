/*
 * Created Date: Monday, August 23rd 2021, 10:46:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "include/device.h"

extern DeviceInitFunc __initcall_init_lv0_start[];
extern DeviceInitFunc __initcall_init_lv0_end[];
extern DeviceInitFunc __initcall_init_lv1_start[];
extern DeviceInitFunc __initcall_init_lv1_end[];

void register_device(DeviceDesc *desc) {
  // TODO: search in device tree by compatible
  if (desc->doProbe != NULL) {
    desc->doProbe(desc, device_tree_find_by_compatible(desc->compatible));
  }
}

void init_early_devices() {
  DeviceInitFunc *function = NULL;
  for (function = __initcall_init_lv0_start; function < __initcall_init_lv0_end;
       function++) {
    (*function)(NULL);
  }
}

void init_key_devices() {
  DeviceInitFunc *function = NULL;
  for (function = __initcall_init_lv1_start; function < __initcall_init_lv1_end;
       function++) {
    (*function)(NULL);
  }
}
