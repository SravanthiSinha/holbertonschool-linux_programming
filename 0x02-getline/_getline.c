#include "_getline.h"

static StreamsInfo ss = {NULL, 0};

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
	char buff[READ_SIZE + 1], *token = NULL, *new = NULL;
	int bytes_read = 0, pos = 0;

	if (fd != -1)
	{
		if (initializeStash(&ss, fd + 1) != SUCCESS)
			return (NULL);
		while (ss.streams[fd].eof == 0)
		{
			if (ss.streams[fd].buffer)
			{
				pos = getPosition(ss.streams[fd].buffer, '\n', 0);
				if (pos >= 0)
				{
					token = strapp(NULL, ss.streams[fd].buffer, pos);
					new = strdup(ss.streams[fd].buffer + pos + 1);
					free(ss.streams[fd].buffer);
					ss.streams[fd].buffer = new;
					return (token);
				}
			}
			bytes_read = read(fd, c_buff(buff), READ_SIZE);
			if (bytes_read < 0)
				return (NULL);
			ss.streams[fd].buffer = strapp(ss.streams[fd].buffer, buff, bytes_read);
			if (bytes_read == 0 && ss.streams[fd].buffer &&
			    getPosition(ss.streams[fd].buffer, EOF, 0) == -1) {
				ss.streams[fd].eof = -1;
				if (getPosition(ss.streams[fd].buffer, '\0', 1))
					return (strdup(ss.streams[fd].buffer));
			}
			else if (!ss.streams[fd].buffer)
				break;
		}
	}
	freeStash(&ss, fd);
	return (NULL);
}

/**
 * initializeStash - handles stash
 * @ss: All the streams
 * @fd: the file descriptor to read from.
 * Return: 1 on Success and 0 on failure
 */
int initializeStash(StreamsInfo *ss, const int fd)
{
	int i = 0;

	if (ss->size < (size_t)fd)
	{
		ss->streams = (StreamInfo *)_realloc(ss->streams,
						     fd * sizeof(StreamInfo) * 2, ss->size * sizeof(StreamInfo));
		if (!ss->streams)
			return (MALLOC_ERROR);
		for (i = ss->size; i < (fd * 2); i++)
		{
			ss->streams[i].buffer = NULL;
			ss->streams[i].eof = 0;
		}
		ss->size = fd * 2;
	}
	return (SUCCESS);
}


/**
 * getPosition - Returns a pointer to the 1st occurrence of the
 * character c in the string s
 * @s: string to be searched in
 * @c: character to be looked for
 * @f_len : if f_len == 1 length of the string is returned
 *
 * Return: Pointer to the matched character or NULL if character is not found.
 */
int getPosition(char *s, int c, int f_len)
{
	char ch = c;
	int i = 0;

	if (!f_len)
	{
		while (*s != ch)
		{
			if (*s == '\0')
				return (-1);
			i++;
			s++;
		}
	}
	else
	{
		while (s && s[i])
			i++;
	}
	return (i);
}

/**
 * freeStash - frees stash
 * @fd: the file descriptor to read from.
 * @ss: All the streams
 */
void freeStash(StreamsInfo *ss, const int fd)
{
	size_t i = 0;

	/* free_stash*/
	if (fd == -1)
	{
		for (i = 0; i < ss->size; i++)
		{
			free(ss->streams[i].buffer);
			ss->streams[i].buffer = NULL;
			ss->streams[i].eof = 0;
		}
		free(ss->streams);
		ss->streams = NULL;
		ss->size = 0;
		ss = NULL;
	}
}

/**
 * strapp - Appends the s2 string to previous with s2 allocation
 * @s1: old String
 * @s2: new String
 * @s2_len : length of string 2
 * Return: Created string with  old and new string concatinated.
 */
char *strapp(char *s1, char *s2, int s2_len)
{
	size_t s1_len = 0;
	size_t out_size = 0;
	char *out = NULL;

	if (s1)
		s1_len = getPosition(s1, '\0', 1);
	out_size = s1_len + s2_len;
	out = malloc(out_size + 1);
	if (out != NULL)
	{
		if (s1)
			memcpy(out, s1, s1_len);
		if (s2)
			memcpy(out + s1_len, s2, s2_len);
		out[out_size] = 0;
		if (s1)
			free(s1);
	}
	return (out);
}

/**
 * _realloc - function changes the size of the memory block pointed to by
 * ptr to size bytes
 * @ptr: the pointer to be reallocted
 * @size: the no of bytes to be reallocted
 * @msize: the no of bytes to be  previously allocted
 * Return: a pointer to the newly allocated memory.
 */
void *_realloc(void *ptr, size_t size, size_t msize)
{
	void *newptr = NULL;

	if (size <= msize)
		return (ptr);
	newptr = malloc(size);
	if (newptr)
	{
		memcpy(newptr, ptr, msize);
		free(ptr);
		return (newptr);
	}
	return (NULL);
}
