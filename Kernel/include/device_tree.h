/*
 * Created Date: Monday, August 23rd 2021, 10:01:10 pm
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */

#ifndef __SYNESTIAOS_KERNEL_DEVICE_TREE__
#define __SYNESTIAOS_KERNEL_DEVICE_TREE__

typedef struct DeviceNode {
	// TODO:
} DeviceNode;

DeviceNode* device_tree_find_by_compatible(char* compatible);

#endif /* __SYNESTIAOS_KERNEL_DEVICE_TREE__ */
