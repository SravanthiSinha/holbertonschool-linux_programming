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
	assert(asm_puts("H") == 1);
	assert(asm_puts("olberton") == 8);
	assert(asm_puts(" School\n") == 8);

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
