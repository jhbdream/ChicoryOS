//
// Created by neroyang on 2021/9/5.
//

#include "../../include/device.h"

void generic_timer_probe(DeviceDesc *desc, DeviceNode *node) {}

static DeviceDesc generic_timer_init_desc = {.compatible = "arm,generic_timer",
                                             .doProbe = &generic_timer_probe};

int generic_timer_init(void *args) {
  register_device(&generic_timer_init_desc);
  return 0;
}

early_device_init(generic_timer_init)
