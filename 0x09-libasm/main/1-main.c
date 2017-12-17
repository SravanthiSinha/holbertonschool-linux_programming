#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"
#define S4  "H"
#define S5  "Ho"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcmp(S1, S1) == asm_strcmp(S1, S1));
	assert(strcmp(S1, S2) == asm_strcmp(S1, S2));
	assert(strcmp(S1, S3) == asm_strcmp(S1, S3));
	assert(strcmp(S1, S4) == asm_strcmp(S1, S4));
	assert(strcmp(S2, S1) == asm_strcmp(S2, S1));
	assert(strcmp(S5, S1) == asm_strcmp(S5, S1));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
