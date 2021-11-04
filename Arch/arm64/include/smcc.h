/*
 * Created Date: Thursday, Nov 5rd 2021, 22:49:55 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#ifndef __CHICORYOS_ARCH_SMCC__
#define __CHICORYOS_ARCH_SMCC__
#include "../../../Kernel/include/stddef.h"

uint64_t smc_call(uint64_t r0, ...);

#endif /* __CHICORYOS_ARCH_SMCC__ */
