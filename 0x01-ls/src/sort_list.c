#include "hls.h"

/**
 * node_cmp - compares the value of the 2 nodes alphabetically
 * @node1: node1
 * @node2: node2
 * @reverse: reverse enabled or disabled.
 *
 * Return: compared value of the 2 nodes alphabetically.
 * 0 if matches else > or < 0
 */
int node_cmp(List *node1, List *node2, int reverse)
{
	int r = strcasecmp(node1->str, node2->str);

	if (r)
		return (reverse == 0 ? r : -r);
	r = strcmp(node1->str, node2->str);
	return (reverse == 0 ? -r : r);
}


/**
 * swap_list - swaps the value of the 2 nodes
 * @node1: node1
 * @node2: node2
 *
 * Return: void
 */
void swap_list(List *node1, List *node2)
{
	char *temp = node1->str;

	node1->str = node2->str;
	node2->str = temp;
}


/**
 * sort_list - sorts the list based on the cmp functions
 * @a: list to be sorted
 * @cmp: cmp function to be applied for sorting
 * @reverse: reverse enabled or disabled.
 *
 * Return: void
 */
void sort_list(List **a, int (*cmp)(List *a, List *b, int r), int reverse)
{
	List *traverse = *a;
	List *yes;

	if (*a == NULL)
		return;
	for (; traverse != NULL; traverse = traverse->next)
	{
		for (yes = *a; yes->next != NULL; yes = yes->next)
		{
			if ((*cmp)(yes, yes->next, reverse) > 0)
				swap_list(yes, yes->next);
		}
	}
}
