#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "School"
#define S3  "Socool"

/**
char* asm_strstr(const char *str, sonst char *substr)
{
	  while (*str)
	  {
		    const char *Begin = str;
		    const char *pattern = substr;

		    // If first character of sub string match, check for whole string
		    while (*str && *pattern && *str == *pattern)
			{
			      str++;
			      pattern++;
		    }
		    // If complete sub string match, return starting address
		    if (!*pattern)
		    	  return (char *)Begin;

		    str = Begin + 1;	// Increament main string
	  }
	  return NULL;
}
**/
/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    assert(strstr(S1, S2) == asm_strstr(S1, S2));
    assert(strstr(S1, S3) == asm_strstr(S1, S3));
    assert(strstr(S1, S1) == asm_strstr(S1, S1));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}
