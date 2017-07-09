#include "_getline.h"

static char *next;

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
 * get_pos - Returns a pointer to the 1st occurrence of the
 * character c in the string s
 * @s: string to be searched in
 * @c: character to be looked for
 *
 * Return: Pointer to the matched character or NULL if character is not found.
 */
int get_pos(const char *s, int c)
{
	const char ch = c;
	int i = 0;

	while (*s != ch)
	{
		if (*s == '\0')
			return (-1);
		i++;
		s++;
	}
	return (i);
}

/**
 * _strlen - calculate the length of a string
 * @s: This is the string whose length has to be calculated.
 *
 * Return: Number of bytes in the string s.
 */
unsigned int _strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/**
 * _strndup - The  _strndup()  function  copies the string pointed to by src,
 * at most n bytes of  src  are copied.
 * to  the  buffer  pointed  to  by  dest.
 * @s: string to be copied
 * @n: number of bytes to be copied
 *
 * Return: a pointer to the destination string dest.
 */
char *_strndup(char *s, size_t n)
{
	char *result;
	unsigned int len = _strlen(s);

	if (n < len)
		len = n;

	result = (char *)malloc(len + 1);
	if (!result)
		return (0);

	result[len] = '\0';
	return ((char *)memcpy(result, s, len));
}

/**
 * _strapp - Appends the s2 string to previous with s2 allocation
 * @s1: old String
 * @s2: new String
 *
 * Return: Created string with  old and new string concatinated.
 */
char *_strapp(char *s1, char *s2)
{
	size_t s1_len = 0, s2_len = 0;
	size_t out_len = 0;
	char *out = NULL;

	if (s1)
		s1_len = _strlen(s1);
	if (s2)
		s2_len = _strlen(s2);
	out_len = s1_len + s2_len + 1;
	out = malloc(out_len);
	if (out != NULL)
	{
		memcpy(out, s1, s1_len);
		memcpy(out + s1_len, s2, s2_len + 1);
	}
	free(s1);
	free(s2);
	return (out);
}

/**
 * _getline - reads an entire line from a file descriptor.
 * @fd: the file descriptor to read from.
 *
 * Return: On Success - a null-terminated string that does not
 *include the newline character.
 * On Failure - NUll.
 */
char *_getline(const int fd)
{
	char buffer[READ_SIZE + 1];
	char *token = NULL;
	int bytes_read, pos;

	if (fd == -1)
		free(next);
	else
	{
		bytes_read = read(fd, buffer, READ_SIZE);
		if (bytes_read >= 0)
		{
			if (next)
				next = _strapp(strdup(next), _strndup(buffer, bytes_read));
			else
				next = _strapp(next, _strndup(buffer, bytes_read));
			if (next != NULL)
			{
				do {
					pos = get_pos(next, '\n');
					if (pos >= 0)
					{
						token = _strndup(next, pos);
						next = next + pos + 1;
						return (token);
					}
					bytes_read = read(fd, buffer, READ_SIZE);
					next = _strapp(strdup(next), _strndup(buffer, bytes_read));
				} while (next != NULL && bytes_read);
			}
		}
	}
	return (NULL);
}
