#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 1024
#define c_buff(buffer) memset(buffer, 0, sizeof(buffer))

/**
 * struct stream_s - used to store all related info of a particular stream.
 * @fd: the file descriptor
 * @buff: The buff for each fd
 * @buff_size: size of the buff
 * @eof: eof flag for each fd
 * @next: pointer to next stream
 * A value is not unique. It can correspond to several keys
 */
typedef struct stream_s
{
	int fd;
	char *buff;
	int buff_size;
	int eof;
	struct stream_s *next;
} StreamInfo;



StreamInfo *initialize_get_Stash(StreamInfo **ss, int fd, int *error_occured);
void deleteStash(StreamInfo **ss, StreamInfo *stream);
void setStash(StreamInfo *stream, int *error_occured);
void freeStash(StreamInfo **ss);

char *get_update_Stash(StreamInfo *stream, int at, int *error_occured);

char *_getline(const int fd);

#endif
