/**
 * _memset - The _memset function fills the first n bytes of the memory area
 * pointed to by s with the bytes b
 * @s: bytes to be filled in
 * @b: bytes to be filled
 * @n: no of bytes
 *
 * Return: A pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *p;

	p = s;
	while (n--)
		*p++ = b;
	return (s);
}
