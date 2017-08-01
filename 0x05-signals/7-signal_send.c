#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


/**
 * main -  a program that sends the signal SIGINT to a process, given its PID
 * @argc: No of command line args
 * @argv : command line args
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
