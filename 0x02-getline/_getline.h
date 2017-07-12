#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 8
#define  MAX_FILE_DESCRIPTOR 804663

typedef struct
{
	char *next;
	int eof;
} stream_info;
static const __attribute__((unused))  char *n = "\0";
char *_getline(const int fd);

#endif
