#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"
#define S4  "H"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strncmp(S1, S3, 1) == asm_strncmp(S1, S3, 1));
	assert(strncmp(S1, S3, 11) == asm_strncmp(S1, S3, 11));
	assert(strncmp(S1, S3, 15) == asm_strncmp(S1, S3, 15));
	assert(strncmp(S2, S1, 10) == asm_strncmp(S2, S1, 10));
	assert(strncmp(S2, S4, 2) == asm_strncmp(S2, S4, 2));
	assert(strncmp(S1, S2, 1) == asm_strncmp(S1, S2, 1));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
