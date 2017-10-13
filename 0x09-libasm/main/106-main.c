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
#define A3  "()[]{}<>n"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strpbrk(S2, A1) == asm_strpbrk(S2, A1));
	assert(strpbrk(S2, A2) == asm_strpbrk(S2, A2));
	assert(strpbrk(S3, A1) == asm_strpbrk(S3, A1));
	assert(strpbrk(S3, A2) == asm_strpbrk(S3, A2));
	assert(strpbrk(S1, A3) == asm_strpbrk(S1, A3));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
