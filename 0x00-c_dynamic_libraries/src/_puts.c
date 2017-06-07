#include "holberton.h"

/**
 * _puts - writes the string s to stdout
 * @s: The string to print
 *
 * Return: void
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}
