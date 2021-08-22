volatile unsigned int * const UART0DR = (unsigned int *) 0x09000000;
int _kernel_entry(void* argv){
	while(1){
		*UART0DR = 'y';
	}
}