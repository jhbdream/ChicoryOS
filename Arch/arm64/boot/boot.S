.global _start
_start:
	mrs x1, CurrentEL

	cmp x1, 0xC
	beq init_securiy_monitor

	cmp x1, 0x8
	beq init_hypervisor

	ldr x1, =__stack_base
	mov sp, x1
	mov x0, #1
	b _kernel_entry


init_securiy_monitor:
	ldr x1, =__stack_base
	mov sp, x1
	mov x0, #3
	b _kernel_entry

init_hypervisor:
	ldr x1, =__stack_base
	mov sp, x1
	mov x0, #2
	b _kernel_entry
