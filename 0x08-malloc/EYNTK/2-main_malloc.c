#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i;

	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		str = malloc(10);
		strcpy(str, "Holberton");
		str[9] = '\0';
		printf("%p: %s, ", (void *)str, str);
		printf("program break: %p\n", sbrk(0));

	}

	printf("Final break is %p\n", sbrk(0));
	return (EXIT_SUCCESS);
}
