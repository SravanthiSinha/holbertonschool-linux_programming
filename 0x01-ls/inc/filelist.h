#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <string.h>

/**
 * struct FileList - List to be used to store the paths of the file.
 * @str : The value to be stored.
 * @next : A pointer to the next node of the List
 */
typedef struct FileList
{
	char *str;
	struct FileList *next;
} FileList;

int list_size(FileList *list);
void print_list(FileList *list);
void free_list(FileList *head);
int compare(FileList *one, FileList *two);
int add(FileList **pp, char *value, int (*cmp)(FileList *l, FileList *r));
#endif
