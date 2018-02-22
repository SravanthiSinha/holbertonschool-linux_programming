#include "strace.h"

/**
 * handle_syscall_open - Resolves flags and macros for open syscall
 * @arg: argument of the syscall
 */
void handle_syscall_open(unsigned long arg)
{
	if (arg & O_WRONLY)
		printf("%s", "O_WRONLY");
	else if (arg & O_RDWR)
		printf("%s", "O_RDWR");
	else
		printf("%s", "O_RDONLY");
	if (arg & O_CLOEXEC)
		printf("|%s", "O_CLOEXEC");
	if (arg & O_CREAT)
		printf("|%s", "O_CREAT");
	if (arg & O_DIRECTORY)
		printf("|%s", "O_DIRECTORY");
	if (arg & O_EXCL)
		printf("|%s", "O_EXCL");
	if (arg & O_NOCTTY)
		printf("|%s", "O_NOCTTY");
	if (arg & O_NOFOLLOW)
		printf("|%s", "O_NOFOLLOW");
	if (arg & O_TRUNC)
		printf("|%s", "O_TRUNC");
}

/**
 * handle_syscall_mmap - Resolves flags and macros for mmap syscall
 * @arg: argument of the syscall
 * @arg_index: index of the argument
 */
void handle_syscall_mmap(int arg_index, unsigned long arg)
{
	bool bitwised = false;

	if (arg_index == 2)
	{
		if (arg & PROT_READ)
		{
			if (bitwised)
				printf("|");
			printf("%s", "PROT_READ");
			bitwised = true;
		}
		if (arg & PROT_WRITE)
		{
			if (bitwised)
				printf("|");
			printf("%s", "PROT_WRITE");
			bitwised = true;
		}
		if (arg & PROT_EXEC)
		{
			if (bitwised)
				printf("|");
			printf("%s", "PROT_EXEC");
			bitwised = true;
		}
		if (arg & PROT_NONE)
		{
			if (bitwised)
				printf("|");
			printf("%s", "PROT_NONE");
		}
	} else
	{
		if (arg & MAP_SHARED)
			printf("%s", "MAP_SHARED");
		else if (arg & MAP_PRIVATE)
			printf("%s", "MAP_PRIVATE");
		if (arg & MAP_32BIT)
			printf("|%s", "MAP_32BIT");
		if (arg & MAP_FIXED)
			printf("|%s", "MAP_FIXED");
		if (arg & MAP_FILE)
			printf("|%s", "MAP_FILE");
		if (arg & MAP_ANON)
			printf("|%s", "MAP_ANONYMOUS");
		else if (arg & MAP_ANONYMOUS)
			printf("|%s", "MAP_ANONYMOUS");
		if (arg & MAP_DENYWRITE)
			printf("|%s", "MAP_DENYWRITE");
		if (arg & MAP_EXECUTABLE)
			printf("|%s", "MAP_EXECUTABLE");
		if (arg & MAP_GROWSDOWN)
			printf("|%s", "MAP_GROWSDOWN");
		if (arg & MAP_HUGETLB)
			printf("|%s", "MAP_HUGETLB");
		if (arg & MAP_LOCKED)
			printf("|%s", "MAP_LOCKED");
		if (arg & MAP_NONBLOCK)
			printf("|%s", "MAP_NONBLOCK");
		if (arg & MAP_NORESERVE)
			printf("|%s", "MAP_NORESERVE");
		if (arg & MAP_POPULATE)
			printf("|%s", "MAP_POPULATE");
		if (arg & MAP_STACK)
			printf("|%s", "MAP_STACK");
	}
}

/**
 * handle_syscall_access - Resolves flags and macros for access syscall
 * @arg: argument of the syscall
 */
void handle_syscall_access(unsigned long arg)
{
	switch (arg)
	{
	case F_OK:
		printf("%s", "F_OK");
		break;
	case R_OK:
		printf("%s", "R_OK");
		break;
	case W_OK:
		printf("%s", "W_OK");
		break;
	case X_OK:
		printf("%s", "X_OK");
		break;
	case R_OK | W_OK:
		printf("%s", "R_OK|W_OK");
		break;
	case W_OK | X_OK:
		printf("%s", "W_OK|X_OK");
		break;
	case R_OK | X_OK:
		printf("%s", "R_OK|X_OK");
		break;
	case R_OK | W_OK | X_OK:
		printf("%s", "R_OK|W_OK|X_OK");
		break;
	}
}

/**
 * handle_syscall_macros - Resolves flags and macros for specific syscalls
 * @name: name of the syscall
 * @arg: argument of the syscall
 * @arg_index: index of the argument
 */
void handle_syscall_macros(const char *name, unsigned long arg, int arg_index)
{

	if (!strcmp(name, "mmap"))
		handle_syscall_mmap(arg_index, arg);
	else if (!strcmp(name, "access"))
		handle_syscall_access(arg);
	else if (!strcmp(name, "open"))
		handle_syscall_open(arg);
}
