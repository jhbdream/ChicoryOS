//
// Created by neroyang on 2021/8/30.
// https://developer.arm.com/documentation/ddi0471/b/programmers-model/distributor-register-summary
//

#ifndef __SYNESTIAOS_BREEZY_GIC400_H__
#define __SYNESTIAOS_BREEZY_GIC400_H__

#include "../../include/dlist.h"

#define GIC_400_GICD_CTLR_OFFSET 0x000    // Distributor Control Register
#define GIC_400_GICD_TYPER_OFFSET 0x004   // Interrupt Controller Type Register
#define GIC_400_GICD_IIDR_OFFSET 0x008    // Distributor Implementer Identification Register, GICD_IIDR
#define GIC_400_GICD_IGROUPRn_OFFSET 0x080 // Interrupt Group Registers
#define GIC_400_GICD_IGROUPRn_END 0x0BC
#define GIC_400_GICD_ISENABLERn_OFFSET 0x100 // Interrupt Set-Enable Registers
#define GIC_400_GICD_ISENABLERn_END 0x13C
#define GIC_400_GICD_ICENABLERn_OFFSET 0x180 // Interrupt Clear-Enable Registers
#define GIC_400_GICD_ICENABLERn_END 0x1BC
#define GIC_400_GICD_ISPENDRn_OFFSET 0x200 // Interrupt Set-Pending Registers
#define GIC_400_GICD_ISPENDRn_END 0x23C
#define GIC_400_GICD_GICD_ICPENDRn_OFFSET 0x280 // Interrupt Clear-Pending Registers
#define GIC_400_GICD_GICD_ICPENDRn_END 0x2BC
#define GIC_400_GICD_ISACTIVERn_OFFSET 0x300 // Interrupt Set-Active Registers
#define GIC_400_GICD_ISACTIVERn_END 0x33C
#define GIC_400_GICD_ICACTIVERn_OFFSET 0x380 // Interrupt Clear-Active Registers
#define GIC_400_GICD_ICACTIVERn_END 0x3BC
#define GIC_400_GICD_IPRIORITYRn_OFFSET 0x400 // Interrupt Priority Registers
#define GIC_400_GICD_IPRIORITYRn_END 0x5FC
#define GIC_400_GICD_ITARGETSRn_OFFSET 0x800 // Interrupt Processor Targets Registers
#define GIC_400_GICD_ITARGETSRn_END 0x9FC
#define GIC_400_GICD_ICFGRn_OFFSET 0xC00 // Interrupt Configuration Registers
#define GIC_400_GICD_ICFGRn_END 0xC7C
#define GIC_400_GICD_PPISR_OFFSET 0xD00 // Private Peripheral Interrupt Status Register
#define GIC_400_GICD_GICD_SPISRn_OFFSET 0xD04 // Shared Peripheral Interrupt Status Registers
#define GIC_400_GICD_GICD_SPISRn_END 0xD3C
#define GIC_400_GICD_SGIR_OFFSET 0xF00 // Software Generated Interrupt Register
#define GIC_400_GICD_CPENDSGIRn_OFFSET 0xF10 // SGI Clear-Pending Registers
#define GIC_400_GICD_CPENDSGIRn_END 0xF1C
#define GIC_400_GICD_SPENDSGIRn_OFFSET 0xF20 // SGI Set-Pending Registers
#define GIC_400_GICD_SPENDSGIRn_END 0xF2C
#define GIC_400_GICD_PIDR4_OFFSET 0xFD0 // Peripheral ID 4 Register
#define GIC_400_GICD_PIDR5_OFFSET 0xFD4 // Peripheral ID 5 Register
#define GIC_400_GICD_PIDR6_OFFSET 0xFD8 // Peripheral ID 6 Register
#define GIC_400_GICD_PIDR7_OFFSET 0xFDC // Peripheral ID 7 Register
#define GIC_400_GICD_PIDR0_OFFSET 0xFE0 // Peripheral ID 0 Register
#define GIC_400_GICD_PIDR1_OFFSET 0xFE4 // Peripheral ID 1 Register
#define GIC_400_GICD_PIDR2_OFFSET 0xFE8 // Peripheral ID 2 Register
#define GIC_400_GICD_PIDR3_OFFSET 0xFEC // Peripheral ID 3 Register
#define GIC_400_GICD_CIDR0_OFFSET 0xFF0 // Component ID 0 Register
#define GIC_400_GICD_CIDR1_OFFSET 0xFF4 // Component ID 1 Register
#define GIC_400_GICD_CIDR2_OFFSET 0xFF8 // Component ID 2 Register
#define GIC_400_GICD_CIDR3_OFFSET 0xFFC // Component ID 3 Register

typedef struct GIC_GICD_IIDR {
    int productID: 8;
    int reserved: 4;
    int variant: 4;
    int revision: 4;
    int implementer: 12;
} __attribute__((packed)) GIC_GICD_IIDR;

typedef struct GICDistributor {
    int GICD_CTLR;
    int GICD_TYPER;
    GIC_GICD_IIDR GICD_IIDR;
    int reserved1[0xF];
    int GICD_IGROUPRn[0xF];
    int reserved2[0x11];
    int GICD_ISENABLERn[0xF];
    int reserved3[0x11];
    int GICD_ICENABLERn[0xF];
    int reserved4[0x11];
    int GICD_ISPENDRn[0xF];
    int reserved5[0x11];
    int GICD_ICPENDRn[0xF];
    int reserved6[0x11];
    int GICD_ISACTIVERn[0xF];
    int reserved7[0x11];
    int GICD_ICACTIVERn[0xF];
    int reserved8[0x11];
    int GICD_IPRIORITYRn[0xF];
    int reserved9[0x11];
    int GICD_ITARGETSRn[0xF];
    int reserved10[0x11];
    int GICD_ICFGRn[0xF];
    int reserved11[0x21];
    int GICD_PPISR;
    int GICD_SPISRn[0xF];
    int reserved12[0x71];
    // TODO: it's a boring work, implement register from:
    //
} GICDistributor;

typedef struct GICCPUInterface {
    int GICC_CTLR;
    int GICC_PMR;
    int GICC_BPR;
    int GICC_IAR;
    int GICC_EOIR;
    int GICC_RPR;
    int GICC_HPPIR;
    int GICC_ABPR;
    int GICC_AIAR;
    int GICC_AEOIR;
    int GICC_AHPPIR[(0xD0 - 0x28) / 4];
    int GICC_APR0[(0xE0 - 0xD0) / 4];
    int GICC_NSAPR0[(0xFC - 0xE0) / 4];
    int GICC_IIDR[(0x1000 - 0xFC) / 4];
    int GICC_DIR;
} GICCPUInterface;

typedef struct GICCPUVirutalInterface {
    int GICH_HCR;
    int GICH_VTR;
    int GICH_VMCR;
    int GICH_MISR[(0x20 - 0x10) / 4];
    int GICH_EISR0[(0x30 - 0x20) / 4];
    int GICH_ELSR0[(0xF0 - 0x30) / 4];
    int GICH_APR0[(0x100 - 0xF0) / 4];
    int GICH_LR0;
    int GICH_LR1;
    int GICH_LR2;
    int GICH_LR3;
} GICCPUVirtualInterface;

#endif /* __SYNESTIAOS_BREEZY_GIC400_H__ */
