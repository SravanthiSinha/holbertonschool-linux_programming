#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "_getline.h"

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
	static StreamInfo *ss;
	StreamInfo *stream = NULL;
	char *lineptr = NULL;
	int error_occured = 0, pos = 0;

	if (fd == -1)
		freeStash(&ss);
	else
	{
		stream = initialize_get_Stash(&ss, fd, &error_occured);
		while (!lineptr && stream && !error_occured)
		{
			pos = 0;
			/* get the position of occurence of newline in the buffer */
			while ((pos < stream->buff_size) && (stream->buff[pos] != '\n'))
				++pos;
			/* get the line and update the buffer */
			if ((pos != stream->buff_size) || stream->eof)
				lineptr = get_update_Stash(stream, pos, &error_occured);
			if (stream->eof == 0)
				setStash(stream, &error_occured);
			error_occured |= (stream->eof && (stream->buff_size == 0));
		}
		if (error_occured && (lineptr == NULL))
			deleteStash(&ss, stream);
	}
	return (lineptr);
}

/**
 * initializeStash - INtailise the stash if not else retirn the stored stash
 * @ss: All the streams
 * @fd: the file descriptor to read from.
 * @error_occured: flag to indicate malloc errors or any errors.
 * Return:  a stream realted to fd.
 */
StreamInfo *initialize_get_Stash(StreamInfo **ss, int fd, int *error_occured)
{
	StreamInfo *stream = NULL;

	stream = *ss;
	while (stream && stream->fd != fd)
		stream = stream->next;
	if (!stream)
	{
		stream = malloc(sizeof(StreamInfo));
		*error_occured |= stream == NULL;
		if (stream)
		{
			memset(stream, 0, sizeof(*stream));
			stream->fd = fd;
			stream->next = *ss;
			*ss = stream;
		}
	}
	return (stream);
}

/**
 * setStash - store thestash from the read
 * @stream: The stream to be read
 * @error_occured: flag to indicate malloc errors or any errors.
 */
void setStash(StreamInfo *stream, int *error_occured)
{
	char buff_read[READ_SIZE];
	int bytes_read;
	char *str;

	bytes_read = read(stream->fd, buff_read, READ_SIZE);
	if (bytes_read <= 0)
		stream->eof = 1;
	else
	{
		str = malloc(stream->buff_size + bytes_read);
		*error_occured |= (str == NULL);
		if (str)
		{
			if (stream->buff_size)
				memcpy(str, stream->buff, stream->buff_size);
			memcpy(str + stream->buff_size, buff_read, bytes_read);
		}
		free(stream->buff);
		stream->buff = str;
		stream->buff_size += bytes_read;
	}
}

/**
 * get_update_Stash - Returns a string till newline.
 *	and reset the stash with the buffer left.
 * @stream: stream to be searched in
 * @pos: the index where newline occured previously.
 * @error_occured: flag to indicate malloc errors or any errors.
 *
 * Return: A string where till newline occured.
 */
char *get_update_Stash(StreamInfo *stream, int pos, int *error_occured)
{
	char *str = NULL, *next = NULL;
	int len = stream->buff_size - pos - 1;

	if (stream->buff_size)
	{
		str = malloc(pos + 1);
		*error_occured |= str == NULL;
		if (str)
		{
			memcpy(str, stream->buff, pos);
			str[pos] = 0;
		}
	}
	stream->buff_size = 0;
	if (len > 0)
	{
		next = malloc(len);
		*error_occured |= next != NULL;
		if (next)
			memcpy(next, stream->buff + pos + 1, len);
		stream->buff_size = len;
	}
	free(stream->buff);
	stream->buff = next;
	return (str);
}


/**
 * freeStash - frees stash
 * @ss: All the streams
 */
void freeStash(StreamInfo **ss)
{
	StreamInfo *stream = *ss;
	StreamInfo *tmp;

	while (stream)
	{
		tmp = stream->next;
		free(stream->buff);
		free(stream);
		stream = tmp;
	}
	*ss = NULL;
}

/**
 * deleteStash - deletes the stream from streams @ss.
 * @ss: All the streams
 * @stream: stream to be removed from @ss.
 *
 */
void deleteStash(StreamInfo **ss, StreamInfo *stream)
{
	StreamInfo *s;

	if (stream)
	{
		if (stream == *ss)
			*ss = stream->next;
		else
		{
			s = *ss;
			while (s->next != stream)
				s = s->next;
			s->next = stream->next;
		}
		free(stream->buff);
		free(stream);
	}
}
