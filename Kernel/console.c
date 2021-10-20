/*
 * Created Date: Monday, August 23rd 2021, 10:29:38 pm
 * Author: neroyang
 *
 * Copyright (c) 2021 SynestiaOS
 */

#include "include/console.h"

void console_dummy_put(Console *console, char *str);

static Console dummy_console = {.put = console_dummy_put};

static Console *current_console = &dummy_console;

void register_console(Console *console) { current_console = console; }

Console *console_get() { return current_console; }

void console_dummy_put(Console *console, char *str) {
  // this just a dummy put func.
}