#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *ptr;

	printf("Starting break is %p\n", sbrk(0));
	ptr = sbrk(1);
	if (ptr == (void *)-1)
	{
		return (1);
	}
	printf("Break after extension is %p\n", sbrk(0));
	*ptr = 'H';
	printf("Address of our char is %p\n", ptr);
	printf("Value at this address is '%c'\n", *ptr);
	return (0);
}
