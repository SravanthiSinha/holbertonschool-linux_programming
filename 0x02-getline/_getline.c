#include "_getline.h"

static stream_info streams[MAX_FILE_DESCRIPTOR];

/**
 * free_stash - frees everything and reset all static variables if fd == -1
 * @fd: the file descriptor to read from.
 */
void free_stash(const int fd)
{
	long i;

	if (fd == -1)
	{
		for (i = 0; i < MAX_FILE_DESCRIPTOR; i++)
		{
			if (streams[i].next != NULL)
			{
				streams[i].next = NULL;
				free(streams[i].next);
			}
		}
		memset(streams, 0, sizeof(stream_info));
	}
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
		if (s1)
			memcpy(out, s1, s1_len);
		memcpy(out + s1_len, s2, s2_len + 1);
	}
	if (s1)
		free(s1);
	if (s2)
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
	char buffer[READ_SIZE + 1], *token = NULL, *new, *v_buf = NULL;
	int bytes_read = 0, pos = 0;

	if (fd != -1)
	{
		memset(buffer, 0, sizeof(buffer));
		bytes_read = read(fd, buffer, READ_SIZE);
		if (streams[fd].eof != -1 && bytes_read >= 0)
		{
			streams[fd].next =
				_strapp(streams[fd].next, v_buf = _strndup(buffer, bytes_read));
			if (streams[fd].next != NULL)
			{
				do {
					pos = get_pos(streams[fd].next, '\n');
					if (pos >= 0)
					{
						token = _strndup(streams[fd].next, pos);
						new = strdup(streams[fd].next + pos + 1);
						free(streams[fd].next);
						streams[fd].next = new;
						return (token);
					}
					memset(buffer, 0, sizeof(buffer));
					bytes_read = read(fd, buffer, READ_SIZE);
					streams[fd].next =
						_strapp(streams[fd].next, v_buf = _strndup(buffer, bytes_read));
				} while (streams[fd].next != NULL && bytes_read &&
					 get_pos(streams[fd].next, EOF) == -1);
				if (streams[fd].next && _strlen(streams[fd].next))
				{
					streams[fd].next = _strapp(streams[fd].next, v_buf = strdup(n));
					streams[fd].eof = -1;
					return (strdup(streams[fd].next));
				}
			}
		}
		if (streams[fd].next)
		{
			free(streams[fd].next);
			streams[fd].next = NULL;
		}
	}
	free_stash(fd);
	return (NULL);
}
