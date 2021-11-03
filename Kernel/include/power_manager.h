/*
 * Created Date: Monday, August 23rd 2021, 22:34:55 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#ifndef __CHICORYOS_KERNEL_POWERMANAGER__
#define __CHICORYOS_KERNEL_POWERMANAGER__
#include "dlist.h"
#include "stddef.h"

typedef int32_t (*PSCIGetVersion)(void);
typedef int32_t (*PSCICpuSuspend)(uint32_t power_state, uint64_t entry_point_address, uint64_t context_id);
typedef int32_t (*PSCICpuOff)(void);
typedef int32_t (*PSCICpuOn)(uint64_t target_cpu, uint64_t entry_point_address, uint64_t context_id);
typedef int32_t (*PSCIAffinityInfo)(uint64_t target_affinity, uint32_t lowest_affinity_level);
typedef int32_t (*PSCIMigrate)(uint64_t target_cpu);
typedef int32_t (*PSCIMigrateInfoType)(void);
typedef int32_t (*PSCIMigrateInfoUpCpu)(void);
typedef void (*PSCISystemOff)(void);
typedef void (*PSCISystemReset)(void);
typedef int32_t (*PSCISystemReset2)(uint32_t reset_type, uint64_t cookie);
typedef int32_t (*PSCIMemProtect)(uint32_t enable);
typedef int32_t (*PSCIMemProtectCheckRange)(uint64_t base, uint64_t len);
typedef int32_t (*PSCIFeatures)(uint32_t psci_func_id);
typedef int32_t (*PSCICpuFreeze)(void);
typedef int32_t (*PSCICpuDefaultSuspend)(uint64_t entry_point_address, uint64_t context_id);
typedef int32_t (*PSCINodeHwState)(uint64_t target_cpu, uint32_t power_level);
typedef int32_t (*PSCISystemSuspend)(uint64_t entry_point_address, uint64_t context_id);
typedef int32_t (*PSCISetSuspendMode)(uint32_t mode);
typedef uint64_t (*PSCIStatResidency)(uint64_t terget_cpu, uint32_t power_state);
typedef uint64_t (*PSCIStatCount)(uint64_t target_cpu, uint32_t power_state);

struct PowerManagerOps {
  PSCIGetVersion getVersion;
  PSCICpuSuspend cpuSuspend;
  PSCICpuOff cpuOff;
  PSCICpuOn cpuOn;
  PSCIAffinityInfo affinityInfo;
  PSCIMigrate migrate;
  PSCIMigrateInfoType migrateInfoType;
  PSCIMigrateInfoUpCpu migrateInfoUpCpu;
  PSCISystemOff systemOff;
  PSCISystemReset systemReset;
  PSCISystemReset2 systemReset2;
  PSCIMemProtect memProtect;
  PSCIMemProtectCheckRange memProtectCheckRange;
  PSCIFeatures features;
  PSCICpuFreeze cpuFreeze;
  PSCICpuDefaultSuspend cpuDefaultSuspend;
  PSCINodeHwState nodeHwState;
  PSCISystemSuspend systemSuspend;
  PSCISetSuspendMode setSuspendMode;
  PSCIStatResidency statResidency;
  PSCIStatCount statCount;
};

typedef struct PowerManager {
  ListNode node;
  struct PowerManagerOps ops;
} PowerManager;

void register_power_manager(PowerManager *power_manager);
PowerManager *power_manager_get();
int32_t power_manager_cpu_on(uint64_t target_cpu, uint64_t entry_point_address, uint64_t context_id);
#endif /* __CHICORYOS_KERNEL_POWERMANAGER__ */
