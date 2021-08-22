ENTRY(_start)

SECTIONS {
	
	__text_start = .;
	.text :
	{
		KEEP(*(.exception_table))
		KEEP(*(.text.boot))
		*(.text)
	}
	. = ALIGN(4096);
	__test_end = .;

	__rodata_start = .;
	.rodata :
	{
		*(.rodata)
	}
	. = ALIGN(4096);
	__rodata_end = .;

	__data_start = .;
	.data :
	{
		*(.data)
	}
	. = ALIGN(4096);
	__data_end = .;

	__bss_start = .;
	.bss :
	{
		*(.bss)
	}
	. = ALIGN(4096);
	__bss_end = .;

	. = 0x8000 + __bss_end;
    __stack_base = .;
}