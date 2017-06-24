#include "hls.h"

/**
 * _strcmp - Compare characters of two strings
 * @s1: C string to be compared.
 * @s2: C string to be compared.
 *
 * Return: An integral value indicating the relationship
 * between the strings
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strncmp - Compare characters of two strings
 * @s1: C string to be compared.
 * @s2: C string to be compared.
 * @k: Maximum number of characters to compare
 * Description:Compares up to k characters of the C string s1
 * to those of the C string s2.
 * Return: An integral value indicating the relationship
 * between the strings
 */
int _strncmp(const char *s1, const char *s2, unsigned int k)
{
	unsigned int i;
	int n1;
	int n2;
	int t;
	unsigned int n;

	i = 0;
	t = 0;
	n1 = _strlen(s1);
	n2 = _strlen(s2);
	n = (n1 >= n2) ? n1 : n2;
	n = (k > n) ? n : k;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			t = s1[i] - s2[i];
			break;
		}
		else
			t = 0;
		i++;
	}
	return (t);
}

/**
 * _tolower - converts a lower case character to upper case
 * @ch: C character to be converted.
 *
 * Return: converted character
 */
char _tolower(unsigned char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch = 'a' + (ch - 'A');
	return (ch);
}

/**
 * _strcasecmp - Compare characters of two strings ignoring case
 * @s1: C string to be compared.
 * @s2: C string to be compared.
 *
 * Return: An integral value indicating the relationship
 * between the strings
 */
int _strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *us1 = (const unsigned char *)s1;
	const unsigned char *us2 = (const unsigned char *)s2;

	while (_tolower(*us1) == _tolower(*us2++))
		if (*us1++ == '\0')
			return (0);
	return (_tolower(*us1) - _tolower(*--us2));
}
