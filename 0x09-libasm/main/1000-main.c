#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "libasm.h"
/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
  assert(asm_puti(8) == 1);
  printf("\n");
  assert(asm_puti(-1) == 2);
  printf("\n");
  assert(asm_puti(-1024) == 5);
  printf("\n");
  assert(asm_puti(INT_MAX) == 10);
  printf("\n");
  assert(asm_puti(INT_MIN) == 11);
  printf("\n");
  assert(asm_puti(0) == 1);
  printf("\n");
  return (EXIT_SUCCESS);
}
