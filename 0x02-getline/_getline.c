#include "_getline.h"

static char buffer[READ_SIZE];
static int bytes_read;

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
	char *out;

	if (s1)
		s1_len = _strlen(s1);
	if (s2)
		s2_len = _strlen(s2);
	out_len = s1_len + s2_len + 1;
	out = malloc(out_len);
	memcpy(out, s1, s1_len);
	memcpy(out + s1_len, s2, s2_len + 1);
	free(s1);
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
	char *lineptr = NULL;
	char s[READ_SIZE];
	int i = 0, d = 0;

	if (bytes_read)
	{
		while (i < READ_SIZE && buffer[i] != '\n')
			i++;
		/* copy from s2 line from previous buffer*/
		strcpy(s, buffer + i + 1);
		s[_strlen(buffer + i + 1)] = '\0';
		lineptr = _strapp(lineptr, s);
	}
	do {
		/*consider a block */
		bytes_read = read(fd, buffer, READ_SIZE);
		if (bytes_read)
		{
			i = 0;
			while (i < READ_SIZE && buffer[i] != '\n' && buffer[i] != EOF)
				i++;
			s[0] = '\0';
			/* copy till s2 line*/
			strncpy(s, buffer, i);
			s[i] = '\0';
			lineptr = _strapp(lineptr, s);
		}
	} while (bytes_read > 0 && buffer[i] != '\n');
	if (bytes_read == 0 && lineptr)
	{
		d = _strlen(lineptr);
		/* check end of previous buffer if it has s2line*/
		if (lineptr[d - 1] == '\n')
			lineptr[d - 1] = '\0';
		buffer[0] = '\0';
	}
	return (lineptr);
}
