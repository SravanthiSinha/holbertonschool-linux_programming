#include "holberton.h"
/**
 * _strspn - function calculates the length (in bytes) of the initial segment
 * of s which consists entirely of bytes in accept
 * @s:string s
 * @accept: bytes to be looked for in @s
 *
 * Return: Number of bytes in the initial segment of s which consist
 * only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int ret;

	ret = 0;
	while (*s && _strchr(accept, *s++))
		ret++;
	return (ret);
}
