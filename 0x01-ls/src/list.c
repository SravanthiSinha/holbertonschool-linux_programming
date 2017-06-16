#include "hls.h"

/**
 * list_size - Prints the List.
 * @list: The List whose size has to be measured.
 *
 * Return: size of the list of List.
 */
int list_size(List *list)
{
	List *node = NULL;
	int size;

	size = 0;
	node = list;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}

	return (size);
}

/**
 * list_add - Adds the value to the direntry of Direntry
 * @list: The List where the values are added.
 * @content: The value to be added.
 *
 * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2.
 */
int list_add(List **list, char *content)
{
	List *head;
	List *node;

	head = *list;
	node = malloc(sizeof(List));
	if (node == NULL)
		return (1);
	node->str = strdup(content);
	node->next = head;
	*list = node;
	return (0);

}

/**
 * array_to_list - Converts an string array to a linked list
 * @a: string array.
 *
 * Return: A linked list with values from array string.
 */
List *array_to_list(char **a)
{

	List *list;
	int i;

	list = NULL;
	for (i = 0; a[i]; i++)
		list_add(&list, a[i]);
	return (list);
}

/**
 * free_list - Frees the List
 * @head: The List to be freed
 *
 * Return: void
 */
void free_list(List *head)
{
	List *node = NULL;
	List *temp = NULL;

	node = head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		free(temp);
	}
}


/**
 * print_list - Prints the List
 * @list: The List to be printed
 *
 * Return: void
 */
void print_list(List *list)
{
	List *node = NULL;

	node = list;
	while (node != NULL)
	{
		printf("%s\n", node->str);
		node = node->next;
	}
}
