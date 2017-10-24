#include <unistd.h>

/**
* naive_malloc_header - malloc which allocates more space than asked
* in order to store a small header at the beginning of the allocated chunk.
* @size: No of bytes to be allocated
* Return: A pointer to the allocated memory
*/
void *naive_malloc_header(size_t size)
{
	void *previous_break;
	size_t header_size = sizeof(size_t);

	previous_break = sbrk(header_size);
	*((size_t *) previous_break) = header_size + size;
	previous_break = sbrk(size);
	/* check for error */
	if (previous_break == (void *)-1)
	{
		/* on error malloc returns NULL */
		return (NULL);
	}
	return (previous_break);
}
