/*
 * Created Date: Saturday, August 21st 2021, 11:51:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 Your Company
 */

#include "include/console.h"
#include "include/device.h"

int _kernel_entry(int mode) {
  init_early_devices();
  Console *console = console_get();
  if(mode == 1){
    console->put(console, "Hello from kernel.");
  }
  if(mode == 2){
    console->put(console, "Hello from hypervisor.");
  }
  if(mode == 3){
    console->put(console, "Hello from security monitor.");
  }

  while (1)
    ;
}
