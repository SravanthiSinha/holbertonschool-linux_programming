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
    asm_puti_base(98, "0123456789");
    printf("\n");
    asm_puti_base(-1, "0123456789");
    printf("\n");
    asm_puti_base(129342, "0123456789abcdef");
    printf("\n");
    asm_puti_base(781532, "01");
    printf("\n");
    asm_puti_base(INT_MAX, "abcdefghijklmnopqrstwxyz");
    printf("\n");
    asm_puti_base(INT_MIN, "0123456789ABCDEF");
    printf("\n");
    asm_puti_base(0, "01234567");
    printf("\n");
    return (EXIT_SUCCESS);
}
