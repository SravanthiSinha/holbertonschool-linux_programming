#include "hls.h"


/**
 * direntry_add - Adds the value to the direntry of Direntry
 * @direntry: The Direntry where the values are added.
 * @content: The value to be added.
 * @is_dir: if a file path is a directory = 1 else 0
 * @size : file_size
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2.
 */
int direntry_add(Direntry **direntry, char *content, int is_dir, long size)
{
	Direntry *head = NULL;
	Direntry *node = NULL;

	head = *direntry;
	if (head == NULL)
	{
		head = malloc(sizeof(Direntry));
		if (head == NULL)
			return (1);
		head->str = strdup(content);
		head->is_dir = is_dir;
		head->size = size;
		head->next = NULL;
		*direntry = head;
		return (HLS_SUCCESS);
	}
	else
	{
		node = malloc(sizeof(Direntry));
		if (node == NULL)
			return (1);
		node->str = strdup(content);
		head->is_dir = is_dir;
		head->size = size;
		node->next = *direntry;
		*direntry = node;
		return (HLS_SUCCESS);
	}
	return (HLS_MAJOR_ERROR);
}

/**
 * direntry_size - Prints the Direntry.
 * @direntry: The Direntry whose size has to be measured.
 *
 * Return: size of the direntry of Direntry.
 */
int direntry_size(Direntry *direntry)
{
	Direntry *node = NULL;
	int size;

	size = 0;
	node = direntry;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}

	return (size);
}

/**
 * print_direntry - Prints the Direntry
 * @direntry: The Direntry to be printed
 *
 * Return: void
 */
void print_direntry(Direntry *direntry)
{
	Direntry *node = NULL;

	node = direntry;
	while (node != NULL)
	{
		printf("%s\n", node->str);
		node = node->next;
	}
}

/**
 * free_direntry - Frees the Direntry
 * @head: The Direntry to be freed
 *
 * Return: void
 */
void free_direntry(Direntry *head)
{
	Direntry *node = NULL;
	Direntry *temp = NULL;

	node = head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		free(temp);
	}
}
