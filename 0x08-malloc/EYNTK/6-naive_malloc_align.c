#include <unistd.h>
#include <stdio.h>

static void *heap_start;
static size_t no_chunks = 0;

/**
* get_next_multiple - returns a number rounded up to the next multiple of 8
* @size: No of bytes to be allocated
* Return: A pointer to the aligned address
*/
size_t get_next_multiple(size_t size)
{
	int n = size;

	/*We allocate extra space when the size is not a multiple of 8 */
	if (n % 8)
		n = n + (8 - n % 8);
	return (n);
}

/**
* naive_malloc_align -  malloc which keep track of the address of the first
* chunk in chain and number of chunks useda and allocate more space when a
* page is full
* @size: No of bytes to be allocated
* Return: A pointer to the allocated memory that is aligned for any type
*/
void *naive_malloc_align(size_t size)
{
	void *previous_break = NULL;
	size_t header_size = sizeof(size_t), unused_chunk, used_chunk;
	size_t i = 0;

	size = get_next_multiple(size);
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
		    unused_chunk - header_size - size;
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
	if (unused_chunk <= (header_size + size))
	{
		sbrk((size_t) sysconf(_SC_PAGESIZE));
		*((size_t *) ((char *)previous_break + size)) =
		    unused_chunk + (size_t) sysconf(_SC_PAGESIZE) -
		    header_size - size;
	} else
		*((size_t *) ((char *)previous_break + size)) =
		    unused_chunk - header_size - size;
	no_chunks++;
	return (previous_break);
}
