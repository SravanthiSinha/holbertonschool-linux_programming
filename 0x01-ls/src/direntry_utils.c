#include "hls.h"

/**
 * get_direntres - gets the list of the Direntres with specified value
 * @str: The value of the Direntry to be searched.
 * @en: The Direntry where the value are to be looked in.
 *
 * Return: on success: List of of the Direntres, on Failure: NULL
 */
Direntry *get_direntres(char *str, Direntry *en)
{
	Direntry *result = NULL, *temp = NULL;
	int index = 0;

	while (en != NULL)
	{
		if (strncmp(en->str, str, strlen(str)) == 0)
		{
			if (strchr(str, '/') == NULL)
				index = strlen(str);
			else
				index = strlen(str) + 1;
			if (strchr(en->str + index, '/') == NULL)
			{
				if (temp == NULL)
				{
					result = malloc(sizeof(Direntry));
					temp = result;
				}
				else
				{
					temp->next = malloc(sizeof(Direntry));
					temp = temp->next;
				}
				temp->str = strdup(en->str);
				temp->next = NULL;
			}
		}
		en = en->next;
	}
	return (result);
}

/**
 * get_biggest_size - gets the size of the biggest file in the list.
 * @en: The Direntry where the size of each drientry are to be looked in.
 *
 * Return: size of the biggest file
 */
long get_biggest_size(Direntry *en)
{
	long size = 0;
	long tsize = 0;

	if (en != NULL)
		size = file_size(en->str);
	while (en != NULL)
	{
		tsize = file_size(en->str);
		if (tsize > size)
			size = tsize;
		en = en->next;
	}
	return (size);
}

/**
 * get_files - gets the list of the Direntres which are files in dirnames
 * @en: The Direntry where the value are to be looked in.
 *
 * Return: on success: List of of the Direntres, on Failure: NULL
 */
Direntry *get_files(Direntry *en)
{
	Direntry *result = NULL, *temp = NULL;

	while (en != NULL)
	{
		if (strchr(en->str, '/') == NULL)
		{
			if (temp == NULL)
			{
				result = malloc(sizeof(Direntry));
				temp = result;
			}
			else
			{
				temp->next = malloc(sizeof(Direntry));
				temp = temp->next;
			}
			temp->str = strdup(en->str);
			temp->next = NULL;
		}
		en = en->next;
	}
	return (result);
}
/**
 * deleteDirent - Deletes the Direntry with a specified value
 * @head_ref: The List where the value are to be deleted.
 * @key: The value of the node to be deleted.
 *
 * Return: void
 */
void deleteDirent(Direntry **head_ref, char *key)
{
	Direntry *temp = *head_ref, *prev;

	if (temp != NULL && strcmp(temp->str, key) == 0)
		{
		*head_ref = temp->next;
		free(temp->str);
		free(temp);
		return;
	}
	while (temp != NULL && strcmp(temp->str, key) != 0)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;
	prev->next = temp->next;
	free(temp->str);
	free(temp);
}

/**
 * removeDuplicates - removes duplicate the Direntry with a specified value
 * @head: The List where the value are to be deleted.
 *
 * Return: void
 */
void removeDuplicates(Direntry *head)
{
	Direntry *temp;

	while (head != NULL)
	{
		if (head->next != NULL)
		{
			while (head->next != NULL && strcmp(head->next->str, head->str) == 0)
			{
				temp = head->next;
				head->next = temp->next;
				free(temp->str);
				free(temp);
			}
		}
		head = head->next;
	}
}
