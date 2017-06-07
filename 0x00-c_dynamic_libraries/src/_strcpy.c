/**
 * _strcpy - The  _strcpy()  function  copies the string pointed to by src,
 * including the terminating null byte ('\0') to the buffer pointed to by dest.
 * @dest: string to be copied into
 * @src: string to be copied
 *
 * Return: a pointer to the destination string dest.
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

