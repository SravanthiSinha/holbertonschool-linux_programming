#include "hls.h"

/**
 * print_error - Prints thes the error
 * @error_code:  error_code
 * @name: file input option
 *
 * Return: void
 */
void print_error(int error_code, char *name)
{
	char *dir;

	switch (error_code)
		{
		case HLS_INVALID_FILE_DIR:
			dir = _strdup(name);
			dir[_strlen(dir) - 1] = '\0';
			if (file_exist(dir) && name[_strlen(name) - 1] == '/')
				printf("hls: cannot access %s: Not a directory\n", name);
			else
				printf("hls: cannot access %s: No such file or directory\n", name);
			free(dir);
			break;
		case HLS_PERMISSION_DENIED:
			printf("hls: cannot open directory %s: Permission denied\n", name);
			break;
		case HLS_INVALID_OPTION:
			printf("hls: invalid option -- '%c'\n", name[0]);
			printf("Try 'hls --help' for more information.\n");
			break;
		}
}
