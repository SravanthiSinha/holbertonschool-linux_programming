/**
 * _memcpy - A function that copies n bytes from memory area src
 * to memory area dest.
 * @dest: destationation to be copied to
 * @src: src to be copied from
 * @n: no of bytes to be copied
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *dp;
	const char *sp;

	dp = dest;
	sp = src;
	while (n--)
		*dp++ = *sp++;
	return (dest);
}
