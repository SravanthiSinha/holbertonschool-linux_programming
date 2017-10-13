#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int i;
	char *src = strdup("Holberton");

	for (i = 0; i <= 9; i++)
	{
		char *dest = strdup("......... School");

		assert(asm_memcpy(dest, src, i) == dest);
		printf("%s\n", dest);
		free(dest);
	}
	free(src);
	printf("All good!\n");
	return (EXIT_SUCCESS);
}
