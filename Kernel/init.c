/*
 * Created Date: Saturday, August 21st 2021, 11:51:39 pm
 * Author: neroyang
 * 
 * Copyright (c) 2021 Your Company
 */

#include "include/device.h"
#include "include/console.h"

int _kernel_entry(void* argv){
	init_early_devices();
	Console* console = console_get();
	console->put(console, "Hello, SynestiaOS.");
	while(1);
}