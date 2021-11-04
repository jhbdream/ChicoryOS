/*
 * Created Date: Monday, August 23rd 2021, 12:13:22 am
 * Author: neroyang
 *
 * Copyright (c) 2021 SynestiaOS
 */

#ifndef __SYNESTIAOS_ARCH_ARM64_REGISTER__
#define __SYNESTIAOS_ARCH_ARM64_REGISTER__

/**
 * 0b0: Indicates that EL0 and EL1 are in Secure state
 * 0b1: Indicates that Exception lower than EL3 are in
 *      Non-secure state, so memory accesses from those
 *      Exception levels cannot access Secure memory.
 */
#define SCR_EL3_NS (1 << 0) 
#define SCR_EL3_IRQ (1 << 1)
#define SCR_EL3_FIQ (1 << 2)

/**
 * 0b0: SMC instructions are enabled at EL3,El2,EL1
 * 0b1: SMC instructions are UNDEFINED
 */
#define SCR_EL3_SMD (1 << 7)

/**
 * 0b0: HVC instructions are UNDEFINED
 * 0b1: HVC instructions are enabled at EL3,EL2,EL1
 */
#define SCR_EL3_HCE (1 << 8)
#define SCR_EL3_SIF (1 << 9)
#define SCR_EL3_RW (1 << 10)
#define SCR_EL3_ST (1 << 11)
#define SCR_EL3_TWI (1 << 12)
#define SCR_EL3_TWE (1 << 13)
#define SCR_EL3_TLOR (1 << 14)
#define SCR_EL3_TERR (1 << 15)
#define SCR_EL3_APK (1 << 16)
#define SCR_EL3_API (1 << 17)
#define SCR_EL3_EEL2 (1 << 18)
#define SCR_EL3_EASE (1 << 19)
#define SCR_EL3_NMEA (1 << 20)
#define SCR_EL3_FIEN (1 << 21)
#define SCR_EL3_EnSCXT (1 << 25)
#define SCR_EL3_ATA (1 << 26)
#define SCR_EL3_FGTEn (1 << 27)
#define SCR_EL3_ECVEn (1 << 28)
#define SCR_EL3_TWEDEn (1 << 29)
#define SCR_EL3_TWEDEL (1 << 30)
#define SCR_EL3_AMVOFFEN (1 << 35)
#define SCR_EL3_EnAS0 (1 << 36)
#define SCR_EL3_ADEn (1 << 37)
#define SCR_EL3_HXEn (1 << 38)

#define SPSR_EL3_D (1 << 9)
#define SPSR_EL3_A (1 << 8)
#define SPSR_EL3_I (1 << 7)
#define SPSR_EL3_F (1 << 6)

#define SPSR_EL3_M_EL0t 0x0
#define SPSR_EL3_M_EL1t 0x4
#define SPSR_EL3_M_EL1h 0x5
#define SPSR_EL3_M_EL2t 0x8
#define SPSR_EL3_M_EL2h 0x9
#define SPSR_EL3_M_EL3t 0xC
#define SPSR_EL3_M_EL3h 0xD

#define MPIDR_CPU_ID_MASK 0xFF

#define read_reg(reg)                                 \
  static int read_reg_##reg##() {                     \
    int value;                                        \
    asm volatile("msr " #reg #", %0" : : "r"(value)); \
    asm volatile("" : : : "memory");                  \
    return value;                                     \
  }

#endif /* __SYNESTIAOS_ARCH_ARM64_REGISTER__ */
