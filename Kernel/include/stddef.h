/*
 * Created Date: Monday, August 23rd 2021, 8:49:11 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#ifndef __CHICORYOS_KERNEL_STDDEF__
#define __CHICORYOS_KERNEL_STDDEF__

#define KERNEL_NAME_LEN 32

#define NULL (void *)0
#define E_ERR (-1)
#define E_OK 0

typedef unsigned long *Pointer;

typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long uint64_t;
typedef long int64_t;

#endif /* __CHICORYOS_KERNEL_STDDEF__ */
