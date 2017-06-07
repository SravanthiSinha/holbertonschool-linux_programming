#include "holberton.h"
/**
 * _memcmp - compares the first n characters of the object pointed to by s1
 * to the first n characters of the object pointed to by s2.
 * @s1: string @s1
 * @s2: string @s2
 * @n: no of characters to be compated
 *
 * Return: Integer greater than, equal to, or less than zero, accordingly as
 * the object pointed to by s1 is greater than, equal to, or less than the
 * object pointed to by s2.
 */
int _memcmp(const void *s1, const void *s2, unsigned int n)
{
	const unsigned char *p1 = s1, *p2 = s2;

	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++, p2++;
	}
	return (0);
}

/**
 * _strstr - Finds the 1st occurrence of the substring needle in
 * the string haystack.
 * @haystack: string to be searched in
 * @needle: string to be looked for in @haystack
 *
 * Return: A pointer to the beginning of the substring, or NULL
 * if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int n;

	n = _strlen(needle);
	while (*haystack)
		if (!_memcmp(haystack++, needle, n))
			return (haystack - 1);
	return (0);
}
