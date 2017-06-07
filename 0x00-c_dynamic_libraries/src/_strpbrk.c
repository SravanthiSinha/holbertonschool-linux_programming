#include "holberton.h"
/**
 * _strpbrk - The function locates the first occurrence in the string s of any
 * of the bytes in the string accept.
 * @s:string s
 * @accept: bytes to be looked for in @s
 *
 * Return: a pointer to the byte in s that  matches  one
 * of the bytes in accept, or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
		if (_strchr(accept, *s++))
			return ((char *) --s);
	return (0);
}
