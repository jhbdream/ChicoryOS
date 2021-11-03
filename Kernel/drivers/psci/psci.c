/*
 * Created Date: Wednesday, Nov 03st 2021, 21:26:39 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#include "../../include/device.h"
#include "../../include/power_manager.h"

int32_t psci_get_version(void) {
  // @todo: inplement me
  return 0;
}

int32_t psci_cpu_suspend(uint32_t power_state, uint64_t entry_point_address, uint64_t context_id) {
  // @todo: inplement me
  return 0;
}

int32_t psci_cpu_off(void) {
  // @todo: inplement me
  return 0;
}

int32_t psci_cpu_on(uint64_t target_cpu, uint64_t entry_point_address, uint64_t context_id) {
  // @todo: inplement me
  return 0;
}

int32_t psci_affinity_info(uint64_t target_affinity, uint32_t lowest_affinity_level) {
  // @todo: inplement me
  return 0;
}

int32_t psci_migrate(uint64_t target_cpu) {
  // @todo: inplement me
  return 0;
}

int32_t psci_migrate_info_type(void) {
  // @todo: inplement me
  return 0;
}

int32_t psci_migrate_info_up_cpu(void) {
  // @todo: inplement me
  return 0;
}

void psci_system_off(void) {
  // @todo: inplement me
}

void psci_system_reset(void) {
  // @todo: inplement me
}

int32_t psci_system_reset2(uint32_t reset_type, uint64_t cookie) {
  // @todo: inplement me
  return 0;
}

int32_t psci_mem_protect(uint32_t enable) {
  // @todo: inplement me
  return 0;
}

int32_t psci_mem_protect_check_range(uint64_t base, uint64_t len) {
  // @todo: inplement me
  return 0;
}

int32_t psci_features(uint32_t psci_func_id) {
  // @todo: inplement me
  return 0;
}

int32_t psci_cpu_freeze(void) { 
  // @todo: inplement me
  return 0;
}

int32_t psci_cpu_default_suspend(uint64_t entry_point_address, uint64_t context_id) {
  // @todo: inplement me
  return 0;
}

int32_t psci_node_hw_state(uint64_t target_cpu, uint32_t power_level) {
  // @todo: inplement me
  return 0;
}

int32_t psci_system_suspend(uint64_t entry_point_address, uint64_t context_id) {
  // @todo: inplement me
  return 0;
}

int32_t psci_set_suspend_mode(uint32_t mode) {
  // @todo: inplement me
  return 0;
}

uint64_t psci_stat_residency(uint64_t terget_cpu, uint32_t power_state) {
  // @todo: inplement me
  return 0;
}

uint64_t psci_stat_count(uint64_t target_cpu, uint32_t power_state) {
  // @todo: inplement me
  return 0;
}

static PowerManager psci = {
  .ops = {
    .getVersion = psci_get_version,
    .cpuSuspend = psci_cpu_suspend,
    .cpuOff = psci_cpu_off,
    .cpuOn = psci_cpu_on,
    .affinityInfo = psci_affinity_info,
    .migrate = psci_migrate,
    .migrateInfoType = psci_migrate_info_type,
    .migrateInfoUpCpu = psci_migrate_info_up_cpu,
    .systemOff = psci_system_off,
    .systemReset = psci_system_reset,
    .systemReset2 = psci_system_reset2,
    .memProtect = psci_mem_protect,
    .memProtectCheckRange = psci_mem_protect_check_range,
    .features = psci_features,
    .cpuFreeze = psci_cpu_freeze,
    .cpuDefaultSuspend = psci_cpu_default_suspend,
    .nodeHwState = psci_node_hw_state,
    .systemSuspend = psci_system_suspend,
    .setSuspendMode = psci_set_suspend_mode,
    .statResidency = psci_stat_residency,
    .statCount = psci_stat_count,
  }
};

void psci_probe(DeviceDesc *desc, DeviceNode *node) {
  register_power_manager(&psci);
}

static DeviceDesc psci_desc = {.compatible = "arm,psci",
                                .doProbe = &psci_probe};

int psci_init(void *args) {
  register_device(&psci_desc);
  return 0;
}

key_device_init(psci_init)
