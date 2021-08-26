/*
 * Created Date: Monday, August 23rd 2021, 12:13:22 am
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */

#ifndef __SYNESTIAOS_ARCH_ARM64_REGISTER__
#define __SYNESTIAOS_ARCH_ARM64_REGISTER__

#define read_reg(reg) static int read_reg_##reg##(){    \
    int value;                                          \
    asm volatile ("msr "#reg#", %0" : : "r" (value));   \
    asm volatile ("" : : : "memory");                   \
    return value;                                       \
}

read_reg(test)

#endif /* __SYNESTIAOS_ARCH_ARM64_REGISTER__ */