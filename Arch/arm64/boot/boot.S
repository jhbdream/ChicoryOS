.global _start
_start:
	ldr x1, __stack_base
	mov sp, x1
	
	// initialize the VBAR_EL3
	// ldr	x1, exception_table_el3
	// msr	vbar_el3, x1

	// initialize the VBAR_EL3
	// ldr	x1, exception_table_el2
	// msr	vbar_el2, x1

	// initialize the VBAR_EL1
	// ldr	x1, exception_table_el1
	// msr	vbar_el1, x1

	b _kernel_entry