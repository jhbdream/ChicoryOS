/*
 * Created Date: Monday, August 30th 2021, 10:52:08 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 SynestiaOS
 */
#include "gic400.h"

#include "../../include/device.h"

#define GIC_400_BASE_ADDRESS 0x4c0040000
#define GIC_400_LOW_BASE_ADDRESS 0xff840000
#define GIC_400_NUM_CPU 4
#define GIC_400_NUM_SPIS 192

void gic400_probe(DeviceDesc *desc, DeviceNode *node) {
  // _Static_assert(OffsetOf(GICDistributor,GICD_CTLR) == 0, "Distributor
  // Control Register GICD_CTLR offset should be 0");
  // FIXME: check distributor offset
  // FIXME: reset distributor registers
  // TODO:
}

static DeviceDesc gic400_desc = {.compatible = "gic_v3,pl011",
                                 .doProbe = &gic400_probe};

int gic_v3_init(void *args) {
  register_device(&gic400_desc);
  return 0;
}

early_device_init(gic_v3_init)