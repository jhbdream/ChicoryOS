/*
 * Created Date: Monday, August 23rd 2021, 8:51:43 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 ChicoryOS
 */

#ifndef __CHICORYOS_KERNEL_DLIST__
#define __CHICORYOS_KERNEL_DLIST__

typedef struct ListNode {
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

#define OffsetOf(type, member) ((int)((char *)&((type *)0)->member))
#define ContainerOf(ptr, type, member) \
  ((type *)((char *)(ptr) - (char *)(&(((type *)0)->member))))

#endif /* __CHICORYOS_KERNEL_DLIST__ */
