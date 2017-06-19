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
	int r = _strcasecmp(node1->str, node2->str);

	if (r)
		return (reverse == 0 ? r : -r);
	r = _strcmp(node1->str, node2->str);
	return (reverse == 0 ? -r : r);
}

/**
  * node_cmp_size - compares the value of the 2 nodes by file size
  * @node1: node1
  * @node2: node2
  * @reverse: reverse enabled or disabled.
	*
  * Return: compared value of the 2 nodes by file size.
  * 0 if matches else > or < 0
  */
int node_cmp_size(List *node1, List *node2, int reverse)
{
	long a = file_size(node1->str);
	long b = file_size(node2->str);

	if (a == b)
		return (node_cmp(node1, node2, reverse));
	return (reverse == 0 ? (a > b ? -1 : 1) : (a < b ? -1 : 1));
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
