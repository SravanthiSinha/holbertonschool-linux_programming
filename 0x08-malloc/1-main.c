#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct rec
{
	int i;
	float PI;
	char A;
} RECORD;

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	struct rec *ptr_one;

	ptr_one = (struct rec *)_malloc(sizeof(struct rec));
	ptr_one->i = 10;
	ptr_one->PI = 3.14;
	ptr_one->A = 'a';

	printf("First value: %d\n", ptr_one->i);
	printf("Second value: %f\n", ptr_one->PI);
	printf("Third value: %c\n", ptr_one->A);

	return (0);
}
