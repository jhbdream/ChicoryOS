/*
 * Created Date: Monday, August 23rd 2021, 12:13:22 am
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */

#ifndef __SYNESTIAOS_ARCH_ARM64_REGISTER__
#define __SYNESTIAOS_ARCH_ARM64_REGISTER__

int read_reg(const char* reg);
int write_reg(const char* reg, int data);

#endif /* __SYNESTIAOS_ARCH_ARM64_REGISTER__ */