#include "malloc.h"

void *global_base = NULL;

/**
* find_block - A function that looks for a free block in the heap
* @last: pointer to the last block of the heap
* @size: No of bytes requested.
* Return: pointer to the avilable free block.
*/
t_block find_block(t_block *last, size_t size)
{
	t_block current = global_base;

	while (current && !(current->free && current->size >= size))
	{
		*last = current;
		current = current->next;
	}
	return (current);
}

/**
* extend_heap - A function that extends the heap
* @last: pointer to the last block of the heap
* @s: No of bytes requested.
* Return: current block to be used.
*/
t_block extend_heap(t_block last, size_t s)
{
	t_block current;

	current = sbrk(0);
	if (sbrk(BLOCK_SIZE + s) == (void *)-1)
	{
		perror("sbrk failed");
		return (NULL);
	}
	current->size = s;
	current->next = NULL;
	if (last)
		last->next = current;
	current->free = 0;
	return (current);
}

/**
* split_block - A function that splits the block based on the requested size.
* @current: current block to be allocated
* @s: No of bytes requested.
*/
void split_block(t_block current, size_t s)
{
	t_block new;

	new = (t_block) (current->data + s);
	new->size = current->size - s - BLOCK_SIZE;
	new->next = current->next;
	new->free = 1;
	current->size = s;
	current->next = new;
}

/**
* _malloc - A function which allocates size bytes and returns a pointer to the
* allocated memory.
* @size: No of bytes to be allocated
* Return: On success - A pointer to the allocated memory that is suitably
* aligned for any kind of variable
* On failure - NULL
*/
void *_malloc(size_t size)
{
	t_block current, last;
	size_t s;

	s = align8(size);
	if (global_base)
	{
		/* First find a block */
		last = global_base;
		current = find_block(&last, s);
		if (current)
		{
			/* can we split */
			if ((current->size - s) >= (BLOCK_SIZE + 8))
				split_block(current, s);
			current->free = 0;
		} else
		{
			/* No fitting block , extend the heap */
			current = extend_heap(last, s);
			if (!current)
				return (NULL);
		}
	} else
	{
		/* first time */
		current = extend_heap(NULL, s);
		if (!current)
			return (NULL);
		global_base = current;
	}
	return (current->data);
}
