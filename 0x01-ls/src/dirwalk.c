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
			else if (exit_value == HLS_PERMISSION_DENIED)
			{
				print_error(HLS_PERMISSION_DENIED, param);
				deleteParam(dirnames, param);
				error_occured = 1;
			}
		}
		else
		{
			print_error(HLS_INVALID_FILE_DIR, param);
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
 * @en: The List to be built with the file_path
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR
 */
int dirwalk(char *dirname, Direntry **en)
{
	DIR *dir = NULL;
	struct dirent *read = NULL;
	int exit_value = HLS_SUCCESS;
	char path[MAX_PATH_SIZE];

	path[0] = '\0';
	if (!is_directory(dirname))
		exit_value = direntry_add(en, dirname, 0, file_size(dirname));
	else
	{
		dir = opendir(dirname);
		if (!dir)
			return (HLS_PERMISSION_DENIED);
		while ((read = readdir(dir)) != NULL && exit_value == HLS_SUCCESS)
		{
			strcat(path, dirname);
			if (path[strlen(path) - 1] != '/')
				strcat(path, "/");
			strcat(path, read->d_name);
			exit_value = direntry_add(en, path, is_directory(path), file_size(path));
			path[0] = '\0';
		}
		closedir(dir);
	}
	return (exit_value);
}
