#include "holberton.h"
/**
 * _strncat - concatinates the given 2 strings
 * @dest: string to be concatinated to
 * @src: string to be concatinated with
 * @n: number of bytes to be concatinated
 * Description: concatinates the given 2 strings
 * Return:  return  a  pointer  to  the  resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len;
	int i;

	dest_len = _strlen(dest);
	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
