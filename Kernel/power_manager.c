/*
 * Created Date: Monday, August 23rd 2021, 22:34:55 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "include/power_manager.h"
#include "include/console.h"

static PowerManager *current_power_manager = NULL;

void register_power_manager(PowerManager *power_manager) {
  current_power_manager = power_manager;
  console_get()->put(console_get(), "PSCI registered.\n");
}

PowerManager *power_manager_get() {
  return current_power_manager;
}

int32_t power_manager_cpu_on(uint64_t target_cpu, uint64_t entry_point_address, uint64_t context_id) {
  if (current_power_manager != NULL) {
    return current_power_manager->ops.cpuOn(target_cpu, entry_point_address, context_id);
  }
  return E_OK;
}
