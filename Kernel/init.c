/*
 * Created Date: Saturday, August 21st 2021, 11:51:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 Your Company
 */

#include "include/console.h"
#include "include/device.h"

int _kernel_entry(int el) {
  init_early_devices();
  Console *console = console_get();
  if (el == 1) {
    console->put(console, "Hello from kernel.");
  } else if (el == 2) {
    console->put(console, "Hello from hypervisor.");
  } else if (el == 3) {
    console->put(console, "Hello from security monitor.");
  } else {
    console->put(console, "Hello from unknown el.");
  }

  while (1)
    ;
}
