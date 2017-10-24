#include <unistd.h>

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
