/*
 * Created Date: Monday, August 23rd 2021, 10:14:55 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "../../include/console.h"
#include "../../include/device.h"

#define UART0DR 0x09000000
volatile unsigned int *const ptr = (unsigned int *)UART0DR;

void pl011_put(Console *console, char *str) {
  char *tmp = str;
  while (*tmp != '\0') {
    *ptr = *tmp;
    tmp++;
  }
}

static Console pl011_console = {.put = pl011_put};

void pl011_probe(DeviceDesc *desc, DeviceNode *node) {
  register_console(&pl011_console);
}

static DeviceDesc pl011_desc = {.compatible = "arm,pl011",
                                .doProbe = &pl011_probe};

int pl011_init(void *args) {
  register_device(&pl011_desc);
  return 0;
}

early_device_init(pl011_init)
