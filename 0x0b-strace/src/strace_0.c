#include "strace.h"

/**
 * run_tracee -  A function that runs a tracee
 * @argv: Has path and arguments to be executed
 */
void run_tracee(char **argv)
{
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
	{
		perror("Error setting TRACEME");
		exit(EXIT_FAILURE);
	}
	execve(argv[0], argv, NULL);
}

/**
 * run_tracer -  A function that runs a tracer
 * @child_pid: pid of the tracee to be traced
 */
void run_tracer(pid_t child_pid)
{
	int status;
	struct user_regs_struct regs;

	while (wait(&status) && !WIFEXITED(status))
	{
		if (ptrace(PTRACE_GETREGS, child_pid, 0, &regs) < 0)
		{
			perror("Error setting TRACER");
			exit(EXIT_FAILURE);
		}
		printf("%ld\n", (size_t) regs.orig_rax);
		if (ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL) < 0)
		{
			perror("Error setting syscall tracer");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * main - Starts the program
 * @argc : no of command line arguments
 * @argv: command line arguments
 * Return: on success - EXIT_SUCCESS, on failure - EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	pid_t child_pid;

	if (argc < 2)
		printf("Usage: %s command [args...]\n", argv[0]);
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			run_tracee(argv + 1);
		} else if (child_pid > 0)
		{
			run_tracer(child_pid);
		} else
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
