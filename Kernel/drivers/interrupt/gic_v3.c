/*
 * Created Date: Monday, August 30th 2021, 10:52:08 pm
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */
#include "../../include/device.h"

void gic400_probe(DeviceDesc *desc, DeviceNode *node) {
    // TODO:
}

static DeviceDesc gic400_desc = {
        .compatible = "gic_v3,pl011",
        .doProbe = &gic400_probe
};

int gic_v3_init(void* args) {
    register_device(&gic400_desc);
    return 0;
}

early_device_init(gic_v3_init)