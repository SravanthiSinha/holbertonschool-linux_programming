#include "hls.h"

/**
  * dirent_cmp - compares the value of the 2 nodes alphabetically
  * @node1: node1
  * @node2: node2
  * @reverse: reverse enabled or disabled.
	*
  * Return: compared value of the 2 nodes alphabetically.
  * 0 if matches else > or < 0
  */
int dirent_cmp(Direntry *node1, Direntry *node2, int reverse)
{
	int r = strcasecmp(node1->str, node2->str);

	if (r)
		return (reverse == 0 ? r : -r);
	r = strcmp(node1->str, node2->str);
	return (reverse == 0 ? -r : -r);
}


/**
 * swap - swaps the value of the 2 Direntres
 * @a: Direntry 1
 * @b: Direntry 2
 *
 * Return: void
 */
void swap(Direntry *a, Direntry *b)
{
	char *temp = a->str;

	a->str = b->str;
	b->str = temp;
}


/**
 * sort_direntres - sorts the direntry based on the cmp functions
 * @a: direntry to be sorted
 * @c: cmp function to be applied for sorting
 * @r: reverse enabled or disabled.
 *
 * Return: void
 */
void sort_direntres(Direntry **a, int (*c)(Direntry *, Direntry *, int), int r)
{
	Direntry *traverse = *a;
	Direntry *yes;

	if (*a == NULL)
		return;
	for (; traverse != NULL; traverse = traverse->next)
	{
		for (yes = *a; yes->next != NULL; yes = yes->next)
		{
			if ((*c)(yes, yes->next, r) > 0)
				swap(yes, yes->next);
		}
	}
}
