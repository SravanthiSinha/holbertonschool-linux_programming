#include "hls.h"


/**
 * scan_files -scales the dirnames for validity of filepaths and builds
 * a direntry accordingly
 * @dirnames: input file optons
 * @direntry: The List to be built with the file_path
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR,
 * HS_INVALID_FILE_DIR
 */
int scan_files(List **dirnames, Direntry **direntry)
{
	int i;
	int exit_value = HLS_SUCCESS;
	int error_occured = 0;
	char *param;
	List *node, *next;

	node = *dirnames;
	while (node != NULL)
	{
		param = strdup(node->str);
		next = node->next;
		if (file_exist(param))
		{
			exit_value = dirwalk(param, direntry);
			if (exit_value == HLS_MAJOR_ERROR)
				break;
		}
		else
		{
			print_error(HS_INVALID_FILE_DIR, param);
			deleteParam(dirnames, param);
			error_occured = 1;
		}
		node = next;
		free(param);
	}
	free_list(node);
	return (exit_value != HLS_SUCCESS || error_occured ? HLS_MAJOR_ERROR
		: HLS_SUCCESS);
}

/**
 * dirwalk - Adds to list consisiting of the files with in the
 * files in a particluar directory and files
 * @dirname: input file opton
 * @direntry: The List to be built with the file_path
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR
 */
int dirwalk(char *dirname, Direntry **direntry)
{
	DIR *dir;
	struct dirent *read;
	int exit_value = HLS_SUCCESS;
	char path_name[MAX_PATH_SIZE];

	path_name[0] = '\0';
	if (!is_directory(dirname))
		exit_value = direntry_add(direntry, dirname, 0);
	else
	{
		dir = opendir(dirname);
		while ((read = readdir(dir)) != NULL && exit_value == HLS_SUCCESS)
		{
			strcat(path_name, dirname);
			if (path_name[strlen(path_name) - 1] != '/')
				strcat(path_name, "/");
			strcat(path_name, read->d_name);
			exit_value = direntry_add(direntry, path_name, is_directory(path_name));
			path_name[0] = '\0';
		}
		closedir(dir);
	}
	return (exit_value);
}
