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
	char valid_options[4] = {'1', 'a', 'A', 'r'};
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

/**
 * inititate_options - INitialtes the options given by the user and
 * fill the options structure
 * @options: user options inputs
 *
 * Return: Options structure
 */
Options *inititate_options(char *options)
{
	Options *options_s = malloc(sizeof(Options));

	if (options_s != NULL)
	{
		if (options && strchr(options, '1') != NULL)
			options_s->delimeter = strdup("\n");
		else
			options_s->delimeter = strdup("  ");
		if (options && strchr(options, 'a') != NULL)
			options_s->all = 1;
		else
			options_s->all = 0;
		if (options && strchr(options, 'A') != NULL && strchr(options, 'a') == NULL)
			options_s->almost_all = 1;
		else
			options_s->almost_all = 0;
		if (options && strchr(options, 'r') != NULL)
			options_s->reverse = 1;
		else
			options_s->reverse = 0;
	}
	return (options_s);
}


/**
 * free_options - frees the options structure
 * @options: user options inputs structure
 *
 * Return: void
 */
void free_options(Options *options)
{
	if (options != NULL)
	{
		free(options->delimeter);
		free(options);
	}
}
