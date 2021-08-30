//
// Created by neroyang on 2021/8/30.
//

#ifndef __SYNESTIAOS_BREEZY_GIC400_H__
#define __SYNESTIAOS_BREEZY_GIC400_H__
#include "../../include/dlist.h"

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
    // https://developer.arm.com/documentation/ddi0471/b/programmers-model/distributor-register-summary
} GICDistributor;

#endif /* __SYNESTIAOS_BREEZY_GIC400_H__ */
