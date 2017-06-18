#include "hls.h"

/**
 * validate_options - validates the options given by the user and
 * fill the options
 * @argv: user inputs
 * @options: options to be validated.
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_INVALID_OPTION.
 */
int validate_options(char **argv, char *options)
{
	int i, j;
	char valid_options[1] = {'1'};
	int exit_value = HLS_SUCCESS;

	options[0] = '\0';
	for (i = 0 ; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '-' && strstr(options, argv[i]) == NULL)
			strcat(options, argv[i] + 1);
	}
	for (i = 0; i < strlen(options) && exit_value == HLS_SUCCESS; i++)
	{
		if (strchr(valid_options, options[i]) == NULL)
			exit_value = HLS_INVALID_OPTION;

	}
	if (exit_value != HLS_SUCCESS)
		print_error(exit_value, options + i - 1);
	return (exit_value);
}
