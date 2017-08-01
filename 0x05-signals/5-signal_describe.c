#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - A program that prints a description of a given signal
 * @argc: No of command line args
 * @argv : command line args
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}
