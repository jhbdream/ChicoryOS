/*
 * Created Date: Tuesday, Nov 01st 2021, 23:56:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "../Kernel/include/console.h"
#include "../Kernel/include/device.h"

void hypervisor_start_primary() {
  init_early_devices();
  Console *console = console_get();
  console->put(console, "Hypervisor primary start.\n");
  
  init_key_devices();
  while (1)
    ;

}

void hypervisor_start_secondary() {
  init_early_devices();
  Console *console = console_get();
  console->put(console, "Hypervisor secondary start.\n");

  while (1)
    ;

}
