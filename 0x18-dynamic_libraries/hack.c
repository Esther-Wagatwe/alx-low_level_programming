#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int printf(const char *format, ...)
{
	void (*real_printf)(const char *format, ...) = dlsym(RTLD_NEXT, "printf");
	real_printf("9 8 10 24 75 - 9\n");
	real_printf("Congratulations, you win the Jackpot!\n");
	exit(EXIT_SUCCESS);
}
