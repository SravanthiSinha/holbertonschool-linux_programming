#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <stdio.h>

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

	child_pid = fork();
	if (child_pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execve(argv[1], argv + 1, NULL);
	} else
	{
		wait(&status);
		while (WIFSTOPPED(status))
		{
			ptrace(PTRACE_SINGLESTEP, child_pid, 0, 0);
			printf("single step\n");
			wait(&status);
		}
		printf("Exit status: %d\n", WEXITSTATUS(status));
	}
	return (0);
}
