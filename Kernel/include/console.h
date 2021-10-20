/*
 * Created Date: Monday, August 23rd 2021, 10:23:23 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 SynestiaOS
 */

#ifndef __SYNESTIAOS_KERNEL_CONSOLE__
#define __SYNESTIAOS_KERNEL_CONSOLE__
#include "dlist.h"

struct Console;
typedef void (*ConsolePutFunc)(struct Console *console, char *str);

typedef struct Console {
  ListNode node;
  ConsolePutFunc put;
} Console;

void register_console(Console *console);
Console *console_get();

#endif /* __SYNESTIAOS_KERNEL_CONSOLE__ */
