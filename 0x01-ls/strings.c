#include "hls.h"

/**
 * _strlen - calculate the length of a string
 * @s: This is the string whose length has to be calculated.
 *
 * Return: Number of bytes in the string s.
 */
unsigned int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * _strcat - concatinates the given 2 strings
 * @dest: string to be concatinated to
 * @src: string to be concatinated with
 * Description: concatinates the given 2 strings
 * Return: concatinated string
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len;
	int i;

	dest_len = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strchr - Returns a pointer to the 1st occurrence of the
 * character c in the string s
 * @s: string to be searched in
 * @c: character to be looked for
 *
 * Return: Pointer to the matched character or NULL if character is not found.
 */
char *_strchr(const char *s, int c)
{
	const char ch = c;

	while (*s != ch)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/**
 * _strrchr - Returns a pointer to the last occurrence of the
 * character c in the string s
 * @s: string to be searched in
 * @c: character to be looked for
 *
 * Return: Pointer to the matched character or NULL if character is not found.
 */
char *_strrchr(const char *s, int c)
{
	char *rtnval = 0;

	do {
		if (*s == c)
			rtnval = (char *)s;
	} while (*s++);
	return (rtnval);
}

/**
 * _strdup - Creates a duplicate of the string pointed to by str
 * @str: pointer to the null-terminated string to duplicate
 * Description: Creates a duplicate of the string pointed to by str
 * Return: A pointer to the newly allocated string,
 * or a null pointer if an error occurred.
 */
char *_strdup(const char *str)
{
	int len;
	int i;
	char *s;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	s = malloc(sizeof(*s) * (len + 1));
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
