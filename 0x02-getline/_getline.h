#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 10

char *_getline(const int fd);

#endif
