#include "hls.h"

/**
 * validate_options - validates the op given by the user and
 * fill the op
 * @argv: user inputs
 * @op: op to be validated.
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_INVALID_OPTION.
 */
int validate_options(char **argv, char *op)
{
	unsigned int i;
	char valid_options[6] = {'1', 'a', 'A', 'r', 'l', 'S'};
	int exit_value = HLS_SUCCESS;

	op[0] = '\0';
	for (i = 0 ; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '-' && _strstr(op, argv[i]) == NULL)
			_strcat(op, argv[i] + 1);
	}
	for (i = 0; i < _strlen(op) && exit_value == HLS_SUCCESS; i++)
	{
		if (_strchr(valid_options, op[i]) == NULL)
			exit_value = HLS_INVALID_OPTION;
	}
	if (exit_value != HLS_SUCCESS)
		print_error(exit_value, op + i - 1);
	return (exit_value);
}

/**
 * inititate_options - INitialtes the op given by the user and
 * fill the op structure
 * @op: user op inputs
 *
 * Return: Options structure
 */
Options *inititate_options(char *op)
{
	Options *options_s = malloc(sizeof(Options));

	if (options_s != NULL)
	{
		if (op && (_strchr(op, '1') != NULL || _strchr(op, 'l') != NULL))
			options_s->delimeter = _strdup("\n");
		else
			options_s->delimeter = _strdup("  ");
		if (op && _strchr(op, 'a') != NULL)
			options_s->all = 1;
		else
			options_s->all = 0;
		if (op && _strchr(op, 'A') != NULL && _strchr(op, 'a') == NULL)
			options_s->almost_all = 1;
		else
			options_s->almost_all = 0;
		if (op && _strchr(op, 'r') != NULL)
			options_s->reverse = 1;
		else
			options_s->reverse = 0;
		if (op && _strchr(op, 'l') != NULL)
			options_s->long_format = 1;
		else
			options_s->long_format = 0;
		if (op && _strchr(op, 'S') != NULL)
			options_s->sort_size = 1;
		else
			options_s->sort_size = 0;
	}
	return (options_s);
}


/**
 * free_options - frees the op structure
 * @op: user op inputs structure
 *
 * Return: void
 */
void free_options(Options *op)
{
	if (op != NULL)
	{
		free(op->delimeter);
		free(op);
	}
}
