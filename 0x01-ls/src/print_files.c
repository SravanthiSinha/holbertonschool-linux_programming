#include "hls.h"

/**
 * print_files - Prints the filelist
 * @options: options to be applied for each @dirname
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 *
 * Return: 1 if list of files are printed else 0
 */
int print_files(Options *options, Direntry **dirent, List **dirnames)
{
	Direntry *node = *dirent;
	char *filename;
	int a = 0;
	int hidden_file;

	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		hidden_file = 0;
		filename = strdup(node->str);
		if (basename(filename)[0] == '.' || strcmp(basename(filename), "..") == 0)
			hidden_file = 1;
		if (!options->all && hidden_file)
			node = node->next;
		else
		{
			printf("%s", basename(filename));
			if (!is_directory(filename))
				deleteParam(dirnames, filename);
			a = 1;
		node = node->next;
		if (node && a)
			printf("%s", options->delimeter);
		}
		free(filename);
	}
	printf("\n");
	return (1);
}

/**
 * print_file_list - Prints the filelist
 * @op: options to be applied for each @dirnames
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 * @ec : to print a newline if an error was printed to OUTPUT
 *
 * Return: void
 */
void print_file_list(Options *op, List **dirnames, Direntry **dirent, int ec)
{
	Direntry *node = NULL;
	int a = 0;
	int i = 0;
	int no_dirs = 0;
	int no_files = 0;
	char param[MAX_PATH_SIZE];

	param[0] = '\0';
	/* print_files*/
	node = get_files(*dirent);
	sort_direntres(&node, &dirent_cmp);
	no_files = print_files(op, &node, dirnames);
	free_direntry(node);
	/* print_dirs*/
	no_dirs = list_size(*dirnames);
	if (no_files && no_dirs)
		printf("\n");
	while (i < no_dirs)
	{
		a = 0;
		strcat(param, get_node(*dirnames, i));
		if ((no_dirs > 1 || ec || no_files) && is_directory(param))
			printf("%s:\n", param);
		if (param[strlen(param) - 1] != '/')
			strcat(param, "/");
		node = get_direntres(param, *dirent);
		sort_direntres(&node, &dirent_cmp);
		removeDuplicates(node);
		if (print_files(op, &node, dirnames) && i < no_dirs - 1)
			printf("\n");
		free_direntry(node);
		i++;
		param[0] = '\0';
	}
}
