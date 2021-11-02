/*
 * Created Date: Saturday, August 21st 2021, 11:51:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "include/console.h"
#include "include/device.h"

int _kernel_entry() {
  init_early_devices();
  Console *console = console_get();
  console->put(console, "Kernel start.");

  while (1)
    ;
}
