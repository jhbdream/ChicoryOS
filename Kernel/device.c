/*
 * Created Date: Monday, August 23rd 2021, 10:46:39 pm
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */

#include "include/device.h"

extern EarlyDeviceInitFunc __initcall_init_lv0_start[];
extern EarlyDeviceInitFunc __initcall_init_lv0_end[];

void register_device(DeviceDesc *desc){
	// TODO: search in device tree by compatible
	if(desc->doProbe != NULL){
		desc->doProbe(desc, device_tree_find_by_compatible(desc->compatible));
	}
}

void init_early_devices(){ 
	if(&__initcall_init_lv0_start == &__initcall_init_lv0_end){
		return;
	}
	EarlyDeviceInitFunc* function = NULL;
	for(function = __initcall_init_lv0_start; function < __initcall_init_lv0_end; function++){
	    (*function)(NULL);
	}
}