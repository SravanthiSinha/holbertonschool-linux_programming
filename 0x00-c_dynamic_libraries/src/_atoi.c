#include "holberton.h"

/**
 * _atoi - The function converts the initial portion of the string
 * pointed  to by @s to int.
 * @s: string too be converted to
 *
 * Return: Converted Value
 */
int _atoi(char *s)
{
	int res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; s[i] != '\0'; ++i)
	{
		if (_isdigit(s[i]) == 0)
			return (0);
		res = res * 10 + s[i] - '0';
	}
	return (sign * res);
}


