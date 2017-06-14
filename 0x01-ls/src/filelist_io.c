#include "hls.h"

/**
  * compare - compares the value of the 2 nodes alphabetically
  * @node1: node1
  * @node2: node2
  *
  * Return: compared value of the 2 nodes alphabetically.
  * 0 if matches else > or < 0
  */
int compare(struct FileList *node1, struct FileList *node2)
{
	int r = strcasecmp(node1->str, node2->str);

	if (r)
		return (r);
	return (-strcmp(node1->str, node2->str));
}

/**
  * add - Adds the value to the list of FileList in a sorted manner.
  * @list: The FileList where the values are added.
  * @value: The value to be added.
  * @cmp : The comparision function to be used while sorting.
  *
  * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2.
  */
int add(FileList **list, char *value, int (*cmp)(FileList *l, FileList *r))
{
	struct FileList *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (HLS_MAJOR_ERROR);
	new->str = strdup(value);
	for (; *list != NULL; list = &(*list)->next)
	{
		if (cmp(*list, new) > 0)
			break;
	}
	new->next = *list;
	*list = new;
	return (HLS_SUCCESS);
}

/**
  * list_size - Prints the FileList.
  * @list: The FileList whose size has to be measured.
  *
  * Return: size of the list of FileList.
  */
int list_size(FileList *list)
{
	FileList *node = NULL;
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
  * print_list - Prints the FileList
  * @list: The FileList to be printed
  *
  * Return: void
  */
void print_list(FileList *list)
{
	FileList *node = NULL;

	node = list;
	while (node != NULL)
	{
		printf("%s\n", node->str);
		node = node->next;
	}
}

/**
  * free_list - Frees the FileList
  * @head: The FileList to be freed
  *
  * Return: void
  */
void free_list(FileList *head)
{
	FileList *node = NULL;
	FileList *temp = NULL;

	node = head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		free(temp);
	}
}
