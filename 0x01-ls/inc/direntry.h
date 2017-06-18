#ifndef _Direntry_H_
#define _Direntry_H_

/**
 * struct Direntry - List to be used to store the paths of the file.
 * @str : The value to be stored.
 * @is_dir : If a file path is directory
 * @next : A pointer to the next node of the List
 * @size : file size
 */
typedef struct Direntry
{
	char *str;
	int is_dir;
	long size;
	struct Direntry *next;
} Direntry;

int direntry_size(Direntry *direntry);
void print_direntry(Direntry *direntry);
void free_direntry(Direntry *head);
void removeDuplicates(Direntry *head);
int direntry_add(Direntry **direntry, char *content, int is_dir, long size);
void deleteDirent(Direntry **head_ref, char *key);
Direntry *get_direntres(char *str, Direntry *en);
Direntry *get_files(Direntry *en);
#endif
