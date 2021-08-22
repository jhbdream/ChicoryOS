.global _start
_start:
	ldr x1, =__stack_base
	mov sp, x1

	b _kernel_entry