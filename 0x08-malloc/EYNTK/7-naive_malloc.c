#include <unistd.h>

#define PAGE_SIZE ((size_t) sysconf(_SC_PAGESIZE))
#define align8(x) (((((x) - 1) >> 2) << 2 )+ 8)

static void *heap_start;

/**
* naive_malloc -  malloc which keep track of the address of the first
* chunk in chain and also allocate more space when a page is full
* @size: No of bytes to be allocated
* Return: A pointer to the allocated memory that is aligned for any type
*/
void *naive_malloc(size_t size)
{
	void *previous_break = NULL;
	size_t header_size = sizeof(size_t), unused_chunk, used_chunk, chunk;

	if (size <= 0)
		return (NULL);
	size = align8(size);
	chunk = header_size + size;
	if (heap_start == NULL)
	{
		heap_start = sbrk(0);
		unused_chunk = PAGE_SIZE;
		previous_break = sbrk(unused_chunk);
		if (previous_break == (void *)-1)
			return (NULL);
		*((size_t *) previous_break) = chunk;	/*set used bytes */
		*((size_t *) ((char *)previous_break + chunk)) = unused_chunk - chunk;	/* setting unused chunk */
		return ((void *)((char *)previous_break + header_size));
	}
	previous_break = heap_start;
	do
	{
		used_chunk = *((size_t *) previous_break);
		previous_break = (void *)((char *)previous_break + used_chunk);
		unused_chunk = *((size_t *) previous_break);
	}
	while (unused_chunk <= chunk);
	*((size_t *) previous_break) = chunk;
	previous_break = (void *)((char *)previous_break + header_size);
	if (unused_chunk <= chunk)
	{
		if (sbrk(PAGE_SIZE) == (void *)-1)
			return (NULL);
		*((size_t *) ((char *)previous_break + size)) =
		    unused_chunk + PAGE_SIZE - chunk;
	} else
		*((size_t *) ((char *)previous_break + size)) =
		    unused_chunk - chunk;
	return (previous_break);
}
