#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 10
#define c_buff(buffer) memset(buffer, 0, sizeof(buffer))
#define SUCCESS 0
#define MALLOC_ERROR 1
#define ERROR 2

/**
 * struct StreamInfo - stream
 * @eof : eof flag for each fd
 * @buffer : The buffer for each fd
 * A value is not unique. It can correspond to several keys
 */
typedef struct StreamInfo
{
	char *buffer;
	int eof;
} StreamInfo;

/**
 * struct StreamsInfo - All the streams
 * @size : The size of the array *
 * @streams : An array of streams of size @size
 */
typedef struct StreamsInfo
{
	StreamInfo *streams;
	size_t size;
} StreamsInfo;

char *_getline(const int fd);

#endif
