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

	lstat(filepath, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

/**
 * file_size - Verifies if a file path is a directory
 * @filepath: file path
 *
 * Return: the file size.
 */
long file_size(const char *filepath)
{
	struct stat path_stat;

	lstat(filepath, &path_stat);
	return ((long)(path_stat.st_size));
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

	return (lstat(filepath, &buffer) == 0);
}


/**
 * basename - returns only the filename for a file path
 * @filepath: file path
 *
 * Return: a pointers to null-terminated strings
 */
char *basename(const char *filepath)
{
	char *p = _strrchr(filepath, '/');

	return (p ? p + 1 : (char *)filepath);
}
