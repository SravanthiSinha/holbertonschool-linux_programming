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
	Direntry *direntry = NULL;
	List *dirnames = NULL;
	char *names[2] = {"./", NULL};
	char options[MAX_OPTION_SIZE];
	int error_occured = 0;
	Options *options_s = NULL;

	/* default: current directory */
	if (argc == 1 || (argc == 2 && strcmp(argv[1], ".") == 0))
		dirnames = array_to_list(names);
	else if (argc > 1)
	{
		exit_value = validate_options(argv + 1, options);
		/* default: current directory */
		if (exit_value == HLS_SUCCESS && argc == 2 && strlen(options) > 0)
			dirnames = array_to_list(names);
		else if (exit_value == HLS_SUCCESS)
			dirnames = array_to_list(argv + 1);
		sort_list(&dirnames, &node_cmp);
	}
	if (list_size(dirnames))
	{

		exit_value = scan_files(&dirnames, &direntry);
		if (exit_value != HLS_SUCCESS)
			error_occured = 1;
		options_s = inititate_options(options);
		print_file_list(options_s, &dirnames, &direntry, error_occured);
		free_options(options_s);
		free_direntry(direntry);
		free_list(dirnames);
	}
	return (exit_value != HLS_SUCCESS || error_occured ? HLS_MAJOR_ERROR
		: HLS_SUCCESS);
}
