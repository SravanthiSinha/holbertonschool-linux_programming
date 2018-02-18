#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/user.h>

/**
 * main - Starts the program
 * @argc : no of command line arguments
 * @argv: command line arguments
 * Return: on success - 0, on failure - 1
 */
int main(int __attribute__ ((unused)) argc, char **argv)
{
	pid_t child_pid;
	int status;
	struct user_regs_struct regs;

	child_pid = fork();
	if (child_pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execve(argv[1], argv + 1, NULL);
	} else
	{
		while (wait(&status) && !WIFEXITED(status))
		{
			ptrace(PTRACE_GETREGS, child_pid, 0,  &regs);
			printf("%ld\n", (size_t)regs.orig_rax);
			ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		}
		printf("Exit status: %d\n", WEXITSTATUS(status));

	}
	return (0);
}
