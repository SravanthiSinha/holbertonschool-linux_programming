#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton"
#define S2  "holberton"
#define S3  "HOLBERTON"

#define A1  "abcdefghijklmnopqrstuvwxyz"
#define A2  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcspn(S2, A1) == asm_strcspn(S2, A1));
	assert(strcspn(S2, A2) == asm_strcspn(S2, A2));
	assert(strcspn(S3, A1) == asm_strcspn(S3, A1));
	assert(strcspn(S3, A2) == asm_strcspn(S3, A2));
	assert(strcspn(S1, A1) == asm_strcspn(S1, A1));
	assert(strcspn(S1, A2) == asm_strcspn(S1, A2));
	assert(strcspn(S1, A1 A2) == asm_strcspn(S1, A1 A2));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
