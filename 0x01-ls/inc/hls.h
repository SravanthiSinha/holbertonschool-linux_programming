#ifndef _HEADER_H_
#define _HEADER_H_

#include "filelist.h"
#include "hashtable.h"
#include <dirent.h>
#include <grp.h>
#include <libgen.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define HLS_SUCCESS 0
#define HLS_MINOR_ERROR 1
#define HLS_MAJOR_ERROR 2

#define HS_INVALID_FILE 3
#define HS_INVALID_OPTION 4
#define MAX_PATH_SIZE 100

int execute(char *dir, HashTable *, FileList **);
int node_cmp(FileList *, FileList *);
void print_file_list(HashTable __attribute__((unused)) *, FileList *list);
#endif
