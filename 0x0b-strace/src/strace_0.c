#include "strace.h"

/**
 * run_tracee -  A function that runs a tracee
 * @argv: Has path and arguments to be executed
 * @envp: environment variables
 */
void run_tracee(char *const argv[], char *const envp[])
{
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
	{
		perror("Error setting TRACEME");
		exit(EXIT_FAILURE);
	}
	kill(getpid(), SIGSTOP);
	execve(argv[0], argv, envp);
}

/**
 * wait_for_syscall -  A function that traps only syscalls
 * @child_pid: pid of the tracee to be traced
 * Return: 1 if syscall is trapped else 0
 */
int wait_for_syscall(pid_t child_pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
		waitpid(child_pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		if (WIFEXITED(status))
			return (1);
	}
}

/**
 * run_tracer -  A function that runs a tracer
 * @child_pid: pid of the tracee to be traced
 */
void run_tracer(pid_t child_pid)
{
	int status;
	struct user_regs_struct regs;

	waitpid(child_pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (wait_for_syscall(child_pid) != 0)
			break;
		ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
		printf("%ld\n", (size_t) regs.orig_rax);
		fflush(stdout);
		if (wait_for_syscall(child_pid) != 0)
			break;
	}
}

/**
 * main - Starts the program
 * @argc : no of command line arguments
 * @argv: command line arguments
 * @envp: environment variables
 * Return: on success - EXIT_SUCCESS, on failure - EXIT_FAILURE
 */
int main(int argc, char *const argv[], char *const envp[])
{
	pid_t child_pid;

	if (argc < 2)
		printf("Usage: %s command [args...]\n", argv[0]);
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			run_tracee(argv + 1, envp);
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
