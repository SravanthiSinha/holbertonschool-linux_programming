#include "hls.h"

/**
 * delete_nodeint_at_index - Deletes the node at index specified
 * @head: The List where the value are to be deleted.
 * @index: The position of the node to be deleted.
 *
 * Return: on success: 1, on Failure: 0 - list empty, -1 if position not found
 */
int delete_nodeint_at_index(List **head, unsigned int index)
{
	List *curr = NULL;
	List *temp = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (0);
	curr = *head;
	if (index == 1)
	{
		*head = (*head)->next;
		free(curr->str);
		free(curr);
		return (1);
	}
	else
	{
		while ((curr != NULL) && (i < index))
		{
			i++;
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL)
			return (-1);
		temp->next = curr->next;
		free(temp->str);
		free(temp);
	}
	return (1);
}


/**
 * deleteParam - Deletes the node with a specified value
 * @head_ref: The List where the value are to be deleted.
 * @key: The value of the node to be deleted.
 *
 * Return: void
 */
void deleteParam(List **head_ref, char *key)
{
	List *temp = *head_ref, *prev = NULL;

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
 * get_node - get the value of the node at index specified
 * @head: The List where the value are to be deleted.
 * @index: The position of the node to be deleted.
 *
 * Return: on success: Value of the node, on Failure: NULL
 */
char *get_node(List *head, int index)
{
	List *current = head;
	int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current->str);
		count++;
		current = current->next;
	}
	return (NULL);
}
