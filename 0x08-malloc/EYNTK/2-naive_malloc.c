#include <unistd.h>

/**
* naive_malloc -  malloc with no extra byte is allocated and everything is
* contiguous and packed in memory
* @size: No of bytes to be allocated
* Return: A pointer to the allocated memory
*/
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
