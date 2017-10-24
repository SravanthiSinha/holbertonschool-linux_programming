#include <unistd.h>

void *naive_malloc(size_t size)
{
	void *previous_break;

	previous_break = sbrk(size);
	/* check for error */
	if (previous_break == (void *)-1)
	{
		/* on error malloc returns NULL */
		return (NULL);
	}
	return (previous_break);
}
