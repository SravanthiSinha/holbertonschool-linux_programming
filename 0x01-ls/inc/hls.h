#ifndef _HEADER_H_
#define _HEADER_H_

#include "direntry.h"
#include "list.h"
#include "options.h"
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

#define HLS_INVALID_FILE_DIR 3
#define HLS_INVALID_OPTION 4
#define HLS_PERMISSION_DENIED 5
#define MAX_PATH_SIZE 400
#define MAX_OPTION_SIZE 100

int scan_files(List **dirnames,  Direntry **direntry);
int dirwalk(char *dirname, Direntry **direntry);

void print_file_list(Options *op, List **dirnames, Direntry **dirent, int);

void print_error(int error_code, char *name);

int file_exist(char *filename);
int is_directory(const char *path);

int dirent_cmp_size(Direntry *node1, Direntry *node2, int reverse);
int dirent_cmp(Direntry *, Direntry *, int reverse);
void sort_direntres(Direntry **, int (*c)(Direntry *, Direntry *, int), int r);

int node_cmp_size(List *node1, List *node2, int reverse);
int node_cmp(List *node1, List *node2, int reverse);
void sort_list(List **a, int (*cmp)(List *a, List *b, int r), int reverse);

int validate_options(char **argv, char *options);

int no_digits(long n);
long file_size(const char *filepath);
#endif
