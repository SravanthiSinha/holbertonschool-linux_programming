#ifndef _HEADER_H_
#define _HEADER_H_

#include "direntry.h"
#include "list.h"
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

#define HS_INVALID_FILE_DIR 3
#define HS_INVALID_OPTION 4
#define MAX_PATH_SIZE 100

int scan_files(List **dirnames,  Direntry **direntry);
int dirwalk(char *dirname, Direntry **direntry);

void print_file_list(List **dirnames, Direntry **dirent, int);

void print_error(int error_code, char *name);

int file_exist(char *filename);
int is_directory(const char *path);

int dirent_cmp(Direntry *, Direntry *);
void sort_direntres(Direntry **a, int (*cmp)(Direntry *a, Direntry *b));

int node_cmp(List *node1, List *node2);
void sort_list(List **a, int (*cmp)(List *a, List *b));
#endif
