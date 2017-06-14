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
	HashTable *hashtable = NULL;
	FileList *list = NULL;

	hashtable = ht_create(INITIAL_TABLE_SIZE);
	if (hashtable != NULL)
	{
		/* no params or current directory*/
		if (argc == 1)
			exit_value = execute(".", hashtable, &list);
		else
		{
			for (i = 1; i < argc && exit_value == HLS_SUCCESS; i++)
				if (argv[i][0] != '-')
					exit_value = execute(argv[i], hashtable, &list);
		}
		if (exit_value == HLS_SUCCESS)
			print_file_list(hashtable, list);
	}
	else
		exit_value = HLS_MAJOR_ERROR;
	free_list(list);
	ht_free(hashtable);
	return (exit_value);
}
