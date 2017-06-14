#include "hls.h"

/**
  * print_file_list - Prints the filelist
  * @hashtable: The hastable consisiting keys as the path to the files
  * and value being the corresponding dirname
  * @list: The list of the sorted file paths.
  *
  * Return: void
  */
void print_file_list(HashTable __attribute__((unused)) * hashtable,
		     FileList *list)
{
	FileList *node;
	int a = 0;

	node = list;
	while (node != NULL)
	{
		if (strcmp(basename(node->str), ".") != 0 &&
		    strcmp(basename(node->str), "..") != 0)
		{
			printf("%s", basename(node->str));
			a = 1;
		}
		node = node->next;
		if (node && a)
		{
			printf("  ");
			a = 0;
		}
		else if (!node)
		{
			printf("\n");
		}
	}
}

/**
  * execute - Adds to a hash and an list consisiting of the files with the
  * files in a particluar directory
  * @dirname: name of the driectory whose files have to be listed.
  * @hashtable: The hastable to be built with keys as the path to the files
  * and value being the @dirname
  * @list: Creates the list of the sorted file paths.
  *
  * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2
  */
int execute(char *dirname, HashTable *hashtable, FileList **list)
{
	DIR *dir;
	struct dirent *read;
	int exit_value = HLS_SUCCESS;
	char path_name[MAX_PATH_SIZE];

	path_name[0] = '\0';
	dir = opendir(dirname);

	if (dir == NULL) /* check if the directory is avaialbe*/
		return (HLS_MAJOR_ERROR);

	while ((read = readdir(dir)) != NULL && exit_value == HLS_SUCCESS)
	{
		strcat(path_name, dirname);
		if (path_name[strlen(path_name) - 1] != '/')
			/*Check if user supplied '/' at the end of directory name. */
			strcat(path_name, "/");
		exit_value = ht_put(hashtable, strcat(path_name, read->d_name), dirname);
		if (exit_value == HLS_SUCCESS)
			exit_value = add(list, path_name, compare);
		path_name[0] = '\0';
	}
	closedir(dir);

	return (exit_value);
}
