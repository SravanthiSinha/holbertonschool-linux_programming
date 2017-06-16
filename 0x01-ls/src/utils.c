#include "hls.h"


/**
 * is_directory - Verifies if a file path is a directory
 * @filepath: file path
 *
 * Return: on success: 1 , on Failure:0.
 */
int is_directory(const char *filepath)
{
	struct stat path_stat;

	stat(filepath, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

/**
 * file_exist - Verifies if a file path exists
 * @filepath: file path
 *
 * Return: on success: 1 , on Failure:0.
 */
int file_exist(char *filepath)
{
	struct stat buffer;

	return (stat(filepath, &buffer) == 0);
}
