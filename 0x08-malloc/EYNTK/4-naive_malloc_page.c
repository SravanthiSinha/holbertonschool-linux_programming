#include <unistd.h>
#include <stdio.h>

static void *heap_start;
static size_t no_chunks = 0;

/**
* naive_malloc_page -  malloc which keep track of the address of the first
* chunk in chain and number of chunks used
* @size: No of bytes to be allocated
* Return: A pointer to the allocated memory
*/
void *naive_malloc_page(size_t size)
{
	void *previous_break = NULL;
	size_t header_size = sizeof(size_t), unused_chunk, used_chunk;
	size_t i = 0;

	if (no_chunks == 0)
	{
		/*The first time our malloc is called, we need to extend the program break by the virtual memory page size. */
		heap_start = sbrk(0);
		unused_chunk = (size_t) sysconf(_SC_PAGESIZE);
		previous_break = sbrk(unused_chunk);
		if (previous_break == (void *)-1)
			return (NULL);
		/*set used bytes */
		*((size_t *) previous_break) = header_size + size;
		/* setting unused chunk */
		*((size_t *) ((char *)previous_break + header_size + size)) =
		    unused_chunk - size - header_size;
		no_chunks++;
		return ((void *)((char *)previous_break + header_size));
	}
	previous_break = heap_start;
	for (i = 0; i < no_chunks; i++)
	{
		used_chunk = *((size_t *) previous_break);
		previous_break = (void *)((char *)previous_break + used_chunk);
		unused_chunk = *((size_t *) previous_break);
	}
	/*set used bytes */
	*((size_t *) previous_break) = header_size + size;
	previous_break = (void *)((char *)previous_break + header_size);
	/* setting unused chunk */
	*((size_t *) ((char *)previous_break + size)) =
	    unused_chunk - header_size - size;

	no_chunks++;
	return (previous_break);
}
