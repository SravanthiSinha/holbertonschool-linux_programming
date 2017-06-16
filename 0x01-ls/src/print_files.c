#include "hls.h"

/**
 * print_files - Prints the filelist
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 *
 * Return: 1 if list of files are printed else 0
 */
int print_files(Direntry **dirent, List **dirnames)
{
	Direntry *node;
	char *filename;
	int a = 0;

	node = *dirent;
	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		filename = strdup(node->str);
		if (basename(filename)[0] != '.' && strcmp(basename(filename), "..") != 0)
		{
			printf("%s", basename(filename));
			if (!is_directory(node->str))
				deleteParam(dirnames, node->str);
			a = 1;
		}
		node = node->next;
		if (node && a)
			printf("  ");
		free(filename);
	}
	printf("\n");
	return (1);
}

/**
 * print_file_list - Prints the filelist
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 * @error_occured : to print a newline if an error was printed to OUTPUT
 *
 * Return: void
 */
void print_file_list(List **dirnames, Direntry **dirent, int error_occured)
{
	Direntry *node;
	int a;
	int i = 0;
	int no_dirs;
	int no_files;
	char *param;

	/* print_files*/
	node = get_direntres("", *dirent);
	sort_direntres(&node, &dirent_cmp);
	no_files = print_files(&node, dirnames);
	free_direntry(node);
	/* print_dirs*/
	no_dirs = list_size(*dirnames);
	if (no_files && no_dirs)
		printf("\n");
	while (i < no_dirs)
	{
		a = 0;
		param = get_node(*dirnames, i);
		if ((no_dirs > 1 || error_occured || no_files) && is_directory(param))
			printf("%s:\n", param);
		if (param[strlen(param) - 1] != '/')
			strcat(param, "/");
		node = get_direntres(param, *dirent);
		sort_direntres(&node, &dirent_cmp);
		if (print_files(&node, dirnames) && i < no_dirs - 1)
			printf("\n");
		free_direntry(node);
		i++;
		free(param);
	}
}
