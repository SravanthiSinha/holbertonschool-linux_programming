#include "strace.h"

/**
 * is_machine_32 - evaluates if machine is 32 or 64 bit
 * Return: true if 32, else false
 */
bool is_machine_32(void)
{
	struct utsname buffer;

	errno = 0;
	if (uname(&buffer) != 0)
	{
		perror("uname");
		exit(EXIT_FAILURE);
	}
	if (strcmp(buffer.machine, "x86_64") == 0)
		return (false);
	if (strcmp(buffer.machine, "i686") == 0)
		return (true);
	return (false);
}


/**
 * get_syscall_arg - fetches the parameter to the syscall
 * @regs: structure containing registers info
 * @n: which parameter
 * Return: nth argument/ parameter
 */
unsigned long get_syscall_arg(struct user_regs_struct regs, int n)
{
	switch (n)
	{
#ifdef __amd64__
	case 0:
		return ((unsigned long)regs.rdi);
	case 1:
		return ((unsigned long)regs.rsi);
	case 2:
		return ((unsigned long)regs.rdx);
	case 3:
		return ((unsigned long)regs.r10);
	case 4:
		return ((unsigned long)regs.r8);
	case 5:
		return ((unsigned long)regs.r9);
#else
	case 0:
		return ((unsigned long)regs.ebx);
	case 1:
		return ((unsigned long)regs.ecx);
	case 2:
		return ((unsigned long)regs.edx);
	case 3:
		return ((unsigned long)regs.esi);
	case 4:
		return ((unsigned long)regs.edi);
	case 5:
		return ((unsigned long)regs.ebp);
#endif
	default:
		return (-1L);
	}
}
