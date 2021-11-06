/*
 * Created Date: Tuesday, Nov 01st 2021, 23:56:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "../Kernel/include/console.h"
#include "../Kernel/include/device.h"

volatile uint32_t uart_init_done = 0;

void hypervisor_start_primary() {
  init_early_devices();
  uart_init_done = 1;
  Console *console = console_get();
  console->put(console, "Hypervisor primary start.\n");

  init_key_devices();
  while (1)
    ;

}

void hypervisor_start_secondary() {

  while (uart_init_done == 0)
  {
    /* code */
  }

  Console *console = console_get();
  console->put(console, "Hypervisor secondary start.\n");

  while (1)
    ;

}
