#include "strace.h"

/**
 * is_machine_32 - estruates if machine is 32 or 64 bit
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

/**
 * read_string - Returns the string stored in the memory @addr
 * @child_pid: pid of the process
 * @addr: address to be looked in
 * Return: string stored in memory
 */
char *read_string(pid_t child_pid, unsigned long addr)
{

	/*
	 *points to the beginning of the memory, which is used later to read
	 *the string
	 */
	char *str = malloc(4096);
	unsigned int allocated = 4096;
	unsigned long read = 0;
	unsigned long tmp;

	while (1)
	{
		/**
		 *Since ptrace() reads and returns only 8 bytes at a time,
		 *we need to do this iteratively
		 */
		if (read + sizeof(tmp) > allocated)
		{
			allocated *= 2;
			str = realloc(str, allocated);
		}
		tmp = ptrace(PTRACE_PEEKDATA, child_pid, addr + read);
		if (errno != 0)
		{
			str[read] = 0;
			break;
		}
		memcpy(str + read, &tmp, sizeof(tmp));
		if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
			break;
		read += sizeof(tmp);
	}
	return (str);
}

/**
 * print_arg - prints the argument based on its type
 * @arg: argument to be printed
 * @arg_type: type of the argument
 * @deal_null: To reolve NULL
 */
void print_arg(unsigned long arg, type_t arg_type, bool deal_null)
{
	switch (arg_type)
	{
	case INT:
		printf("%d", (int)arg);
		break;
	case LONG:
		printf("%ld", (long)arg);
		break;
	case SIZE_T:
		printf("%ld", (size_t) arg);
		break;
	case SSIZE_T:
		printf("%ld", (ssize_t) arg);
		break;
	case U64:
		printf("%lu", (unsigned long)arg);
		break;
	case UINT32_T:
		printf("%d", (uint32_t) arg);
		break;
	case UNSIGNED_INT:
		printf("%du", (unsigned int)arg);
		break;
	case UNSIGNED_LONG:
		printf("%lu", (unsigned long)arg);
		break;
	case PID_T:
		printf("%d", (pid_t) arg);
		break;
	default:
		if (deal_null && !arg)
			printf("NULL");
		else
			printf("%#lx", arg);
		break;
	}
}
