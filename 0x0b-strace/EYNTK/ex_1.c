#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <stdio.h>

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
			printf("syscall ");
			ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
			wait(&status);
			if (WIFEXITED(status))
				printf("Exit status: %d\n", WEXITSTATUS(status));
			else
				printf("return\n");
		}

	}
	return (0);
}
