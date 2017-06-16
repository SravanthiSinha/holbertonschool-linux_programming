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
	switch (error_code)
		{
		case HS_INVALID_FILE_DIR:
			printf("hls: cannot access %s: No such file or directory\n", name);
			break;
		case HS_INVALID_OPTION:
			printf("Try 'hls --help' for more information.");
			break;
		}
}
