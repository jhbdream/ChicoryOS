#include "../include/register.h"
#include "../include/common.h"

.global _start
_start:
	mrs x1, CurrentEL

	cmp x1, 0xC
	beq init_securiy_monitor

	cmp x1, 0x8
	beq init_hypervisor

_halt:
	b _halt;

init_securiy_monitor:
	mov x1, #0
	orr x1, x1, #SCR_EL3_NS 
	orr x1, x1, #SCR_EL3_HCE
	orr x1, x1, #SCR_EL3_RW
	msr scr_el3, x1

	mov x1, #0
	orr x1, x1, #SPSR_EL3_D
	orr x1, x1, #SPSR_EL3_A
	orr x1, x1, #SPSR_EL3_I
	orr x1, x1, #SPSR_EL3_F
	orr x1, x1, #0x8
	orr x1, x1, #0x1
	msr spsr_el3, x1

	adr x1, init_hypervisor
	msr elr_el3, x1
	eret

init_hypervisor:
	mrs x1, mpidr_el1
	and x1, x1, #MPIDR_CPU_ID_MASK

	mov x3, #STACK_SIZE
	mul x4, x1, x3
	ldr x2, =__stack_base
	sub x2, x2, x4
	mov sp, x2

	cbnz x1, hypervisor_start_secondary

	b hypervisor_start_primary
