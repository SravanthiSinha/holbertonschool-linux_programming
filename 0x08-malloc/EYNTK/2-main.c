#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *naive_malloc(size_t size);

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
		str = naive_malloc(10);
		strcpy(str, "Holberton");
		str[9] = '\0';
		printf("%p: %s\n", (void *)str, str);
	}

	printf("Final break is %p\n", sbrk(0));
	return (EXIT_SUCCESS);
}
