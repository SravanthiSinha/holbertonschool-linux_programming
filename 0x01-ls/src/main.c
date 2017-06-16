#include "hls.h"

/**
 * main - A program that takes the name of a directory as a parameter and
 * prints its content.
 * @argc: no of inputs.
 * @argv: inputs.
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2.
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	int exit_value = HLS_SUCCESS;
	int i;
	Direntry *direntry = NULL;
	List *dirnames = NULL;
	char *names[2] = {"./", NULL};
	int error_occured = 0;

	/* default: current directory */
	if (argc == 1 || (argc == 2 && strcmp(argv[1], ".") == 0))
		dirnames = array_to_list(names);
	else if (argc > 1)
	{
		if (argv[1][0] == '-')
			dirnames = array_to_list(argv + 2);
		else
			dirnames = array_to_list(argv + 1);
		sort_list(&dirnames, &node_cmp);
	}
	if (list_size(dirnames))
	{
		exit_value = scan_files(&dirnames, &direntry);
		if (exit_value != HLS_SUCCESS)
			error_occured = 1;
		print_file_list(&dirnames, &direntry, error_occured);
		free_direntry(direntry);
		free_list(dirnames);
	}
	return (exit_value != HLS_SUCCESS || error_occured ? HLS_MAJOR_ERROR
		: HLS_SUCCESS);
}
