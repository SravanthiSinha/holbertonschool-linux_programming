#include "hls.h"

/**
  * ltrim - ltrims the string(removes leading .)
  * @src: node1
	*
  * Return: ltrimmed string
  */
char *ltrim(char *src)
{
	char *original = src;
	char *p = original;
	int trimmed = 0;

	do {
		if (*original != '.' || trimmed)
		{
			trimmed = 1;
			*p++ = *original;
		}
	}	while (*original++ != '\0');
	return (src);
}

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
	char *a;
	char *b;
	int r = 0;

	a = _strdup(basename(node1->str));
	b = _strdup(basename(node2->str));
	if (_strcmp(a, ".") != 0 && _strcmp(a, "..") != 0)
		a = ltrim(a);
	if (_strcmp(b, ".") != 0 && _strcmp(b, "..") != 0)
		b = ltrim(b);
	r = _strcasecmp(a, b);
	if (r)
	{
		free(a);
		free(b);
		return (reverse == 0 ? r : -r);
	}
	r = _strcmp(a, b);
	free(a);
	free(b);
	return (reverse == 0 ? -r : r);
}

/**
  * dirent_cmp_size - compares the value of the 2 nodes by file size
  * @node1: node1
  * @node2: node2
  * @reverse: reverse enabled or disabled.
	*
  * Return: compared value of the 2 nodes by file size.
  * 0 if matches else > or < 0
  */
int dirent_cmp_size(Direntry *node1, Direntry *node2, int reverse)
{
	long a = file_size(node1->str);
	long b = file_size(node2->str);

	if (a == b)
		return (dirent_cmp(node1, node2, reverse));
	return (reverse == 0 ? (a > b ? -1 : 1) : (a < b ? -1 : 1));
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
	char *temp;
	int tdir;
	long tsize;

	tdir = a->is_dir;
	a->is_dir = b->is_dir;
	b->is_dir = tdir;

	tsize = a->size;
	a->size = b->size;
	b->size = tsize;

	temp = a->str;
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
