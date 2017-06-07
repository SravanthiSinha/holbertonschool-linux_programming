/**
 * _strchr - Returns a pointer to the 1st occurrence of the
 * character c in the string s
 * @s: string to be searched in
 * @c: character to be looked for
 *
 * Return: Pointer to the matched character or NULL if character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
