/**
 * _strncpy - The  _strncpy()  function  copies the string pointed to by src,
 * at most n bytes of  src  are copied.
 * to  the  buffer  pointed  to  by  dest.
 * @dest: string to be copied into
 * @src: string to be copied
 * @n: number of bytes to be copied
 *
 * Return: a pointer to the destination string dest.
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = 0;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

