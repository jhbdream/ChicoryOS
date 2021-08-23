/*
 * Created Date: Monday, August 23rd 2021, 12:13:15 am
 * Author: neroyang
 * 
 * Copyright (c) 2021 SynestiaOS
 */

#include "include/register.h"

int read_reg(const char* reg){
	int value;
	asm volatile ("msr cpsr, %0" : : "r" (value));
	asm volatile ("" : : : "memory");
	return value;
}

int write_reg(const char* reg, int data){

}