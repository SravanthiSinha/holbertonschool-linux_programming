#include "holberton.h"
/**
 * _strcat - concatinates the given 2 strings
 * @dest: string to be concatinated to
 * @src: string to be concatinated with
 * Description: concatinates the given 2 strings
 * Return: concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = _strlen(dest);
	for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
