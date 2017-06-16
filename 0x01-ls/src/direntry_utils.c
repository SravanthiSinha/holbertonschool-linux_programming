#include "hls.h"

/**
 * get_node - gets the list of the Direntres with specified value
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
